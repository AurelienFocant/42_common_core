#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

#define NB_BITS	8

class Fixed
{

	public:
		Fixed	( void );
		Fixed	( const Fixed& src );
		Fixed&	operator=	( const Fixed& rhs );
		~Fixed	( void );

		int getRawBits	( void )	const;
		void setRawBits	( int const raw );


		Fixed	( const int n );
		Fixed	( const float f );

		float	toFloat	( void ) const;
		int		toInt	( void ) const;



	private:
		int					_value;
		static const int	_nbFractionalBits;


};

std::ostream	&	operator<<	(std::ostream & os, const Fixed & src);

#endif // __FIXED_HPP__
