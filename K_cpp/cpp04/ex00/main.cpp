#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int	main()
{
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete(i);
	delete(j);
	delete(meta);

	const WrongAnimal*	v = new WrongAnimal();
	const WrongAnimal*	w = new WrongCat();

	v->makeSound();
	w->makeSound();

	delete(v);
	delete(w);

	return (0);
}
