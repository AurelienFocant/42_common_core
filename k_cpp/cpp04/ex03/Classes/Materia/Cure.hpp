#ifndef __CURE_HPP__
#define __CURE_HPP__

#include "AMateria.hpp"

class Cure : public AMateria
{

	public:
		Cure	( void );
		Cure	( const Cure& src );
		Cure&	operator=	( const Cure& rhs );
		~Cure	( void );

		AMateria*	clone( void ) const;
		void		use( ICharacter& target );
};

#endif // __CURE_HPP__
