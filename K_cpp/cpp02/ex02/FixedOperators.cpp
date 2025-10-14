#include "Fixed.hpp"

bool	Fixed::operator>	( const Fixed & rhs ) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<	( const Fixed & rhs ) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=	( const Fixed & rhs ) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=	( const Fixed & rhs ) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==	( const Fixed & rhs ) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=	( const Fixed & rhs ) const
{
	return (this->getRawBits() != rhs.getRawBits());
}


Fixed	Fixed::operator+	( const Fixed & rhs ) const
{
	Fixed	res;

	res.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (res);
}

Fixed	Fixed::operator-	( const Fixed & rhs ) const
{
	Fixed	res(this->toFloat() - rhs.toFloat());

	return (res);
}

Fixed	Fixed::operator*	( const Fixed & rhs ) const
{
	Fixed	res(this->toFloat() * rhs.toFloat());

	return (res);
}

Fixed	Fixed::operator/	( const Fixed & rhs ) const
{
	Fixed	res;

	res.setRawBits(this->getRawBits() / rhs.getRawBits());
	return (res);
}


Fixed&	Fixed::operator++	( void )
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++	( int )
{
	Fixed	res;

	res = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (res);
}

Fixed&	Fixed::operator--	( void )
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--	( int )
{
	Fixed	res;

	res = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (res);
}
