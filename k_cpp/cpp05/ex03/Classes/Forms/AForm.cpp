#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

AForm::AForm( void )
	: _name("default name")
	, _target("no target")
	, _gradeToBeSigned(150)
	, _gradeToBeExecuted(150)
	, _isSigned(false)
{
	std::cout << "Form Object Constructed" << std::endl;
}

AForm::AForm( std::string const name )
	: _name(name)
	, _target("no target")
	, _gradeToBeSigned(150)
	, _gradeToBeExecuted(150)
	, _isSigned(false)
{
	std::cout << "Form Object Constructed" << std::endl;
}

AForm::AForm( const AForm& src )
	: _name("default name")
	, _target(src.getTarget())
	, _gradeToBeSigned(src._gradeToBeSigned)
	, _gradeToBeExecuted(src._gradeToBeExecuted)
	, _isSigned(src._isSigned)
{
}

AForm&	AForm::operator=( const AForm& rhs )
{
	std::cout << "Form Object Copied by Assignment" << std::endl;

	if (this != &rhs) {
		this->_target = rhs._target;
		this->_gradeToBeSigned = rhs._gradeToBeSigned ;
		this->_gradeToBeExecuted = rhs._gradeToBeExecuted;
		this->_isSigned = rhs._isSigned;
	}
	return (*this);
}

AForm::~AForm( void )
{
}

AForm::AForm( const std::string name, const std::string target, const int gradeToBeSigned, const int gradeToBeExecuted )
	: _name(name)
	, _target(target)
	, _gradeToBeSigned(gradeToBeSigned)
	, _gradeToBeExecuted(gradeToBeExecuted)
	, _isSigned(false)
{
	if (gradeToBeSigned < 1 || gradeToBeExecuted < 1)
		throw AForm::GradeTooHighException("Invalid grade for this Form: Too High");
	if (gradeToBeSigned > 150 || gradeToBeExecuted > 150)
		throw AForm::GradeTooLowException("Invalid grade for this Form: Too Low");
}

const std::string	AForm::getName( void ) const
{
	return (this->_name);
}

const std::string	AForm::getTarget( void ) const
{
	return (_target);
}


int					AForm::getGradeSig( void ) const
{
	return (this->_gradeToBeSigned);
}

int					AForm::getGradeExe( void ) const
{
	return (this->_gradeToBeExecuted);
}

bool				AForm::getIfSigned( void ) const
{
	return (this->_isSigned);
}

bool	AForm::beSigned( Bureaucrat const& b )
{
	if (b.getGrade() > this->_gradeToBeSigned)
		throw AForm::GradeTooLowException("Bureaucrat's grade is too low to sign this Form");

	this->_isSigned = true;
	return (true);
}

bool	AForm::execute( Bureaucrat const& executor ) const
{
	if (!this->_isSigned)
		throw FormUnsignedException("Form is not signed");
	if (executor.getGrade() > this->_gradeToBeExecuted)
		throw GradeTooLowException("Bureaucrat's grade is too low to execute to execute the form");

	return (this->_formExecution());
}

std::ostream& operator<<(std::ostream& out, AForm const& form)
{
	out << "The form type is "				<< form.getName()	  << '\n'
		<< "its signing grade is "			<< form.getGradeSig() << '\n'
		<< "its executing grade is "		<< form.getGradeExe() << '\n'
		<< std::boolalpha
		<< "and its signature status is "	<< form.getIfSigned()
		<< std::endl;

	return (out);
}
