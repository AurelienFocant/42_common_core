#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

int	main( void )
{

	Bureaucrat john_150("John", 150);
	Bureaucrat jean_120("Jean", 120);

	try {
		ShrubberyCreationForm	f1;
		ShrubberyCreationForm	f2("TargetAcquired");

		// std::cout << f1 << '\n';
		// std::cout << f2 << '\n';

		jean_120.signForm(f1);
		jean_120.signForm(f2);
		ShrubberyCreationForm	f3(f1);
		jean_120.executeForm(f1);
		jean_120.executeForm(f2);
		jean_120.executeForm(f3);


	}
	catch (std::exception const& e) {
		std::cout << "Exception Caught: " << e.what() << std::endl;
	}

	std::cout << "This line is executed\n"; 
}
