#include "BSPNode.hpp"

#include "Fixed.hpp"
#include "Point.hpp"

#include <iostream>

BSPNode::BSPNode( void ) :
	_a(Point(0, 0)),
	_b(Point(0, 0))
{
	std::cout << "BSPNode Object Constructed" << std::endl;
}

BSPNode::BSPNode( const BSPNode& src ) :
	_a(src.getPointA()),
	_b(src.getPointB())
{
	std::cout << "BSPNode Object Constructed by Copy" << std::endl;
}

BSPNode::~BSPNode( void )
{
	std::cout << "BSPNode Object Destroyed" << std::endl;
}

BSPNode::BSPNode ( const Point & a, const Point & b ) :
	_a(a),
	_b(b)
{
}

Point	BSPNode::getPointA( void ) const
{
	return (_a);
}

Point	BSPNode::getPointB( void ) const
{
	return (_b);
}

const Fixed	BSPNode::crossProduct( const Point & p ) const
{
	Fixed	res;

	res = (_b.getX() - _a.getX()) * (p.getY() - _a.getY()) - (_b.getY() - _a.getY()) * (p.getX() - _a.getX());
	return (res);
}
