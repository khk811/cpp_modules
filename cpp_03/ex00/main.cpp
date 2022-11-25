#include "ClapTrap.hpp"

void	getStatus(ClapTrap const& src) {

	std::cout << std::endl;
	std::cout << src.getClapTrapName() << "'s current hit point is ";
	std::cout << src.getClapTrapHP() << std::endl;
	std::cout << src.getClapTrapName() << "'s current energy point is ";
	std::cout << src.getClapTrapEP() << std::endl;
	std::cout << src.getClapTrapName() << "'s current attack damage is ";
	std::cout << src.getClapTrapAD() << std::endl;
	std::cout << std::endl;
}

int	main(void) {
	ClapTrap	steve("Steve");
	ClapTrap	romeo("Romeo");
	ClapTrap	alex("Alex");

	steve.attack("Romeo");
	romeo.takeDamage(5);
	alex.takeDamage(100);
	getStatus(steve);
	getStatus(romeo);
	getStatus(alex);
	romeo.beRepaired(10);
	steve.beRepaired(20);
	steve.takeDamage(15);
	getStatus(steve);
	getStatus(romeo);
	getStatus(alex);
	return 0;
}
