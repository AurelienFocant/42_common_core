#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <string>

class Zombie
{

	public:
		Zombie( void );
		Zombie( std::string name );
		~Zombie( void );

		void	announce( void ) const;
		void	announce(int n) const;

		std::string	getName( void ) const;
		void	setName( std::string a );


	private:
		std::string	_name;


};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name);


#endif // __ZOMBIE_HPP__
