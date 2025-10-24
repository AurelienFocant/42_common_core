#include "Harl.hpp"

#include <iostream>

int	main()
{
	Harl		harl;
	std::string	level;

	std::cout	<< "Input the level of Hal's complain: ";
	std::cin	>> level;
	harl.complain(level);

	return (0);
}
