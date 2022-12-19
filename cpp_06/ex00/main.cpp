#include "ScalarConvert.hpp"

int	main(int argc, char** argv) {
	if (argc == 2) {
		std::string	target = argv[1];

		try
		{
			ScalarConvert	convert(target);
			std::cout << "\n\n===Convert Scalar===" << std::endl;
			convert.printInputNType();
			std::cout << "\n\n" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "\n\n" << std::endl;
			std::cout << e.what() << std::endl;
		}
		return 0;
	}
	return 1;
}
