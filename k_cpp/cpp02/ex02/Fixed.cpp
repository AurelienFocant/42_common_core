#include "Fixed.hpp"

#include <iostream>
#include <cmath>

Fixed::Fixed( void ) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& src ) :
	_value(src.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed&	Fixed::operator=( const Fixed& rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &rhs) {
		this->_value = rhs.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}


Fixed::Fixed	( const int n )
{
	std::cout << "Int constructor called" << std::endl;

	int	raw;

	raw = n;
	raw <<= _nbFractionalBits;
	this->setRawBits(raw);
}

Fixed::Fixed	( const float f )
{
	std::cout << "Float constructor called" << std::endl;

	int		intPart;
	float	fracPart;
	int		raw;

	intPart = static_cast<int> (f);
	fracPart = f - intPart;
	raw = intPart << _nbFractionalBits;
	raw += round(fracPart * (1 << _nbFractionalBits));
	this->setRawBits(raw);
}

int	Fixed::toInt( void ) const
{
	return (this->getRawBits() >> _nbFractionalBits);
}

float	Fixed::toFloat( void ) const
{
	int		mask;
	float	f;

	mask = (1 << _nbFractionalBits) - 1;
	f = this->getRawBits() >> _nbFractionalBits;
	f += (mask & this->getRawBits()) / static_cast<float> (1 << _nbFractionalBits);
	return (f);
}


std::ostream	&	operator<<	(std::ostream & os, const Fixed & src)
{
	os << src.toFloat();
	return (os);
}

const int	Fixed::_nbFractionalBits = NB_BITS;
