#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <utility>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>

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

template <typename T, template <typename, typename> class Container>
Container<T, std::allocator<T> >
fjSort(const Container<T, std::allocator<T> >& seq)
{
    typedef Container<T, std::allocator<T> > Cont;

    size_t n = seq.size();

    if (n <= 1)
        return seq;

    if (n == 2)
    {
        Cont out(seq);
        if (out[1] < out[0])
            std::swap(out[0], out[1]);
        return out;
    }

    bool hasStraggler = (n % 2 != 0);
    T straggler;
    if (hasStraggler)
        straggler = seq[n - 1];

    size_t pairCount = n / 2;

    // STEP 1: pairs (larger, smaller)
    Container< std::pair<T, T>, std::allocator< std::pair<T, T> > > pairs;

    for (size_t i = 0; i < pairCount; ++i)
    {
        T a = seq[2*i];
        T b = seq[2*i + 1];

        if (a < b)
            std::swap(a, b);

        pairs.push_back(std::make_pair(a, b));
    }

    // STEP 2: extract largers
    Cont largers;
    for (size_t i = 0; i < pairCount; ++i)
        largers.push_back(pairs[i].first);

    // STEP 3: recursive sort
    Cont sortedLargers = fjSort<T, Container>(largers);

    // STEP 4: multimap for matching
    std::multimap<T, std::pair<T, T> > mp;
    for (size_t i = 0; i < pairCount; ++i)
        mp.insert(std::make_pair(pairs[i].first, pairs[i]));

    Container< std::pair<T, T>, std::allocator< std::pair<T, T> > > ordered;

    for (size_t i = 0; i < pairCount; ++i)
    {
        typename std::multimap<T, std::pair<T, T> >::iterator it =
            mp.find(sortedLargers[i]);

        ordered.push_back(it->second);
        mp.erase(it);
    }

    // STEP 5: build main chain
    Cont chain;

    chain.push_back(ordered[0].second);

    for (size_t i = 0; i < pairCount; ++i)
        chain.push_back(ordered[i].first);

    // STEP 6: Jacobsthal insertion
    if (pairCount > 1)
    {
        std::vector<size_t> order = jacobsthalSequence(pairCount - 1);

        for (size_t i = 0; i < order.size(); ++i)
        {
            size_t idx = order[i];

            T val   = ordered[idx].second;
            T bound = ordered[idx].first;

            typename Cont::iterator ub =
                std::upper_bound(chain.begin(), chain.end(), bound);

            typename Cont::iterator pos =
                std::lower_bound(chain.begin(), ub, val);

            chain.insert(pos, val);
        }
    }

    // STEP 7: straggler
    if (hasStraggler)
    {
        typename Cont::iterator pos =
            std::lower_bound(chain.begin(), chain.end(), straggler);
        chain.insert(pos, straggler);
    }

    return chain;
}

// ------------------------
// High-resolution timer (microseconds via CLOCK_MONOTONIC)
// ------------------------
static double getTimeUs()
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return ts.tv_sec * 1e6 + ts.tv_nsec / 1e3;
}

// ------------------------
// Main
// ------------------------
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

	// --- std::vector sort ---
	std::vector<int> vecInput = input;
	double t0 = getTimeUs();
	std::vector<int> sortedVec = fjSort(vecInput);
	double t1 = getTimeUs();

	// --- std::deque sort ---
	std::deque<int> deqInput(input.begin(), input.end());
	double t2 = getTimeUs();
	std::deque<int> sortedDeq = fjSort(deqInput);
	double t3 = getTimeUs();

	std::cout << "After:";
	for (size_t i = 0; i < sortedVec.size(); ++i) std::cout << " " << sortedVec[i];
	std::cout << "\n";

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << n
		<< " elements with std::vector : " << (t1 - t0) << " us\n";
	std::cout << "Time to process a range of " << n
		<< " elements with std::deque  : " << (t3 - t2) << " us\n";

	return 0;
}
