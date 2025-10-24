#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#include <iostream>

int	main()
{
	ScavTrap	scav1("Tom");
	ScavTrap	scav2(scav1);

	DiamondTrap	dia1("Marc");
	DiamondTrap dia2(dia1);

	DiamondTrap	diamond;
	diamond = dia1;

	diamond.guardGate();
	diamond.highFivesGuys();


	std::cout << scav1.getName() << '\n';
	std::cout << dia2.getName() << std::endl;
	std::cout << dia2.ClapTrap::getName() << std::endl;

	dia2.attack("plouf");

	ClapTrap	*ptr;
	ptr = &diamond;

	ptr->attack("plaf");
	diamond.whoAmI();


	return (0);
}
