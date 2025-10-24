#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

Bureaucrat::Bureaucrat( void )
	: _name("defaultName")
	, _grade(150)
{
	std::cout << "Bureaucrat Object Constructed" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& src )
	: _grade(src._grade)
{
	std::cout << "Bureaucrat Object Constructed by Copy" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& rhs )
{
	std::cout << "Bureaucrat Object Copied by Assignment" << std::endl;

	if (this != &rhs) {
		_grade = rhs.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat Object Destroyed" << std::endl;
}

Bureaucrat::Bureaucrat( const std::string name, int grade ) :
	_name(name)
{
	std::cout << "Bureaucrat Object Constructed" << std::endl;

	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();

	this->_grade = grade;
}

const std::string	Bureaucrat::getName	( void ) const
{
	return (_name);
}

int					Bureaucrat::getGrade( void ) const
{
	return (_grade);
}

void	Bureaucrat::upGrade ( void )
{
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();

	_grade--;
}

bool	Bureaucrat::signForm(Form& form)
{
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
		return (true);
	}
	catch (Form::GradeTooLowException const& e) {
		std::cout	<< this->getName()	<< " couldn't sign " << form.getName()
					<< " because "		<< e.what()
					<< std::endl;
		return (false);
	}
}

void	Bureaucrat::downGrade ( void )
{
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();

	_grade++;
}

const char*	Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("Can't assign grade: Grade too low!");
}

const char*	Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("Can't assign grade: Grade too high!");
}

std::ostream&	operator<<(std::ostream& out, Bureaucrat& bureaucrat)
{
	out << "The bureaucrat name is " << bureaucrat.getName()	<< '\n'
		<< "and is grade is "		 << bureaucrat.getGrade()	<< '\n'
		<< std::endl;
	return (out);
}
