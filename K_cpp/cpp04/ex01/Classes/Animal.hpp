#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <string>

class Animal
{

	public:
		Animal	( void );
		Animal	( const Animal& src );
		Animal&	operator=	( const Animal& rhs );
		virtual ~Animal	( void );

		virtual void	makeSound( void ) const;

		std::string	getType( void ) const;

	protected:
		std::string	_type;

	private:


};

#endif // __ANIMAL_HPP__
