#ifndef __DIAMONDTRAP_HPP__
#define __DIAMONDTRAP_HPP__

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{

	public:
		DiamondTrap	( void );
		DiamondTrap	( const DiamondTrap& src );
		DiamondTrap&	operator=	( const DiamondTrap& rhs );
		~DiamondTrap	( void );

		DiamondTrap	( std::string name );

		void	attack		( const std::string& target );	//override

		std::string	getName	( void ) const ;	//override
		void		whoAmI	( void ) const ;

	private:
		std::string	_name;

		void	_initDiamondTrapStats( void );


};

#endif // __DIAMONDTRAP_HPP__
