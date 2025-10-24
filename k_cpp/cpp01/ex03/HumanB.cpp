#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(const std::string & name) :
	_name(name),
	_weapon(NULL)
{
	std::cout << getName() << " HumanB Object Constructed" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << getName() << " HumanB Object Destroyed" << std::endl;
}

const std::string &	HumanB::getName(void) const
{
	return (this->_name);
}

void	HumanB::setName(std::string name)
{
	this->_name = name;
}

void	HumanB::attack(void) const
{
	if (!(this->_weapon) || getWeaponType().empty())
		std::cout << this->getName() << " has no weapon, they can't attack" << std::endl;
	else
		std::cout << this->getName() << " attacks with " << getWeaponType() << std::endl;
}

std::string	HumanB::getWeaponType(void) const
{
	return (this->_weapon->getType());
}

void	HumanB::setWeapon(const Weapon & weapon)
{
	this->_weapon = &weapon;
}
