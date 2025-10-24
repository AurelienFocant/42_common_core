#include "Weapon.hpp"
#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(const std::string & name, const Weapon & weapon) :
	_name(name),
	_weapon(weapon)
{
	std::cout << getName() << " HumanA Object Constructed" << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << getName() << " HumanA Object Destroyed" << std::endl;
}

const std::string &	HumanA::getName(void) const
{
	return (this->_name);
}

void	HumanA::setName(std::string name)
{
	this->_name = name;
}

void	HumanA::attack(void) const
{
	std::cout << getName() << " attacks with " << getWeaponType() << std::endl;
}

std::string	HumanA::getWeaponType(void) const
{
	return (this->_weapon.getType());
}
