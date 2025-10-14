#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>

int	main()
{
	ScavTrap	a;
	ScavTrap	b("Prat");
	FragTrap	c("Chris");

	FragTrap	e(c);
	a = b;
	ScavTrap	d(a);

	d.guardGate();
	e.highFivesGuys();

	c.attack(b.getName());
	d.attack(e.getName());


	return (0);
}
