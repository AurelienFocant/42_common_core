#ifndef __BSPNODE_HPP__
#define __BSPNODE_HPP__

#include "Point.hpp"

class BSPNode
{

	public:
		BSPNode	( void );
		BSPNode	( const BSPNode& src );
		~BSPNode	( void );

		BSPNode ( const Point & a, const Point & b);
		Point	getPointA( void ) const;
		Point	getPointB( void ) const;

		const Fixed	crossProduct( const Point & p ) const;



	private:
		Point	_a;
		Point	_b;



};

#endif // __BSPNODE_HPP__
