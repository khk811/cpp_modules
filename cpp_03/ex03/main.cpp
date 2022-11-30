#include "DiamondTrap.hpp"

void	getDiamondTrapStatus(DiamondTrap const& src) {
	std::cout << "DiamondTrap" << " [" << src.getClapTrapName() << "]";
	std::cout << ": ";
	std::cout << "HP => " << src.getClapTrapHP();
	std::cout << " EP => " << src.getClapTrapEP();
	std::cout << " AD => " << src.getClapTrapAD() << std::endl;
}

int	main(void) {
	DiamondTrap	alexandra("Alexandra the mutant");
	DiamondTrap	test_dummy("Test dummy");


	getDiamondTrapStatus(alexandra);
	alexandra.attack(test_dummy.getClapTrapName());
	test_dummy.takeDamage(alexandra.getClapTrapAD());
	getDiamondTrapStatus(alexandra);
	getDiamondTrapStatus(test_dummy);
	alexandra.takeDamage(20);
	alexandra.beRepaired(30);
	alexandra.highFivesGuys();
	alexandra.guardGate();
	test_dummy.takeDamage(200);
	alexandra.whoAmI();
	test_dummy.whoAmI();
	getDiamondTrapStatus(alexandra);

	return 0;
}
