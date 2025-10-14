#include "Fixed.hpp"

Fixed&			Fixed::min	( Fixed& f1, Fixed& f2)
{
	return (f1 < f2 ? f1 : f2);
}

const Fixed&	Fixed::min	( const Fixed& f1, const Fixed& f2 )
{
	return (f1 < f2 ? f1 : f2);
}

Fixed&			Fixed::max	( Fixed& f1, Fixed& f2 )
{
	return (f1 > f2 ? f1 : f2);
}

const Fixed&	Fixed::max	( const Fixed& f1, const Fixed& f2 )
{
	return (f1 > f2 ? f1 : f2);
}
