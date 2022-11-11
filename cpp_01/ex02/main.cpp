#include <iostream>

int	main(void) {
	std::string	the_statement = "HI THIS IS BRAIN";
	std::string*	stringPTR = &(the_statement);
	std::string&	stringREF = the_statement;

	std::cout << &(the_statement) << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &(stringREF) << std::endl;

	std::cout << the_statement << std::endl;
	std::cout << *(stringPTR) << std::endl;
	std::cout << stringREF << std::endl;
	return 0;
}
