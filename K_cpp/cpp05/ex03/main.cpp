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
	intern.makeForm(formName);

	std::cout << formName << std::endl;
}
