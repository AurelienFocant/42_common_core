#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__

#include <string>

class WrongAnimal
{

	public:
		WrongAnimal	( void );
		WrongAnimal	( const WrongAnimal& src );
		WrongAnimal&	operator=	( const WrongAnimal& rhs );
		virtual ~WrongAnimal	( void );

		void	makeSound( void ) const;

		std::string	getType( void ) const;

	protected:
		std::string	_type;

	private:


};

#endif // __WRONGANIMAL_HPP__
