#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

Form::Form( void )
	: _name("default name")
	, _gradeToBeSigned(150)
	, _gradeToBeExecuted(150)
	, _isSigned(false)
{
	std::cout << "Form Object Constructed" << std::endl;
}

Form::Form( const Form& src )
	: _name("default name")
	, _gradeToBeSigned(src._gradeToBeSigned)
	, _gradeToBeExecuted(src._gradeToBeExecuted)
	, _isSigned(src._isSigned)
{
	std::cout << "Form Object Constructed by Copy" << std::endl;
}

Form&	Form::operator=( const Form& rhs )
{
	std::cout << "Form Object Copied by Assignment" << std::endl;

	if (this != &rhs) {
		this->_isSigned = rhs._isSigned;
	}
	return (*this);
}

Form::~Form( void )
{
	std::cout << "Form Object Destroyed" << std::endl;
}

Form::Form( const std::string name, const int gradeToBeSigned, const int gradeToBeExecuted )
	: _name(name)
	, _gradeToBeSigned(gradeToBeSigned)
	, _gradeToBeExecuted(gradeToBeExecuted)
	, _isSigned(false)
{
	std::cout << "Form Object Constructed" << std::endl;

	if (gradeToBeSigned < 1 || gradeToBeExecuted < 1)
		throw Form::GradeTooHighException();
	if (gradeToBeSigned > 150 || gradeToBeExecuted > 150)
		throw Form::GradeTooLowException();
}

const std::string	Form::getName( void ) const
{
	return (this->_name);
}

int					Form::getGradeSig( void ) const
{
	return (this->_gradeToBeSigned);
}

int					Form::getGradeExe( void ) const
{
	return (this->_gradeToBeExecuted);
}

bool				Form::getIfSigned( void ) const
{
	return (this->_isSigned);
}

bool	Form::beSigned( Bureaucrat& b )
{
	if (b.getGrade() > this->_gradeToBeSigned)
		throw Form::GradeTooLowException();

	this->_isSigned = true;
	return (true);
}

std::ostream& operator<<(std::ostream& out, Form& form)
{
	out << "The form name is "				<< form.getName()	  << '\n'
		<< "its signing grade is "			<< form.getGradeSig() << '\n'
		<< "its executing grade is "		<< form.getGradeExe() << '\n'
		<< std::boolalpha
		<< "and its signature status is "	<< form.getIfSigned() << '\n'
		<< std::endl;

	return (out);
}
