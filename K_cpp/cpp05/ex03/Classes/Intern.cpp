#include "Intern.hpp"
#include "AForm.hpp"

#include <iostream>

static std::string normalizeString( std::string & str);

// CONSTRUCTORS //
Intern::Intern( void )
{
}

Intern::Intern( const Intern& src )
{
	(void) src;
}

Intern&	Intern::operator=( const Intern& rhs )
{
	if (this != &rhs) {
	}
	return (*this);
}

Intern::~Intern( void )
{
}


// MEMBER FUNCTIONS //
AForm*	Intern::makeForm( std::string form ) const
{
	std::string forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	// normalize form name
	normalizeString(form);


	for (int i = 0; i < 3; i++) {
		if (normalizeString(forms[i]).find(form) != std::string::npos) {
			return (new );
		}
	}

	return (NULL);
}


// HELPER FUNCTIONS //
static void	toLower( std::string & str )
{
	for (std::size_t i = 0; i < str.length(); i++) {
		str[i] = static_cast<char>(std::tolower(str[i]));	// to lowercase
	}
}

static void	deleteWhitespace( std::string & str )
{
	for (std::size_t i = 0; i < str.length(); i++) {
		if (std::isspace(str[i])) {						// take out whitespace
			str.erase(i, 1);
		}
	}
}

static std::string normalizeString( std::string & str)
{
	toLower(str);
	deleteWhitespace(str);
	return (str);
}
