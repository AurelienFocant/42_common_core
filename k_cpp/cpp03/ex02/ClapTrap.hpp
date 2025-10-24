#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <string>

class ClapTrap
{

	public:
		ClapTrap	( void );
		ClapTrap	( const ClapTrap& src );
		ClapTrap&	operator=	( const ClapTrap& rhs );
		~ClapTrap	( void );

		ClapTrap	( std::string name );

		std::string	getName( void ) const;
		void		setName( std::string name );

		void	attack		( const std::string& target );
		void	takeDamage	( unsigned int amount );
		void	beRepaired	( unsigned int amount );

	private:
		std::string	_name;

	protected:
		int			_hitPts;
		int			_energyPts;
		int			_attackDmg;

		void	_announceIsDead( void );
		void	_announceOutOfEnergy( void );

};

#endif // __CLAPTRAP_HPP__
