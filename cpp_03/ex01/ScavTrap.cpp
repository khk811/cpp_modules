#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "Scavtrap whatever created duh" << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << "scav trap guard whatever" << std::endl;
}
