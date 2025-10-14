#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <string>

#define ABSTRACT 0

class Animal
{

	public:
		Animal	( void );
		Animal	( const Animal& src );
		Animal&	operator=	( const Animal& rhs );
		virtual ~Animal	( void );

		virtual void	makeSound( void ) const = ABSTRACT;

		std::string	getType( void ) const;

	protected:
		std::string	_type;

	private:


};

#endif // __ANIMAL_HPP__
