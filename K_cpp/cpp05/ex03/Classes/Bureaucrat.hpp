#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class AForm;

class Bureaucrat
{

	public:
		Bureaucrat	( void );
		Bureaucrat	( const Bureaucrat& src );
		Bureaucrat&	operator=	( const Bureaucrat& rhs );
		~Bureaucrat	( void );

		Bureaucrat	( const std::string name, int grade );

		const std::string	getName		( void ) const;
		int					getGrade	( void ) const;

		void	upGrade  ( void );
		void	downGrade( void );

		bool	signForm	(AForm& form)		const;
		bool	executeForm (AForm const& form) const;



		class GradeTooHighException : public std::exception {
			public:
				const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char*	what() const throw();
		};


	private:
		const std::string	_name;
		int					_grade;




};

std::ostream&	operator<<(std::ostream& out, Bureaucrat& bureaucrat);

#endif // BUREAUCRAT_HPP
