#include "RPN.hpp"

#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Usage: ./RPN \"input string\"\n";
		return (1);
	}

	RPN	rpn(av[1]);
	try {
		int res = rpn.execute();
		std::cout << res << '\n';
		return (0);
	}
	catch (std::exception const& e) {
		std::cerr << "Error\n";
		return (2);
	}
}
