#include "Point.hpp"

#include "Fixed.hpp"

#include <iostream>

Point::Point( void ) :
	_x(Fixed(0)),
	_y(Fixed(0))
{
	std::cout << "Point Object Constructed" << std::endl;
}

Point::Point( const float x, const float y) :
	_x(Fixed(x)),
	_y(Fixed(y))
{
	std::cout << "Point Object Constructed with x and y values" << std::endl;
}

Point::Point( const Point& src ) :
	_x(src._x),
	_y(src._y)
{
	std::cout << "Point Object Constructed by Copy" << std::endl;
}

Point::~Point( void )
{
	std::cout << "Point Object Destroyed" << std::endl;
}

const Fixed &	Point::getX( void ) const
{
	return (_x);
}

const Fixed	&	Point::getY( void ) const
{
	return (_y);
}

