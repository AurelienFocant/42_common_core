#include "Array.hpp"

#include <iostream>

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
		b[1] = 2;
		b[2] = 3;
		b[3] = 4;
		std::cout << b[0] << '\n';
		std::cout << b[1] << '\n';
		std::cout << b[2] << '\n';
		std::cout << b[3] << '\n';
		std::cout << b[4] << '\n';
	}
	catch (std::exception const& e) {
		std::cerr << e.what() << '\n';
	}

}
