#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include "Intern.hpp"

#include <iostream>

int	main( void )
{
	Intern		intern;
	std::string	formName;

	{
		formName = "Shrubbery creation";
		try {
			AForm* form = intern.makeForm(formName, "Aurel");
			std::cout << *form << std::endl;
			delete form;
		}
		catch (Intern::FormDoesntExistMom const& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	{
		formName = "plaf";
		try {
			AForm* form = intern.makeForm(formName, "Aurel");
			std::cout << *form << std::endl;
			delete form;
		}
		catch (Intern::FormDoesntExistMom const& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	{
		formName = "shrubbery creat";
		try {
			AForm* form = intern.makeForm(formName, "Aurel");
			std::cout << *form << std::endl;
			delete form;
		}
		catch (Intern::FormDoesntExistMom const& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	{
		formName = "pres";
		try {
			AForm* form = intern.makeForm(formName, "Aurel");
			std::cout << *form << std::endl;
			delete form;
		}
		catch (Intern::FormDoesntExistMom const& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	{
		formName = "presa";
		try {
			AForm* form = intern.makeForm(formName, "Aurel");
			std::cout << *form << std::endl;
			delete form;
		}
		catch (Intern::FormDoesntExistMom const& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
}
