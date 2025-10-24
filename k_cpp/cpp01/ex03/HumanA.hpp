#ifndef __HUMANA_HPP__
#define __HUMANA_HPP__

#include "Weapon.hpp"

#include <string>

class HumanA
{
	public:
		HumanA();
		HumanA(const std::string & name, const Weapon & weapon);
		~HumanA();

		const std::string & getName(void) const;
		void				setName(std::string name);

		void	attack(void) const;

		std::string	getWeaponType(void) const;

	private:
		std::string		_name;
		const Weapon &	_weapon;
};

#endif // __HUMANA_HPP__
