#include "Brain.hpp"

#include <iostream>
#include <string>

Brain::Brain( void ) : 
	_ideaIndex(0)
{
	std::cout << "Brain Object Constructed" << std::endl;
}

Brain::Brain( const Brain& src )
{
	std::cout << "Brain Object Constructed by Copy" << std::endl;

	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = src._ideas[i];
	}
	this->_ideaIndex = src._ideaIndex;
}

Brain&	Brain::operator=( const Brain& rhs )
{
	std::cout << "Brain Object Copied by Assignment" << std::endl;

	if (this != &rhs) {
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = rhs._ideas[i];
		}
	}
	this->_ideaIndex = rhs._ideaIndex;
	return (*this);
}

Brain::~Brain( void )
{
	std::cout << "Brain Object Destroyed" << std::endl;
}

Brain*	Brain::deepCopyBrain( void ) const
{
	return (new Brain(*this));
}

unsigned int	Brain::setIdea( const std::string & idea )
{
	this->_ideaIndex %= 100;
	this->_ideas[this->_ideaIndex] = idea;
	return (this->_ideaIndex++);
}

std::string	Brain::getIdea( unsigned int i ) const
{
	if (i > 99)
		return (std::string());
	return (this->_ideas[i]);
}
