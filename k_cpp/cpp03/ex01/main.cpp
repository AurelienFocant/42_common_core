#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

int	main()
{
	ScavTrap	a;
	ClapTrap	b("Prat");
	ClapTrap	c("Chris");
	ScavTrap	d;
	//
	ClapTrap	e(a);
	//
	// a.attack(b.getName());
	// std::cout << e.getName() << '\n';
	//
	// ScavTrap	f("Phil");

	ScavTrap f("Phil");

	ScavTrap	g(f);
	std::cout << g.getName() << '\n';


	a = g;
	a.guardGate();

	return (0);
}
