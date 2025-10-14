#ifndef __POINT_HPP__
#define __POINT_HPP__

#include "Fixed.hpp"

class Point
{

	public:
		Point	( void );
		Point	( float x, float y );
		Point	( const Point& src );
		~Point	( void );

		const Fixed & getX( void ) const;
		const Fixed & getY( void ) const;


	private:
		const Fixed	_x;
		const Fixed	_y;



};

#endif // __POINT_HPP__
