#include "Span.hpp"

#include <stdint.h>
#include <iostream>
#include <list>
#include <set>
#include <cstdlib>
#include <ctime>

int	main()
{
	{
		try {
			Span sp = Span(5);

			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);

			std::cout << sp.shortestSpan() << '\n';
			std::cout << sp.longestSpan() << '\n';

			sp.addNumber(42);
		}
		catch (std::exception const& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	std::cout << "===========================\n";

	{
		try {
			std::list<int>	list;
			list.push_back(6);
			list.push_back(3);
			list.push_back(17);

			std::set<int>	set;
			set.insert(9);
			set.insert(11);

			Span	sp(5);
			sp.addRange(list.begin(), list.end());
			sp.addRange(set.begin(), set.end());

			std::cout << sp.shortestSpan() << '\n';
			std::cout << sp.longestSpan() << '\n';

			Span	sp2(4);
			sp2.addRange(list.begin(), list.end());
			sp2.addRange(set.begin(), set.end());
		}
		catch (std::exception const& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	std::cout << "===========================\n";

	{
		srand(time(NULL));

		try {
			Span sp(50000);
			for (int i = 0; i < 50000; ++i) {
				sp.addNumber(rand());
			}

			std::cout << sp.shortestSpan() << '\n';
			std::cout << sp.longestSpan() << '\n';
		}
		catch (std::exception const& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
}
