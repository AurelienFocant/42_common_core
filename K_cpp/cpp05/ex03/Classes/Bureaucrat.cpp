#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <iostream>

Bureaucrat::Bureaucrat( void )
	: _name("defaultName")
	, _grade(150)
{
}

Bureaucrat::Bureaucrat( const Bureaucrat& src )
	: _grade(src._grade)
{
}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& rhs )
{
	if (this != &rhs) {
		_grade = rhs.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat( void )
{
}

Bureaucrat::Bureaucrat( const std::string name, int grade ) :
	_name(name)
{
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

void	Bureaucrat::downGrade ( void )
{
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();

	_grade++;
}

bool	Bureaucrat::signForm(AForm& form) const
{ 
	try {
		form.beSigned(*this);
		std::cout
			<< _name << " signed form " << form.getName() << std::endl;
		return (true);
	}
	catch (AForm::GradeTooLowException const& e) {
		std::cout
			<< _name << " couldn't sign form " << form.getName()
			<< " because " << e.what()
			<< std::endl;
		return (false);
	}
}

bool	Bureaucrat::executeForm(AForm const& form) const
{
	try {
		form.execute(*this);
		std::cout
			<< _name << " executed form " << form.getName()
			<< " targeted towards " << form.getTarget()
			<< std::endl;
		return (true);
	}
	catch (std::exception & e) {
		std::cout
			<< _name << " could not execute form " << form.getName()
			<< " because " << e.what()
			<< std::endl;
			return (false);
	}
}




const char*	Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("Can't assign grade: Grade of Bureaucrat is too low!");
}

const char*	Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("Can't assign grade: Grade of Bureaucrat is too high!");
}

std::ostream&	operator<<(std::ostream& out, Bureaucrat& bureaucrat)
{
	out << "The bureaucrat name is " << bureaucrat.getName()	<< '\n'
		<< "and is grade is "		 << bureaucrat.getGrade()	<< '\n'
		<< std::endl;
	return (out);
}
