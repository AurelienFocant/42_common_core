#include "ScalarConverter.hpp"

#include <iostream>

int	main(int ac, char **av)
{
	std::string	s;

	if (ac != 2) {
		std::cout << "Usage: one argument to be converted is needed\n";
		return (1);
	}
	s = av[1];
	ScalarConverter::convert(s);
	return (0);
}
