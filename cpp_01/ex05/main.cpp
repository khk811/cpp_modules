#include "Harl.hpp"

int	main() {
	Harl	harl_whatever;

	harl_whatever.complain("ERROR");
	harl_whatever.complain("INFO");
	harl_whatever.complain("DEBUG");
	harl_whatever.complain("INFO");
	return (0);
}
