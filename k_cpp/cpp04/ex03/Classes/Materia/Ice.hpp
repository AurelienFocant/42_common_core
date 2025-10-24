#ifndef __ICE_HPP__
#define __ICE_HPP__

#include "AMateria.hpp"

class Ice : public AMateria
{

	public:
		Ice	( void );
		Ice	( const Ice& src );
		Ice&	operator=	( const Ice& rhs );
		~Ice	( void );

		AMateria*	clone( void ) const;
		void		use( ICharacter& target );
};

#endif // __ICE_HPP__
