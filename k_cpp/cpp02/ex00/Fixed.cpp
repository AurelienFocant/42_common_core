#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed( void ) : value(0)
{
	std::cout << "Fixed Object Constructed" << std::endl;
}

Fixed::Fixed( const Fixed& src ) :
	value(src.getRawBits())
{
	std::cout << "Fixed Object Constructed by Copy" << std::endl;
}

Fixed&	Fixed::operator=( const Fixed& rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &rhs) {
		this->value = rhs.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed( void )
{
	std::cout << "Fixed Object Destroyed" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits( int const raw )
{
	this->value = raw;
}

const int	Fixed::nbFractionnalBits = NB_BITS;
