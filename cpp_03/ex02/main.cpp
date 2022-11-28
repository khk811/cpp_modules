#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void	getFragTrapStatus(FragTrap const& src) {

	std::cout << "FragTrap" << " [" << src.getClapTrapName() << "]";
	std::cout << ": ";
	std::cout << "HP => " << src.getClapTrapHP();
	std::cout << " EP => " << src.getClapTrapEP();
	std::cout << " AD => " << src.getClapTrapAD() << std::endl;
}

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
	FragTrap	alex("Alex");

	steve.attack(alex.getClapTrapName());
	alex.takeDamage(steve.getClapTrapAD());
	romeo.attack(alex.getClapTrapName());
	alex.takeDamage(romeo.getClapTrapAD());
	getClapTrapStatus(steve);
	getScavTrapStatus(romeo);
	getFragTrapStatus(alex);
	alex.beRepaired(20);
	alex.highFivesGuys();
	alex.attack(steve.getClapTrapName());
	steve.takeDamage(alex.getClapTrapAD());
	alex.attack(romeo.getClapTrapName());
	romeo.takeDamage(alex.getClapTrapAD());
	getClapTrapStatus(steve);
	getScavTrapStatus(romeo);
	getFragTrapStatus(alex);
	return 0;
}
