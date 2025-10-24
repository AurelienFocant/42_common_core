#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{

	public:
		Cat	( void );
		Cat	( const Cat& src );
		Cat&	operator=	( const Cat& rhs );
		~Cat	( void );

		void	makeSound ( void ) const;

		unsigned int	setIdea( std::string idea );
		void	purr( void );

	private:
		Brain*	_brain;

};

#endif // __CAT_HPP__
