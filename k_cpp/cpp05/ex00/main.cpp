#include "Bureaucrat.hpp"

#include <iostream>
#include <cstdlib>

void	makeBadBureaucrats( void )
{
	Bureaucrat	boss("boss", 1);

	boss.upGrade();
}

void	makeGoodBureaucrats( void )
{
	Bureaucrat	john("john", 1);
	john.downGrade();

	Bureaucrat	bob("bob", 150);
	bob.upGrade();

	Bureaucrat	bureaucrat;
	bureaucrat.upGrade();
	bureaucrat.upGrade();
	bureaucrat.downGrade();

	throw std::runtime_error("plouf");
}

int	main( void )
{
	try {
		makeGoodBureaucrats();
		makeBadBureaucrats();
	}
	catch ( Bureaucrat::GradeTooHighException const& e) {
		std::cout << "Specific exception caught: " << e.what() << std::endl;
	}
	catch ( std::exception const& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch ( ... ) {
		std::cout << "Unknown exception occured, program terminated" << std::endl;
	}

	std::cout << "Stack unwinding is hard to understand !" << std::endl;

	return (EXIT_SUCCESS);
}
