#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

	public:
		PresidentialPardonForm	( void );
		PresidentialPardonForm	( const std::string target );

		PresidentialPardonForm	( const PresidentialPardonForm& src );
		PresidentialPardonForm&	operator=	( const PresidentialPardonForm& rhs );

		~PresidentialPardonForm	( void );


	private:
		virtual bool _formExecution( void ) const; //override


};

#endif // PRESIDENTIALPARDONFORM_HPP
