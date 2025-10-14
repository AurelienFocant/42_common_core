#include "Zombie.hpp"

#include <cstdlib>

int	main()
{
	Zombie	*z;

	Zombie	z("sra");

	z = newZombie("z1");
	z->announce();


	randomChump("z2");

	delete(z);

	return (EXIT_SUCCESS);
}
