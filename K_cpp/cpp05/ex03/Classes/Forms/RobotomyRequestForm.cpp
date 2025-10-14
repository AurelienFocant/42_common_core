#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm( void )
	: AForm("ShrubberyCreationForm", "NoTarget", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm( const std::string target )
	: AForm("ShrubberyCreationForm", target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& src )
	:AForm(src)
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm& rhs )
{
	if (this != &rhs) {
		AForm::operator=(rhs);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
}

bool	RobotomyRequestForm::_formExecution( void ) const
{
	srand(time(0));

	if (rand() % 2) {
		std::cout << getTarget() << " has been robotomised !" << std::endl;
		return (true);
	}
	std::cout << "Robotomy of " << getTarget() << " failed" << std::endl;
	return (false);
}
