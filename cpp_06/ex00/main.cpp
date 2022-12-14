#include "Convert.hpp"

int	main(int argc, char **argv) {

	if (argc != 2) {
		return 1;
	}
	else {
		Convert	target(argv[1]);

		return 0;
	}
}
