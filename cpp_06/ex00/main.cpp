#include "ScalarConvert.hpp"

int	main(int argc, char** argv) {
	if (argc == 2) {
		std::string	target = argv[1];

		try
		{
			ScalarConvert	convert(target);
			std::cout << "\n" << std::endl;
			convert.printInputNType();
			std::cout << "\n" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "\n" << std::endl;
			std::cout << e.what() << std::endl;
		}
		// system("leaks convert");
		return 0;
	}
	return 1;
}
