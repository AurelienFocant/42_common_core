/*
** Ford-Johnson Algorithm (Merge-Insertion Sort)
**
** This algorithm minimizes the number of comparisons needed to sort n elements.
** It achieves this by:
**   1. Pairing elements and sorting each pair (1 comparison per pair)
**   2. Recursively sorting the larger elements of each pair
**   3. Inserting the smaller elements using binary search in an order
**      determined by Jacobsthal numbers, which minimizes worst-case comparisons
**
** Jacobsthal sequence: 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, ...
** J(n) = J(n-1) + 2 * J(n-2)
** The insertion order derived from Jacobsthal numbers ensures each insertion
** reduces the upper bound of binary search by exactly half.
*/

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

/* ------------------------------------------------------------------ */
/*  Jacobsthal number generator                                        */
/* ------------------------------------------------------------------ */

/*
** Returns the nth Jacobsthal number.
** J(0) = 0, J(1) = 1, J(n) = J(n-1) + 2 * J(n-2)
*/
static size_t jacobsthal(size_t n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    size_t prev2 = 0;
    size_t prev1 = 1;
    size_t current = 0;

    for (size_t i = 2; i <= n; ++i)
    {
        current = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

/*
** Builds the insertion order sequence based on Jacobsthal numbers.
**
** Given 'pending' elements indexed 1..n, we insert them in the order
** determined by Jacobsthal groups:
**   Group k covers indices from J(k-1)+1 to J(k), inserted in reverse.
**
** Example for 5 pending elements: 2, 1, 4, 3, 5
*/
static std::vector<size_t> buildInsertionOrder(size_t pendingSize)
{
    std::vector<size_t> order;
    std::vector<bool>   inserted(pendingSize + 1, false);

    size_t k = 1;
    while (order.size() < pendingSize)
    {
        size_t jk     = jacobsthal(k + 1);   // upper bound of current group
        size_t jkPrev = jacobsthal(k);        // upper bound of previous group

        if (jk > pendingSize)
            jk = pendingSize;

        // Insert from jk down to jkPrev + 1 (reverse order within group)
        for (size_t i = jk; i > jkPrev && i >= 1; --i)
        {
            if (!inserted[i])
            {
                order.push_back(i);
                inserted[i] = true;
            }
        }
        ++k;

        // Safety: avoid infinite loop if all pending inserted
        if (k > pendingSize + 2)
            break;
    }

    // Catch any remaining elements (shouldn't happen with correct Jacobsthal)
    for (size_t i = 1; i <= pendingSize; ++i)
        if (!inserted[i])
            order.push_back(i);

    return order;
}

/* ------------------------------------------------------------------ */
/*  Binary search insertion                                            */
/* ------------------------------------------------------------------ */

/*
** Inserts 'value' into the sorted range [begin, end) using binary search.
** The search is bounded by 'upperBound' to maintain the comparison-optimal
** guarantee of Ford-Johnson.
**
** upperBound: the exclusive upper index within [begin, end) to search.
**             Pass chain.end() to search the whole sorted chain.
*/
template <typename T>
typename std::vector<T>::iterator
binarySearchInsert(std::vector<T> &chain,
                   typename std::vector<T>::iterator begin,
                   typename std::vector<T>::iterator end,
                   const T &value)
{
    typename std::vector<T>::iterator lo = begin;
    typename std::vector<T>::iterator hi = end;

    while (lo < hi)
    {
        typename std::vector<T>::iterator mid = lo + (hi - lo) / 2;
        if (*mid < value)
            lo = mid + 1;
        else
            hi = mid;
    }
    return chain.insert(lo, value);
}

/* ------------------------------------------------------------------ */
/*  Ford-Johnson sort (recursive)                                      */
/* ------------------------------------------------------------------ */

template <typename T>
std::vector<T> fordJohnsonSort(std::vector<T> seq)
{
    size_t n = seq.size();

    // Base cases
    if (n <= 1)
        return seq;

    if (n == 2)
    {
        if (seq[1] < seq[0])
            std::swap(seq[0], seq[1]);
        return seq;
    }

    /* ----------------------------------------------------------------
    ** Step 1: Form pairs and compare each pair so that the larger
    **         element is first (index 0 of pair = larger).
    ** If n is odd, the last element is a "straggler" with no pair.
    ** ---------------------------------------------------------------- */
    bool        hasStraggler = (n % 2 != 0);
    T           straggler = hasStraggler ? seq[n - 1] : T();
    size_t      pairCount = n / 2;

    // pairs[i] = (larger, smaller)
    std::vector<std::pair<T, T> > pairs(pairCount);
    for (size_t i = 0; i < pairCount; ++i)
    {
        T a = seq[2 * i];
        T b = seq[2 * i + 1];
        if (a < b)
            std::swap(a, b);
        pairs[i] = std::make_pair(a, b); // (larger, smaller)
    }

    /* ----------------------------------------------------------------
    ** Step 2: Recursively sort the sequence of larger elements.
    ** ---------------------------------------------------------------- */
    std::vector<T> largers;
    largers.reserve(pairCount);
    for (size_t i = 0; i < pairCount; ++i)
        largers.push_back(pairs[i].first);

    largers = fordJohnsonSort(largers);

    /* ----------------------------------------------------------------
    ** Step 3: Build the main chain from sorted largers.
    **         Reorder the smalls so that smalls[i] is the pair partner
    **         of largers[i] after recursive sort.
    ** ---------------------------------------------------------------- */

    // We need to know which small goes with which large after sorting.
    // Map: original large value -> its small partner
    // (assumes unique values; for duplicates a more robust map is needed)
    std::vector<T> smallers(pairCount);
    for (size_t i = 0; i < pairCount; ++i)
    {
        // Find the position of pairs[i].first in the sorted largers
        for (size_t j = 0; j < pairCount; ++j)
        {
            if (largers[j] == pairs[i].first)
            {
                smallers[j] = pairs[i].second;
                break;
            }
        }
    }

    // Main chain starts with sorted largers
    std::vector<T> chain(largers);

    /* ----------------------------------------------------------------
    ** Step 4: Insert smallers (and straggler) using Jacobsthal order.
    **
    **   - smallers[0] is always <= largers[0] (by construction),
    **     so insert it at the front first (before chain[0]).
    **   - Then insert remaining smallers in Jacobsthal order,
    **     each with an upper bound = position of its paired large + 1.
    ** ---------------------------------------------------------------- */

    // Insert smallers[0] at the beginning (it's <= chain[0])
    chain.insert(chain.begin(), smallers[0]);

    // Build insertion order for smallers[1..pairCount-1]
    size_t pendingCount = pairCount - 1;

    if (pendingCount > 0)
    {
        std::vector<size_t> insertionOrder = buildInsertionOrder(pendingCount);

        for (size_t idx = 0; idx < insertionOrder.size(); ++idx)
        {
            // insertionOrder uses 1-based indexing into smallers[1..]
            size_t si = insertionOrder[idx]; // 1-based index into pending
            T      val = smallers[si];       // smallers[si] (si >= 1)

            // The paired large is largers[si], find its current position in chain
            // The upper bound for binary search is that position + 1
            // (we know val <= its paired large)
            typename std::vector<T>::iterator upperIt = chain.end();
            for (typename std::vector<T>::iterator it = chain.begin();
                 it != chain.end(); ++it)
            {
                if (*it == largers[si])
                {
                    upperIt = it + 1; // search only up to (and including) paired large
                    break;
                }
            }

            binarySearchInsert(chain, chain.begin(), upperIt, val);
        }
    }

    // Insert straggler (if any) anywhere in the sorted chain
    if (hasStraggler)
        binarySearchInsert(chain, chain.begin(), chain.end(), straggler);

    return chain;
}

/* ------------------------------------------------------------------ */
/*  PmergeMe class (42 CPP09 style, works with vector and deque)       */
/* ------------------------------------------------------------------ */

class PmergeMe
{
public:

    // Sort using std::vector
    static std::vector<int> sortVector(const std::vector<int> &input)
    {
        return fordJohnsonSort(input);
    }

    // Sort using std::deque (convert internally)
    static std::deque<int> sortDeque(const std::deque<int> &input)
    {
        std::vector<int> v(input.begin(), input.end());
        v = fordJohnsonSort(v);
        return std::deque<int>(v.begin(), v.end());
    }
};

/* ------------------------------------------------------------------ */
/*  Utility: print container                                           */
/* ------------------------------------------------------------------ */

template <typename Container>
void printContainer(const std::string &label, const Container &c)
{
    std::cout << label;
    for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " num1 num2 num3 ..." << std::endl;
        return 1;
    }

    std::vector<int> input;

    for (int i = 1; i < argc; ++i)
    {
        std::istringstream iss(argv[i]);
        int val;
        if (!(iss >> val) || val < 0)
        {
            std::cerr << "Error: invalid argument '" << argv[i] << "'" << std::endl;
            return 1;
        }
        input.push_back(val);
    }

    // --- Vector ---
    printContainer("Before (vector): ", input);

    std::vector<int> sortedVec = PmergeMe::sortVector(input);
    printContainer("After  (vector): ", sortedVec);

    // --- Deque ---
    std::deque<int> inputDeque(input.begin(), input.end());
    std::deque<int> sortedDeq = PmergeMe::sortDeque(inputDeque);
    printContainer("After  (deque) : ", sortedDeq);

    return 0;
}
