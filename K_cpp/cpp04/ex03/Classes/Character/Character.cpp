#include "Character.hpp"
#include "Floor.hpp"

#include "AMateria.hpp"

#include <iostream>

Character::Character( void )
{
	std::cout << "Character Object Constructed" << std::endl;

	_name = "default_name";
	_setEmptyInventory();
}

Character::Character( const Character& src )
{
	std::cout << "Character Object Constructed by Copy" << std::endl;

	_name = src._name;
	_copyInventory(src);
}

Character&	Character::operator=( const Character& rhs )
{
	std::cout << "Character Object Copied by Assignment" << std::endl;

	if (this != &rhs) {
		_name = rhs._name;
		_deleteInventory();
		_copyInventory(rhs);
	}
	return (*this);
}

Character::~Character( void )
{
	std::cout << "Character Object Destroyed" << std::endl;

	_deleteInventory();
}

Character::Character( std::string const & name)
{
	std::cout
		<< name << " Character Object Constructed"
		<< std::endl;

	_name = name;
	_setEmptyInventory();
}


std::string	const &	Character::getName() const
{
	return (_name);
}


void	Character::equip( AMateria* m )
{
	if (!m) return ;

	for (int i = 0; i < MAX_INVENTORY; ++i) {
		if (_inventory[i] == m) return ;

		if (! _inventory[i]) {
			_inventory[i] = m;
			return ;
		}
	}

	return ;
}

void	Character::unequip( int idx )
{
	if (idx < 0 || idx >= MAX_INVENTORY)	return ;
	if (!_inventory[idx])					return ;

	if (!Floor::getInstance().dropToFloor(_inventory[idx]))
		delete (_inventory[idx]);
	_inventory[idx] = NULL;
}

void	Character::use( int idx, ICharacter& target )
{
	if (idx < 0 || idx >= MAX_INVENTORY)	return ;
	if (!_inventory[idx])					return ;

	_inventory[idx]->use(target);
}


void	Character::_setEmptyInventory( void )
{
	for (int i = 0; i < MAX_INVENTORY; ++i) {
		_inventory[i] = NULL;
	}
}

void	Character::_deleteInventory( void )
{
	for (int i = 0; i < MAX_INVENTORY; ++i) {
		if (_inventory[i]) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}

void	Character::_copyInventory( const Character& src )
{
	for (int i = 0; i < MAX_INVENTORY; ++i) {
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
	}
}
