#include "Floor.hpp"

#include "AMateria.hpp"

#include <iostream>

#define MAX_FLOORED	100

Floor::Floor( void )
{
	std::cout << "Floor Object Constructed" << std::endl;
}

Floor::Floor( const Floor& src )
{
	std::cout << "Floor Object Constructed by Copy" << std::endl;
	(void) src;
}

Floor&	Floor::operator=( const Floor& rhs )
{
	std::cout << "Floor Object Copied by Assignment" << std::endl;
	(void) rhs;
	return (*this);
}

Floor::~Floor( void )
{
	std::cout << "Floor Object Destroyed" << std::endl;
}

Floor&	Floor::getInstance( void )
{
	static Floor	f;

	return (f);
}

bool	Floor::dropToFloor( AMateria* m )
{
	for (int i = 0; i < MAX_FLOORED; ++i) {
		if (!_floor[i]) {
			_floor[i] = m;
			return (true);
		}
	}
	return (false);
}

void	Floor::cleanFloor( void )
{
	for (int i = 0; i < MAX_FLOORED; ++i) {
		if (_floor[i]) {
			delete _floor[i];
			_floor[i] = NULL;
		}
	}
}
