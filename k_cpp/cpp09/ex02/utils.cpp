#include "utils.hpp"

#include <ctime>
#include <vector>
#include <sstream>

double getCurrTime()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1e6 + ts.tv_nsec / 1e3;
}

std::vector<int>	parseInput(int argc, char **argv)
{
    std::vector<int> input;
    for (int i = 1; i < argc; ++i)
    {
        std::istringstream ss(argv[i]);
        int		val;
		char	c;
		ss >> val;
        if (ss.fail() || val < 0 || (ss >> c))
        {
			std::string	err("Invalid number: " + std::string(argv[i]) + "\n");
			throw (std::runtime_error(err));
        }
        input.push_back(val);
    }
	return (input);
}
