#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"

class Cat : public Animal
{

	public:
		Cat	( void );
		Cat	( const Cat& src );
		Cat&	operator=	( const Cat& rhs );
		~Cat	( void );

		void	makeSound ( void ) const;

};

#endif // __CAT_HPP__
