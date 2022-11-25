#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void) {
	DiamondTrap	test4("Alexandra the mutant");


	std::cout << std::endl;

	std::cout << test4.getClapTrapName() << std::endl;
	std::cout << test4.getClapTrapHP() << std::endl;
	std::cout << test4.getClapTrapEP() << std::endl;
	std::cout << test4.getClapTrapAD() << std::endl;
	test4.attack("Romeo");
	std::cout << std::endl;
	test4.takeDamage(20);
	std::cout << std::endl;
	test4.beRepaired(30);
	std::cout << std::endl;
	test4.highFivesGuys();
	std::cout << std::endl;
	test4.guardGate();
	std::cout << std::endl;

	return 0;
}
