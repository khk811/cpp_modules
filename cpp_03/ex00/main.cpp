#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	test1("steve");
	ClapTrap	test2("romeo");

	test1.attack("alex");
	test2.takeDamage(5);
	std::cout << test2.getClapTrapHP() << std::endl;
	test2.beRepaired(10);
	test1.beRepaired(20);
	test1.takeDamage(15);
	return 0;
}
