#include "Harl.hpp"

int	main(int argc, char **argv) {
	Harl	harl_whatever;

	if (argc == 1) {
		harl_whatever.complain("default");
	}
	else if (argc == 2) {
		harl_whatever.complain(argv[1]);
	}
	return (0);
}
