#include "utils.hpp"

#include <vector>
#include <deque>
#include <list>
#include <map>
#include <algorithm>
#include <utility>
#include <iostream>
#include <iomanip>

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

template <typename Container>
Container fjSort(const Container& input)
{
    typedef typename Container::value_type T;
    typedef typename Container::iterator   Iter;

    std::vector<T> seq(input.begin(), input.end());
    size_t seqSize = seq.size();

	// Base cases
    if (seqSize <= 1)
        return input;

    if (seqSize == 2)
    {
        if (seq[1] < seq[0])
			std::swap(seq[0], seq[1]);
        return Container(seq.begin(), seq.end());
    }


	// Lone odd element
    bool hasStraggler = (seqSize % 2 != 0);
    T straggler;
	if (hasStraggler)
		straggler = seq.back();

    size_t pairCount = seqSize / 2;

    // --- Step 1: form pairs (larger, smaller) ---
    std::vector<std::pair<T, T> > pairs;
    pairs.reserve(pairCount);
    for (size_t i = 0; i < pairCount; ++i)
    {
        T a = seq[2 * i];
        T b = seq[2 * i + 1];
        if (a < b)
			std::swap(a, b);
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
// Main
// ---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <numbers...>\n";
        return 1;
    }

	std::vector<int> seq;
	try {
		seq = parseInput(argc, argv);
	}
	catch (std::exception const& e) {
		std::cerr << e.what();
		return (1);
	}


	size_t size = seq.size();

	std::cout << "Before:";
	for (size_t i = 0; i < size; ++i) std::cout << " " << seq[i];
	std::cout << "\n";

	// --- std::vector ---
	std::vector<int> vecInput(seq.begin(), seq.end());
	double t0 = getCurrTime();
	std::vector<int> sortedVec = fjSort<std::vector<int> >(vecInput);
	double t1 = getCurrTime();

	// --- std::deque ---
	std::deque<int> deqInput(seq.begin(), seq.end());
	double t2 = getCurrTime();
	std::deque<int> sortedDeq = fjSort<std::deque<int> >(deqInput);
	double t3 = getCurrTime();

	// --- std::list ---
	std::list<int> lstInput(seq.begin(), seq.end());
	double t4 = getCurrTime();
	std::list<int> sortedLst = fjSort<std::list<int> >(lstInput);
	double t5 = getCurrTime();

	std::cout << "After:";
	for (size_t i = 0; i < sortedVec.size(); ++i) std::cout << " " << sortedVec[i];
	std::cout << "\n";

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << size
		<< " elements with std::vector : " << (t1 - t0) << " us\n";
	std::cout << "Time to process a range of " << size
		<< " elements with std::deque  : " << (t3 - t2) << " us\n";
	std::cout << "Time to process a range of " << size
		<< " elements with std::list   : " << (t5 - t4) << " us\n";

	return 0;
}
