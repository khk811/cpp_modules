#include "Harl.hpp"

int	main(int argc, char **argv) {
	Harl	harlWhatever;
	if (argc == 2) {
		harlWhatever.complain(argv[1]);
	}
	else if (argc == 1) {
		harlWhatever.complain("default");
	}
	return (0);
}
