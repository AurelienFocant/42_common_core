#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{

	public:
		RobotomyRequestForm	( void );
		RobotomyRequestForm	( const std::string target );

		RobotomyRequestForm	( const RobotomyRequestForm& src );
		RobotomyRequestForm&	operator=	( const RobotomyRequestForm& rhs );

		~RobotomyRequestForm	( void );


	private:
		virtual bool _formExecution( void ) const; //override


};

#endif // ROBOTOMYREQUESTFORM_HPP
