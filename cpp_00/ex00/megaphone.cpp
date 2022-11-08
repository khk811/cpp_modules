#include <iostream>

int	main(int argc, char **argv){
	std::string	result;
	if (argc >= 2){
		for (int i = 1; i < argc; i++){
			std::string	str(argv[i]);
			for (size_t j = 0; j < str.length(); j++){
				result += std::toupper(str[j]);
			}
		}
	}
	else{
		result = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	std::cout << result << std::endl;
	return (0);
}
