#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

//								SIGN  EXEC
// ShrubberyCreationForm	--> 145// 137
// RobotomyRequestForm		--> 72 // 45
// PresidentialPardonForm	--> 25 // 5

static void testAllGoesWell(void)
{
	Bureaucrat john_150("John", 150);
	Bureaucrat jean_120("Jean", 120);
	Bureaucrat julian_1("Julian", 1);

	ShrubberyCreationForm	shrub("target1");
	RobotomyRequestForm		robot("target2");
	PresidentialPardonForm	prez("target3");

	try {
		jean_120.signForm(shrub);
		julian_1.signForm(robot);
		julian_1.signForm(prez);

		jean_120.executeForm(shrub);
		julian_1.executeForm(robot);
		julian_1.executeForm(prez);
		std::cout << "All went well\n"; 
	}
	catch (std::exception const& e) {
		std::cout << "Exception Caught: " << e.what() << std::endl;
	}
}

static void	testSignException(void)
{
	Bureaucrat john_150("John", 150);
	Bureaucrat jean_120("Jean", 120);
	Bureaucrat julian_1("Julian", 1);

	ShrubberyCreationForm	shrub("target1");
	RobotomyRequestForm		robot("target2");
	PresidentialPardonForm	prez("target3");

	try {
		jean_120.signForm(shrub);
		jean_120.signForm(robot);
		julian_1.signForm(prez);

		jean_120.executeForm(shrub);
		julian_1.executeForm(robot);
		julian_1.executeForm(prez);
		std::cout << "All went well\n"; 
	}
	catch (std::exception const& e) {
		std::cout << "Exception Caught: " << e.what() << std::endl;
	}
}

static void testUnsignedForm(void)
{
	Bureaucrat john_150("John", 150);
	Bureaucrat jean_120("Jean", 120);
	Bureaucrat julian_1("Julian", 1);

	ShrubberyCreationForm	shrub("target1");
	RobotomyRequestForm		robot("target2");
	PresidentialPardonForm	prez("target3");

	try {
		jean_120.signForm(shrub);
		julian_1.signForm(prez);

		jean_120.executeForm(shrub);
		julian_1.executeForm(robot);
		julian_1.executeForm(prez);
		std::cout << "All went well\n"; 
	}
	catch (std::exception const& e) {
		std::cout << "Exception Caught: " << e.what() << std::endl;
	}
}

static void testExecException(void)
{
	Bureaucrat john_150("John", 150);
	Bureaucrat jean_120("Jean", 120);
	Bureaucrat julian_1("Julian", 1);

	ShrubberyCreationForm	shrub("target1");
	RobotomyRequestForm		robot("target2");
	PresidentialPardonForm	prez("target3");

	try {
		jean_120.signForm(shrub);
		julian_1.signForm(robot);
		julian_1.signForm(prez);

		jean_120.executeForm(shrub);
		jean_120.executeForm(robot);
		julian_1.executeForm(prez);
		std::cout << "All went well\n"; 
	}
	catch (std::exception const& e) {
		std::cout << "Exception Caught: " << e.what() << std::endl;
	}
}


int	main( void )
{
	std::cout << "-----------------------------------------------\n";
	testAllGoesWell();
	std::cout << "-----------------------------------------------\n";
	testSignException();
	std::cout << "-----------------------------------------------\n";
	testUnsignedForm();
	std::cout << "-----------------------------------------------\n";
	testExecException();
}
