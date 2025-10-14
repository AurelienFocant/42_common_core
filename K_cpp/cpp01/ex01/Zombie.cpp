#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie( void ) : _name("generic Zombie")
{
	std::cout << "default constructor called" << std::endl;
};

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Constructor called" << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << "Destructor called for " << this->getName() << std::endl;
}

void	Zombie::announce( void ) const
{
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName( void ) const
{
	return (this->_name);
}

void		Zombie::setName( std::string name )
{
	this->_name = name;
}
