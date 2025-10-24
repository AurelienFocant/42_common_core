#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

static std::string normalizeString( std::string str);
static AForm* createShrubbery(std::string const& target);
static AForm* createRobotomy(std::string const& target);
static AForm* createPresidential(std::string const& target);

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
AForm*	Intern::makeForm( std::string form, std::string const target ) const
{
	AForm* (*functions[]) (const std::string& target) = {
		&createShrubbery,
        &createRobotomy,
        &createPresidential
	};
	std::string forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};


	for (int i = 0; i < 3; i++) {
		std::string f = normalizeString(forms[i]);
		if (normalizeString(forms[i]).find(normalizeString(form)) != std::string::npos) {
			std::cout << "Intern created form " << forms[i] << std::endl;
			return (functions[i](target));
		}
	}

	std::cout << "Intern couldn't create form " << form << std::endl;
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
			i--;
		}
	}
}

static std::string normalizeString( std::string str)
{
	toLower(str);
	deleteWhitespace(str);
	return (str);
}

// HELPER FUNCTIONS: FORM CREATION //
static AForm* createShrubbery(std::string const& target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(std::string const& target)
{
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(std::string const& target)
{
    return new PresidentialPardonForm(target);
}
