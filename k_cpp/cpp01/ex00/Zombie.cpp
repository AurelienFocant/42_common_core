#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Constructor called" << std::endl;

	this->_name = name;
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
