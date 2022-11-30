#include "ScavTrap.hpp"

void	getScavTrapStatus(ScavTrap const& src) {

	std::cout << "ScavTrap" << " [" << src.getClapTrapName() << "]";
	std::cout << ": ";
	std::cout << "HP => " << src.getClapTrapHP();
	std::cout << " EP => " << src.getClapTrapEP();
	std::cout << " AD => " << src.getClapTrapAD() << std::endl;
}

int	main(void) {
	ScavTrap	steve("Steve");
	ScavTrap	romeo("Romeo");

	getScavTrapStatus(steve);
	getScavTrapStatus(romeo);
	steve.attack(romeo.getClapTrapName());
	romeo.takeDamage(steve.getClapTrapAD());
	getScavTrapStatus(steve);
	getScavTrapStatus(romeo);
	steve.beRepaired(10);
	romeo.beRepaired(20);
	getScavTrapStatus(steve);
	getScavTrapStatus(romeo);
	romeo.takeDamage(150);
	romeo.takeDamage(10);
	romeo.attack(steve.getClapTrapName());
	steve.takeDamage(romeo.getClapTrapAD());
	steve.guardGate();
	romeo.guardGate();
	getScavTrapStatus(steve);
	getScavTrapStatus(romeo);
	return 0;
}
