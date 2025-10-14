#include "Harl.hpp"

#include <iostream>

Harl::Harl(void) {}

Harl::~Harl(void) {}

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << '\n'
			<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!"
			<< '\n' << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << '\n'
			<< "I cannot believe adding extra bacon costs more money."
			<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
			<< '\n' << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << '\n'
			<< "I think I deserve to have some extra bacon for free."
			<< "I’ve been coming for years, whereas you started working here just last month."
			<< '\n' << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << '\n'
			<< "This is unacceptable! I want to speak to the manager now."
			<< '\n' << std::endl;
}

int	Harl::getLevel(std::string arg)
{
	for (int i = 0; i < 4; i++) {
		if (arg == Harl::levels[i])
			return (i);
	}
	return (-1);
}

void	Harl::complain( int i )
{
	void (Harl::*f[4])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	if (i > -1 && i < 4) return (this->*f[i])();
}

std::string Harl::levels[4] = {"debug", "info", "warning", "error"};
