#include "ScalarConvert.hpp"

int	main(int argc, char** argv) {
	if (argc == 2) {
		std::string	target = argv[1];

		try
		{
			ScalarConvert	convert(target);
			convert.printInputNType();
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		return 0;
	}
	return 1;
}
