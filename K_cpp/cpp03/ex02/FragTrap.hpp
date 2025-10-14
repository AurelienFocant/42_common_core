#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

#include <iostream>

class FragTrap : public ClapTrap
{

	public:
		FragTrap	( void );
		FragTrap	( const FragTrap& src );
		FragTrap&	operator=	( const FragTrap& rhs );
		~FragTrap	( void );

		FragTrap	( std::string name );

		void	attack		( const std::string& target );
		void	highFivesGuys( void );

	private:
		void	_initFragTrapStats( void );



};

#endif // __FRAGTRAP_HPP__
