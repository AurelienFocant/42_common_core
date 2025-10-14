#include "ShrubberyCreationForm.hpp"

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm( void )
	: AForm("ShrubberyCreationForm", "NoTarget", 145, 137)
	, _filename(getTarget() + "_shrubbery")
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target )
	: AForm("ShrubberyCreationForm", target, 145, 137)
	, _filename(getTarget() + "_shrubbery")
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& src )
	: AForm(src)
	, _filename(src._filename)
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( const ShrubberyCreationForm& rhs )
{
	if (this != &rhs) {
		AForm::operator=(rhs);
		_filename = rhs._filename;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
}

const std::string	ShrubberyCreationForm::getFileName( void ) const
{
	return (_filename);
}

bool	ShrubberyCreationForm::_formExecution( void ) const
{
	std::ofstream	outfile(_filename.c_str());
	if (!outfile.is_open())
		throw std::runtime_error("Couldn't open file to execute form");

	outfile
       << "                        @@     @%                                 \n"
       << "           ##&%## @& @#@#%%&@  @&%&%@%                            \n"
       << "          %&&#&&#@%@  %@%&@@@&& /:&%@ &   #                       \n"
       << "              %# %@ @%&##_@&# :% #&%&&@@&&@#@@                    \n"
       << "                @ %#_%%@=&@%@#&@@@&%&%@%&#/&@&                    \n"
       << "                 ~|/    %&###&&%#  %@/_&&###@&&&# & &		     \n"
       << "                  |    ~ @%&&@%& ___/=~__%##&&@&#&%#&#            \n"
       << "                  |__=|__#%&=~ &%%#@  ##&%%& @%#@/_#%%#           \n"
       << "                  ~        # _ @@#          %&%#_&##@%@@@%@@&@%   \n"
       << "                /        ## ##@%%%      #&@| //|_@@#%&@ #         \n"
       << "               ~          |&&&#           @ :/         &_%        \n"
       << "               :             =#@      # /      #&&&:#&#&          \n"
       << "               =             |          :            @%&&% %&     \n"
       << "               |             |    ___;_~~=       ##  #%#%         \n"
       << "               |            /|__        _;=|                      \n"
       << "               |;=           //               |                   \n"
       << "                ||||      //                |    ##    #@         \n"
       << "                    ||    /=             @ @&    ;=~ #%@&%        \n"
       << "                      ||/           #@ %& &:    #@%#_@@           \n"
       << "                      =/~|          %% &__@##%@#@#%#@#%@          \n"
       << "                      ||~           %%##|%#@@#%@#&%               \n"
       << "                      |||                &@& @#&@%&               \n"
       << "                      ;||               #@%@   # #&               \n"
       << "                       |||                  %                     \n"
       << "                       =||                                        \n"
       << "                       =:~                                        \n"
       << "           |_______.-./|;||.-._______/                            \n"
       << "            |         .            */                             \n"
       << "             |_____________________/                              \n"
       << std::endl;
	return (true);
}

std::ostream&	operator<<(std::ostream& out, ShrubberyCreationForm const& form)
{
	out << static_cast<AForm const&>(form) 
		<< "The form filename is " << form.getFileName();
	return (out);
}
