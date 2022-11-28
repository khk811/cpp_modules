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
	ClapTrap	alex("Alex");

	steve.attack("Romeo");
	romeo.takeDamage(5);
	alex.takeDamage(100);
	getClapTrapStatus(steve);
	getClapTrapStatus(romeo);
	getClapTrapStatus(alex);
	romeo.beRepaired(10);
	steve.beRepaired(20);
	alex.beRepaired(30);
	steve.takeDamage(15);
	alex.takeDamage(10);
	getClapTrapStatus(steve);
	getClapTrapStatus(romeo);
	getClapTrapStatus(alex);
	return 0;
}
