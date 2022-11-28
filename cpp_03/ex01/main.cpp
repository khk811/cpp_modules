#include "ScavTrap.hpp"

void	getScavTrapStatus(ScavTrap const& src) {

	std::cout << "ScavTrap" << " [" << src.getClapTrapName() << "]";
	std::cout << ": ";
	std::cout << "HP => " << src.getClapTrapHP();
	std::cout << " EP => " << src.getClapTrapEP();
	std::cout << " AD => " << src.getClapTrapAD() << std::endl;
}

void	getClapTrapStatus(ClapTrap const& src) {

	std::cout << "ClapTrap" << " [" << src.getClapTrapName() << "]";
	std::cout << ": ";
	std::cout << "HP => " << src.getClapTrapHP();
	std::cout << " EP => " << src.getClapTrapEP();
	std::cout << " AD => " << src.getClapTrapAD() << std::endl;
}

int	main(void) {
	ClapTrap	steve("Steve");
	ScavTrap	romeo("Romeo");

	steve.attack(romeo.getClapTrapName());
	romeo.takeDamage(steve.getClapTrapAD());
	getClapTrapStatus(steve);
	getScavTrapStatus(romeo);
	steve.beRepaired(10);
	romeo.beRepaired(20);
	getClapTrapStatus(steve);
	getScavTrapStatus(romeo);
	romeo.takeDamage(15);
	romeo.attack(steve.getClapTrapName());
	steve.takeDamage(romeo.getClapTrapAD());
	romeo.guardGate();
	getClapTrapStatus(steve);
	getScavTrapStatus(romeo);
	return 0;
}
