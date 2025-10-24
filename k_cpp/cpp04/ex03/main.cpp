#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Floor.hpp"

#include <iostream>

int	main()
{
	IMateriaSource* src = new MateriaSource();


	AMateria*	ptr = new Ice;
	src->learnMateria(ptr);
	delete ptr;

	ptr = new Ice();
	src->learnMateria(ptr);
	delete ptr;

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");

	me->equip(tmp);
	tmp = src->createMateria("cure");

	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(0);

	Floor::getInstance().cleanFloor();

	delete bob;
	delete me;
	delete src;
	return (0);
}
