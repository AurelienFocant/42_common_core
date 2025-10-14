#include "MateriaSource.hpp"

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include <iostream>

MateriaSource::MateriaSource( void )
{
	std::cout << "MateriaSource Object Constructed" << std::endl;

	_setEmptyStore();
}

MateriaSource::MateriaSource( const MateriaSource& src )
{
	std::cout << "MateriaSource Object Constructed by Copy" << std::endl;

	_copyStore(src);
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& rhs )
{
	std::cout << "MateriaSource Object Copied by Assignment" << std::endl;

	if (this != &rhs) {
		_copyStore(rhs);
	}
	return (*this);
}

MateriaSource::~MateriaSource( void )
{
	std::cout << "MateriaSource Object Destroyed" << std::endl;

	_deleteStore();
}

void	MateriaSource::learnMateria( AMateria* m )
{
	for (int i = 0; i < MAX_SOURCES; ++i) {
		if (!_store[i]) {
			_store[i] = m->clone();
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria( const std::string &type)
{
	for (int i = 0; i < MAX_SOURCES; ++i) {
		if (_store[i] && _store[i]->getType() == type)
			return (_store[i]->clone());
	}
	return (NULL);
}

void	MateriaSource::_setEmptyStore( void )
{
	for (int i = 0; i < MAX_SOURCES; ++i) {
		_store[i] = NULL;
	}
}

void	MateriaSource::_deleteStore( void )
{
	for (int i = 0; i < MAX_SOURCES; ++i) {
		if (_store[i])
			delete _store[i];
	}
}

void	MateriaSource::_copyStore( const MateriaSource& src )
{
	for (int i = 0; i < MAX_SOURCES; ++i) {
		if (src._store[i])
			_store[i] = src._store[i]->clone();
	}
}
