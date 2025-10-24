#ifndef __HUMANB_HPP__
#define __HUMANB_HPP__

#include "Weapon.hpp"

#include <string>

class HumanB
{

	public:
		HumanB(const std::string & name);
		~HumanB();

		const std::string & getName(void) const;
		void				setName(std::string name);

		void	attack(void) const;

		std::string	getWeaponType(void) const;
		void		setWeapon(const Weapon & weapon);

	private:
		std::string		_name;
		const Weapon	*_weapon;


};

#endif // __HUMANB_HPP__
