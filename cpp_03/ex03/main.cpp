#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	ClapTrap	test1("steve");
	ScavTrap	test2("romeo");
	FragTrap	test3("Dmitri");

	test1.attack("alex");
	test2.takeDamage(80);
	test2.beRepaired(10);
	test3.highFivesGuys();
	test1.beRepaired(20);
	test1.takeDamage(15);
	test2.attack("delta");
	test2.guardGate();
	return 0;
}
