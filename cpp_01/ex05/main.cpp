#include "Harl.hpp"

int	main() {
	Harl	harl_whatever;

	harl_whatever.complain("error");
	harl_whatever.complain("info");
	harl_whatever.complain("debug");
	harl_whatever.complain("info");
	return (0);
}
