#include "Array.hpp"

#include <iostream>
#include <string>

int	main()
{
	Array<int> a;

	try {
		a[0] = 1;
	}
	catch (std::exception const& e) {
		std::cerr << e.what() << '\n';
	}

	Array<int> b(4);
	try {
		b[0] = 1;
		std::cout << b[0] << '\n';
		std::cout << b[1] << '\n';
	}
	catch (std::exception const& e) {
		std::cerr << e.what() << '\n';
	}
}
