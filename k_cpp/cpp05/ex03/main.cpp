#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include "Intern.hpp"

#include <iostream>

int	main( void )
{
	Intern	intern;
	std::string	formName;

	formName = "Shrubbery creation";
	AForm* form = intern.makeForm(formName, "Aurel");
	(void) form;

	std::cout << formName << std::endl;
}
