#include "Harl.hpp"

int	main(int argc, char **argv) {
	Harl		harl_whatever;
	std::string	level;

	if (argc == 2) {
		level = argv[1];
		harl_whatever.complain(level);
	}
	return (0);
}
