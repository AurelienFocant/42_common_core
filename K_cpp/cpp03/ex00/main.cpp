#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	a;
	ClapTrap	b("Prat");
	ClapTrap	c("Chris");

	a = c;

	a.attack(b.getName());
	return (0);
}
