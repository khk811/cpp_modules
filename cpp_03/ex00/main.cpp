#include "ClapTrap.hpp"

void	getClapTrapStatus(ClapTrap const& src) {

	std::cout << "ClapTrap" << " [" << src.getClapTrapName() << "]";
	std::cout << ": ";
	std::cout << "HP => " << src.getClapTrapHP();
	std::cout << " EP => " << src.getClapTrapEP();
	std::cout << " AD => " << src.getClapTrapAD() << std::endl;
}

int	main(void) {
	ClapTrap	steve("Steve");
	ClapTrap	romeo("Romeo");

	getClapTrapStatus(steve);
	getClapTrapStatus(romeo);
	steve.attack(romeo.getClapTrapName());
	romeo.takeDamage(steve.getClapTrapAD());
	getClapTrapStatus(steve);
	getClapTrapStatus(romeo);
	steve.takeDamage(15);
	romeo.beRepaired(10);
	steve.beRepaired(20);
	getClapTrapStatus(steve);
	getClapTrapStatus(romeo);
	return 0;
}
