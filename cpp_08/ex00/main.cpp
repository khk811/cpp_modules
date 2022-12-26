#include "easyfind.hpp"
#include <vector>
#include <list>
#include <set>

const char*	ItemCannotFound::what() const throw() {
	return "Target item cannot found";
}

void	test(void) {
	try
	{
		std::vector<int>	int_vec;

		int_vec.push_back(10);
		int_vec.push_back(20);
		int_vec.push_back(30);
		int_vec.push_back(40);
		std::cout << "easyfind result: " << easyfind(int_vec, 60) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::list<int>	int_list;

		int_list.push_back(100);
		int_list.push_back(150);
		int_list.push_back(200);
		std::cout << "easyfind result: " << easyfind(int_list, 150) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

// void	stringTest(void) {
// 	try
// 	{
// 		std::vector<std::string>	str_vec;

// 		str_vec.push_back("hello");
// 		str_vec.push_back("world");
// 		str_vec.push_back("item");
// 		std::cout << "easyfind result: " << easyfind(str_vec, "hello") << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// }

int	main(void) {
	test();
	// stringTest();
	return 0;
}
