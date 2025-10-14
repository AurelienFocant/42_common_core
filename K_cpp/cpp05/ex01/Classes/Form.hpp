#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;

class Form
{

	public:
		Form	( void );
		Form	( const Form& src );
		Form&	operator=	( const Form& rhs );
		~Form	( void );

		Form	( const std::string name,
				  const int			gradeToBeSigned,
				  const int			gradeToBeExecuted );

		const std::string	getName		( void ) const;
		int					getGradeSig	( void ) const;
		int					getGradeExe	( void ) const;
		bool				getIfSigned	( void ) const;

		bool	beSigned( Bureaucrat& b );

		class GradeTooHighException : public std::exception {
			public:
				const char*	what() const throw() { return "grade too high!"; };
		};

		class GradeTooLowException : public std::exception {
			public:
				const char*	what() const throw() { return "grade too low!"; };
		};


	private:
		const std::string	_name;
		const int			_gradeToBeSigned;
		const int			_gradeToBeExecuted;
		bool				_isSigned;

};

std::ostream& operator<<(std::ostream& out, Form& form);

#endif // FORM_HPP
