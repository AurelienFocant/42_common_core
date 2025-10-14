#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#define NB_BITS	8

class Fixed
{

	public:
		Fixed	( void );
		Fixed	( const Fixed& src );
		~Fixed	( void );
		Fixed&	operator=	( const Fixed& rhs );

		int getRawBits( void ) const;
		void setRawBits( int const raw );


	private:
		int					value;
		static const int	nbFractionnalBits;


};

#endif // __FIXED_HPP__
