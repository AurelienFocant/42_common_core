#include <vector>
#include <deque>
#include <list>
#include <map>
#include <algorithm>
#include <utility>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>

// ---------------------------------------------------------------------------
// Jacobsthal sequence generator
// ---------------------------------------------------------------------------
static std::vector<size_t> jacobsthalSequence(size_t n)
{
    std::vector<size_t> seq;
    if (n == 0) return seq;

    std::vector<size_t> jNums;
    jNums.push_back(1);
    size_t j0 = 0, j1 = 1;
    while (true)
    {
        size_t next = j1 + 2 * j0;
        if (next > n) break;
        jNums.push_back(next);
        j0 = j1;
        j1 = next;
    }

    std::vector<bool> added(n + 1, false);
    for (size_t i = 0; i < jNums.size(); ++i)
    {
        size_t curr = jNums[i];
        size_t prev = (i == 0) ? 0 : jNums[i - 1];
        for (size_t k = curr; k > prev; --k)
        {
            if (k <= n && !added[k])
            {
                seq.push_back(k);
                added[k] = true;
            }
        }
    }
    for (size_t i = 1; i <= n; ++i)
        if (!added[i]) seq.push_back(i);

    return seq;
}

// ---------------------------------------------------------------------------
// Generic Ford-Johnson (merge-insertion) sort.
//
// The main chain is kept as a Container throughout, so each container type
// pays its real insertion cost:
//   - std::vector  : O(n) shifts on insert, O(log n) binary search
//   - std::deque   : O(n) shifts on insert, O(log n) binary search
//   - std::list    : O(1) insert once position is found, but O(n) linear
//                    search (no random-access iterator, so lower_bound
//                    degrades from O(log n) to O(n))
//
// Recursion always uses std::vector internally (sorting the largers only),
// so the Container penalty is isolated to the insertion phase.
// ---------------------------------------------------------------------------
template <typename Container>
Container fjSort(const Container& input)
{
    typedef typename Container::value_type T;
    typedef typename Container::iterator   Iter;

    // Copy into a vector for indexed pairing — this is O(n) regardless and
    // is not part of the timed insertion phase.
    std::vector<T> seq(input.begin(), input.end());
    size_t n = seq.size();

    if (n <= 1)
        return input;

    if (n == 2)
    {
        std::vector<T> v(seq);
        if (v[1] < v[0]) std::swap(v[0], v[1]);
        return Container(v.begin(), v.end());
    }

    bool hasStraggler = (n % 2 != 0);
    T straggler = hasStraggler ? seq.back() : T();

    size_t pairCount = n / 2;

    // --- Step 1: form pairs (larger, smaller) ---
    std::vector<std::pair<T, T> > pairs;
    pairs.reserve(pairCount);
    for (size_t i = 0; i < pairCount; ++i)
    {
        T a = seq[2 * i];
        T b = seq[2 * i + 1];
        if (a < b) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    // --- Step 2: recursively sort the larger elements (always via vector) ---
    std::vector<T> largers;
    largers.reserve(pairCount);
    for (size_t i = 0; i < pairCount; ++i)
        largers.push_back(pairs[i].first);

    largers = fjSort<std::vector<T> >(largers);

    // --- Step 3: re-order pairs to match sorted largers ---
    std::multimap<T, std::pair<T, T> > mp;
    for (size_t i = 0; i < pairCount; ++i)
        mp.insert(std::make_pair(pairs[i].first, pairs[i]));

    std::vector<std::pair<T, T> > ordered;
    ordered.reserve(pairCount);
    for (size_t i = 0; i < pairCount; ++i)
    {
        typename std::multimap<T, std::pair<T, T> >::iterator it =
            mp.find(largers[i]);
        ordered.push_back(it->second);
        mp.erase(it);
    }

    // --- Step 4: build the initial chain as the REAL Container ---
    // This is where vector/deque vs list performance diverges.
    Container chain;
    chain.push_back(ordered[0].second);
    for (size_t i = 0; i < pairCount; ++i)
        chain.push_back(ordered[i].first);

    // --- Step 5: insert pending elements in Jacobsthal order ---
    // lower_bound on a list iterator is O(n); on vector/deque it is O(log n).
    // The insert itself is O(1) for list, O(n) for vector/deque.
    if (pairCount > 1)
    {
        std::vector<size_t> order = jacobsthalSequence(pairCount - 1);
        for (size_t i = 0; i < order.size(); ++i)
        {
            size_t idx  = order[i];
            T val       = ordered[idx].second;
            T bound     = ordered[idx].first;

            Iter ub  = std::upper_bound(chain.begin(), chain.end(), bound);
            Iter pos = std::lower_bound(chain.begin(), ub, val);
            chain.insert(pos, val);
        }
    }

    // --- Step 6: insert the straggler ---
    if (hasStraggler)
    {
        Iter pos = std::lower_bound(chain.begin(), chain.end(), straggler);
        chain.insert(pos, straggler);
    }

    return chain;
}

// ---------------------------------------------------------------------------
// Timer (microseconds via CLOCK_MONOTONIC)
// ---------------------------------------------------------------------------
static double getTimeUs()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1e6 + ts.tv_nsec / 1e3;
}

// ---------------------------------------------------------------------------
// Main
// ---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <numbers...>\n";
        return 1;
    }

    std::vector<int> input;
    for (int i = 1; i < argc; ++i)
    {
        std::istringstream iss(argv[i]);
        int val;
        if (!(iss >> val) || val < 0)
        {
            std::cerr << "Invalid number: " << argv[i] << "\n";
            return 1;
        }
        input.push_back(val);
    }

    size_t n = input.size();

    std::cout << "Before:";
    for (size_t i = 0; i < n; ++i) std::cout << " " << input[i];
    std::cout << "\n";

    // --- std::vector ---
    std::vector<int> vecInput(input.begin(), input.end());
    double t0 = getTimeUs();
    std::vector<int> sortedVec = fjSort<std::vector<int> >(vecInput);
    double t1 = getTimeUs();

    // --- std::deque ---
    std::deque<int> deqInput(input.begin(), input.end());
    double t2 = getTimeUs();
    std::deque<int> sortedDeq = fjSort<std::deque<int> >(deqInput);
    double t3 = getTimeUs();

    // --- std::list ---
    std::list<int> lstInput(input.begin(), input.end());
    double t4 = getTimeUs();
    std::list<int> sortedLst = fjSort<std::list<int> >(lstInput);
    double t5 = getTimeUs();

    std::cout << "After:";
    for (size_t i = 0; i < sortedVec.size(); ++i) std::cout << " " << sortedVec[i];
    std::cout << "\n";

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << n
              << " elements with std::vector : " << (t1 - t0) << " us\n";
    std::cout << "Time to process a range of " << n
              << " elements with std::deque  : " << (t3 - t2) << " us\n";
    std::cout << "Time to process a range of " << n
              << " elements with std::list   : " << (t5 - t4) << " us\n";

    return 0;
}
