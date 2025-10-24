#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

#include <fstream>

class ShrubberyCreationForm : public AForm
{

	public:
		ShrubberyCreationForm	( void );
		ShrubberyCreationForm	( const std::string target );

		ShrubberyCreationForm	( const ShrubberyCreationForm& src );
		ShrubberyCreationForm&	operator=	( const ShrubberyCreationForm& rhs );

		virtual ~ShrubberyCreationForm	( void );

		const std::string	getFileName	( void ) const;


	private:
		std::string		_filename;

		virtual bool _formExecution( void ) const; //override


};

std::ostream&	operator<<(std::ostream& out, ShrubberyCreationForm const& form);

#endif // SHRUBBERYCREATIONFORM_HPP
