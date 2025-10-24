#include "Cat.hpp"

#include "Animal.hpp"

#include <iostream>

Cat::Cat( void ) : Animal(),
	_brain(new Brain)
{
	this->_type = "Cat";

	std::cout << "Cat Object Constructed" << std::endl;
}

Cat::Cat( const Cat& src ) : Animal(src)
{
	this->_brain = src._brain->deepCopyBrain();

	std::cout << "Cat Object Constructed by Copy" << std::endl;
}

Cat&	Cat::operator=( const Cat& rhs )
{
	if (this != &rhs) {
		this->Animal::operator=(rhs);
		if (this->_brain)
			delete(this->_brain);
		this->_brain = rhs._brain->deepCopyBrain();
	}

	std::cout << "Cat Object Copied by Assignment" << std::endl;
	return (*this);
}

Cat::~Cat( void )
{
	delete(this->_brain);
	this->_brain = NULL;

	std::cout << "Cat Object Destroyed" << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Miiaow" << std::endl;
}

unsigned int	Cat::setIdea( std::string idea )
{
	return (this->_brain->setIdea(idea));
}

void	Cat::purr( void )
{
	std::cout << "Puurrrrrrrrr" << std::endl;
}
