#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

	public:
		ScavTrap	( void );
		ScavTrap	( const ScavTrap& src );
		ScavTrap&	operator=	( const ScavTrap& rhs );
		~ScavTrap	( void );

		ScavTrap	( std::string name );

		void	attack		( const std::string& target );
		void	guardGate	( void );


	private:
		void	_initScavTrapStats( void );

};

#endif // __SCAVTRAP_HPP__
