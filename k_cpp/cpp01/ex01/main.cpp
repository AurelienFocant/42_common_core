#include "Zombie.hpp"

#include <cstdlib>

Zombie* zombieHorde( int N, std::string name );

int	main()
{
	Zombie	*horde;

	horde = zombieHorde( 10, "zombinou");

	for (int i = 0; i < 10; ++i)
		horde[i].announce();

	delete[] horde;
	return (EXIT_SUCCESS);
}
