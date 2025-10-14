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

		AForm* makeForm( std::string form ) const;
};

#endif // INTERN_HPP
