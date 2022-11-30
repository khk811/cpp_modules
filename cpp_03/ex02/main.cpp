#include "FragTrap.hpp"

void	getFragTrapStatus(FragTrap const& src) {

	std::cout << "FragTrap" << " [" << src.getClapTrapName() << "]";
	std::cout << ": ";
	std::cout << "HP => " << src.getClapTrapHP();
	std::cout << " EP => " << src.getClapTrapEP();
	std::cout << " AD => " << src.getClapTrapAD() << std::endl;
}

int	main(void) {
	FragTrap	steve("Steve");
	FragTrap	romeo("Romeo");

	getFragTrapStatus(steve);
	getFragTrapStatus(romeo);
	steve.attack(romeo.getClapTrapName());
	romeo.takeDamage(steve.getClapTrapAD());
	getFragTrapStatus(steve);
	getFragTrapStatus(romeo);
	romeo.beRepaired(20);
	romeo.takeDamage(140);
	romeo.highFivesGuys();
	romeo.attack(steve.getClapTrapName());
	steve.takeDamage(20);
	romeo.takeDamage(steve.getClapTrapAD());
	getFragTrapStatus(steve);
	getFragTrapStatus(romeo);
	return 0;
}
