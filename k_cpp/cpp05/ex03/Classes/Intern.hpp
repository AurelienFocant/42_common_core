#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern
{
	public:
		Intern	( void );
		Intern	( const Intern& src );
		Intern&	operator=	( const Intern& rhs );
		~Intern	( void );

		AForm* makeForm( std::string f, std::string const target ) const;

		class FormDoesntExistMom : public std::exception {
			public:
				FormDoesntExistMom( const char* msg) : _msg(msg) {};
				const char*	what() const throw() { return _msg; };
			private:
				const char* _msg;
		};
};

#endif // INTERN_HPP
