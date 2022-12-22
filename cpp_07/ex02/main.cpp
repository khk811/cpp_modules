#include "Array.hpp"

void	testClassTemplateArray(void) {
	std::cout << "\n\n\n===Class Template Array Test===" << std::endl;
	std::cout << "\n\n---Instantiate with Parametic constructor---" << std::endl;
	Array<int>		test(7);
	unsigned int	test_size = test.size();
	std::cout << "test array size: " << test_size << std::endl;

	try {
		std::cout << "\n\n---Instantiate with default constructor---" << std::endl;
		Array<int>		default_arr;

		std::cout << "default array size: " << default_arr.size() << std::endl;
		// std::cout << "default_arr[0]: " << default_arr[0] << std::endl; // error: index out of bound;

		std::cout << "\n\n---Use Copy Assignment Operator to Array---" << std::endl;
		default_arr = test;
		std::cout << "After copy => default array size: " << default_arr.size() << std::endl;
		std::cout << "default_arr[0]: " << default_arr[0] << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "\n\n---Print Array elements---" << std::endl;
		for (unsigned int i = 0; i < test_size; i++)
		{
			std::cout << i  <<": " << test[i] << std::endl;
		}
		std::cout << "\n\n=> Modify Array element: Using operaotor[]" << std::endl;
		test[1] = 42;
		test[3] = 119;
		test[4] = test[3];
		test[6] = 9;
		std::cout << "\n\n---After Mpdifying: Print Array elements---" << std::endl;
		for (unsigned int i = 0; i < test_size; i++)
		{
			std::cout << i  <<": " << test[i] << std::endl;
		}
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "\n\n---Access Array element with 'out of bound index'---" << std::endl;
		std::cout << "from index 100: " << test[100] << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

int	main(void) {
	testClassTemplateArray();
	std::cout << "\n\n===Check Memory Leak===" << std::endl;
	system("leaks a.out");
	return 0;
}
