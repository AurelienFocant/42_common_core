#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>

#define NB_ANIMALS	10

int	main()
{
	{
		Animal	*animals[NB_ANIMALS];

		for (int i = 0; i < NB_ANIMALS; i++) {
			if (!(i % 2))
				animals[i] = new Cat();
			else
				animals[i] = new Dog();
		}

		for (int i = 0; i < NB_ANIMALS; i++) {
			animals[i]->makeSound();
			delete(animals[i]);
		}
	}

	{
		Cat	cat1;
		unsigned int i;

		i = cat1.setIdea("Purr");
		std::cout << i << std::endl;
		Cat		cat2(cat1);


		i = cat1.setIdea("Foooood");
		std::cout << i << std::endl;
		Cat	cat3;
		cat3 = cat1;


		Animal	*ani1;
		ani1 = &cat1;
		ani1->makeSound();
		// ani1->purr();

	}
	{
		// Animal	test;
	}

	return (0);
}
