#include "Harl.hpp"

#include <iostream>

int	main(int ac, char **av)
{
	Harl		harl;
	std::string	level;

	if (ac != 2) {
		std::cout << "Usage: needs one argument" << std::endl;
		return (1);
	}

	switch(Harl::getLevel((std::string) av[1])) {
		case (0):
			harl.complain(0);
		case (1):
			harl.complain(1);
		case (2):
			harl.complain(2);
		case (3):
			harl.complain(3);
			break;
		default:
			std::cerr
				<< "Only 'debug', 'info', 'warning' and 'error' levels exist"
				<< std::endl;
	}

	return (0);
}
