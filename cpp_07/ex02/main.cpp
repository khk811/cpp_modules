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
			std::cout << "index [" << i << "]: " << test[i] << std::endl;
		}
		std::cout << "\n\n=> Modify Array elements: Using operaotor[]" << std::endl;
		test[1] = 42;
		test[3] = 119;
		test[4] = test[3];
		test[6] = 9;
		std::cout << "\n\n---After Modifying: Print Array elements---" << std::endl;
		for (unsigned int i = 0; i < test_size; i++)
		{
			std::cout << "index [" << i << "]: " << test[i] << std::endl;
		}
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "\n\n---Access Array element with 'out of bound index'---" << std::endl;
		std::cout << "index[100]: " << test[100] << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n\n---Using operator[] in diffrent types of Array---" << std::endl;
		std::cout << "\n\n---Using operator[] in const Array<float>---" << std::endl;
		const Array<float>	const_float_arr(10);

		for (unsigned int i = 0; i < const_float_arr.size(); i++)
		{
			std::cout << "index [" << i << "]: " << const_float_arr[i] << std::endl;
		}

		std::cout << "\n\n---Using operator[] in Array<std::string>---" << std::endl;
		Array<std::string>	str_arr(3);
		for (unsigned int i = 0; i < str_arr.size(); i++)
		{
			std::cout << "index [" << i << "]: " << str_arr[i] << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main(void) {
	testClassTemplateArray();
	std::cout << "\n\n===Check Memory Leak===" << std::endl;
	system("leaks a.out");
	return 0;
}
