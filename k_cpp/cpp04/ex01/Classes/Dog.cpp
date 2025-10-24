#include "Dog.hpp"

#include "Animal.hpp"

#include <iostream>

Dog::Dog( void ) : Animal(),
	_brain(new Brain)
{
	this->_type = "Dog";

	std::cout << "Dog Object Constructed" << std::endl;
}

Dog::Dog( const Dog& src ) : Animal(src)
{
	this->_brain = src._brain->deepCopyBrain();

	std::cout << "Dog Object Constructed by Copy" << std::endl;
}

Dog&	Dog::operator=( const Dog& rhs )
{
	if (this != &rhs) {
		this->Animal::operator=(rhs);
		if (this->_brain)
			delete(this->_brain);
		this->_brain = rhs._brain->deepCopyBrain();
	}

	std::cout << "Dog Object Copied by Assignment" << std::endl;
	return (*this);
}

Dog::~Dog( void )
{
	delete _brain;
	_brain = NULL;

	std::cout << "Dog Object Destroyed" << std::endl;
}

unsigned int	Dog::setIdea( std::string idea )
{
	return (this->_brain->setIdea(idea));
}


void	Dog::makeSound( void ) const
{
	std::cout << "Woof" << std::endl;
}
