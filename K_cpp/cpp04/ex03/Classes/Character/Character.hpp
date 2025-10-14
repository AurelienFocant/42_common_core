#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include "ICharacter.hpp"

#include <string>

#define MAX_INVENTORY 4

class AMateria;

class Character : public ICharacter
{

	public:
		Character	( void );
		Character	( const Character& src );
		Character&	operator=	( const Character& rhs );
		~Character	( void );
		Character	( std::string const & name);

		std::string const & getName() const;

		void	equip	( AMateria* m );					// override 
		void	unequip	( int idx );						// override	
		void	use		( int idx, ICharacter& target );	// override


	private:
		std::string	_name;
		AMateria	*_inventory[MAX_INVENTORY];


		void	_setEmptyInventory( void );
		void	_deleteInventory( void );
		void	_copyInventory( const Character& src );


};

#endif // __CHARACTER_HPP__
