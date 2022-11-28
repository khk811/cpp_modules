#include "ScavTrap.hpp"

int	main(void) {
	ClapTrap	steve("Steve");
	ScavTrap	romeo("Romeo");

	steve.attack(romeo.getClapTrapName());
	romeo.takeDamage(steve.getClapTrapAD());
	steve.beRepaired(10);
	romeo.beRepaired(20);
	romeo.takeDamage(15);
	romeo.attack(steve.getClapTrapName());
	steve.takeDamage(romeo.getClapTrapAD());
	romeo.guardGate();
	return 0;
}
