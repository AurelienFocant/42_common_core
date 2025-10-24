#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm( void )
	: AForm("PresidentialPardonForm", "NoTarget", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm( const std::string target )
	: AForm("PresidentialPardonForm", target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& src )
	: AForm(src)
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm& rhs )
{
	if (this != &rhs) {
		AForm::operator=(rhs);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
}

bool	PresidentialPardonForm::_formExecution( void ) const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return (true);
}
