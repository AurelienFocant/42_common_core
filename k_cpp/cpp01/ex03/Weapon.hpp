#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <string>

class Weapon
{

	public:
		Weapon();
		Weapon( std::string type );
		~Weapon();

		void				setType( std::string type );
		std::string	const & getType( void ) const;


	private:
		std::string	_type;


};

#endif // __WEAPON_HPP__
