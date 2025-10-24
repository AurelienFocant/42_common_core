#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;

class AForm
{
	public:
		AForm	( void );
		AForm	( std::string const name );
		AForm	( const AForm& src );
		AForm&	operator=	( const AForm& rhs );
		virtual ~AForm	( void );

		AForm	( const std::string name,
				  const std::string target,
				  const int			gradeToBeSigned,
				  const int			gradeToBeExecuted );

		const std::string	getName		( void ) const;
		const std::string	getTarget	( void ) const;
		int					getGradeSig	( void ) const;
		int					getGradeExe	( void ) const;
		bool				getIfSigned	( void ) const;


				bool beSigned	( Bureaucrat const& b );	
		virtual bool execute	( Bureaucrat const& executor ) const;



		class FormUnsignedException : public std::exception {
			public:
				FormUnsignedException ( const char *msg ) : _msg(msg) {};
				const char*	what() const throw() { return _msg; };
			private:
				const char* _msg;
		};

		class GradeTooHighException : public std::exception {
			public:
				GradeTooHighException ( const char *msg ) : _msg(msg) {};
				const char*	what() const throw() { return _msg; };
			private:
				const char* _msg;
		};

		class GradeTooLowException : public std::exception {
			public:
				GradeTooLowException ( const char *msg ) : _msg(msg) {};
				const char*	what() const throw() { return _msg; };
			private:
				const char* _msg;
		};




	private:
		const std::string	_name;
			  std::string	_target;
			  int			_gradeToBeSigned;
			  int			_gradeToBeExecuted;
			  bool			_isSigned;

	protected:
		virtual bool _formExecution( void ) const = 0;

};

std::ostream& operator<<(std::ostream& out, AForm const& form);

#endif // FORM_HPP
