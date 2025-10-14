#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{

	public:
		Dog	( void );
		Dog	( const Dog& src );
		Dog&	operator=	( const Dog& rhs );
		~Dog	( void );

		void	makeSound ( void ) const;
		unsigned int	setIdea( std::string idea );

	private:
		Brain*	_brain;

};

#endif // __DOG_HPP__
