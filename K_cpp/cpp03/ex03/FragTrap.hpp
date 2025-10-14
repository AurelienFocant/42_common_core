#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

#include <string>

class FragTrap : virtual public ClapTrap
{

	public:
		FragTrap	( void );
		FragTrap	( const FragTrap& src );
		FragTrap&	operator=	( const FragTrap& rhs );
		~FragTrap	( void );

		FragTrap	( std::string name );

		void	attack		( const std::string& target );	//override
		void	highFivesGuys( void );

	private:
		void	_initFragTrapStats( void );



};

#endif // __FRAGTRAP_HPP__
