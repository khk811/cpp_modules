#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

const char*	ItemCannotFound::what() const throw() {
	return "Target item cannot found";
}

void	vectorSearchTest(void) {
	std::cout << "\n\n===easyfind() Test in std::vector===\n" << std::endl;
	try
	{
		std::cout << "\n---result: if the vector has the item---\n" << std::endl;
		std::vector<int>	int_vec;

		int_vec.push_back(10);
		int_vec.push_back(20);
		int_vec.push_back(30);
		int_vec.push_back(40);
		std::cout << "easyfind result: " << *(easyfind(int_vec, 40)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n" << std::endl;
	try
	{
		std::cout << "\n---result: if the vector doesn't have the item---\n" << std::endl;
		std::vector<int>	int_vec;

		int_vec.push_back(10);
		int_vec.push_back(20);
		int_vec.push_back(30);
		int_vec.push_back(40);
		std::cout << "easyfind result: " << *(easyfind(int_vec, 60)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n\n\n" << std::endl;
}

void	listSearchTest(void) {
	std::cout << "\n\n===easyfind() Test in std::list===\n" << std::endl;
	try
	{
		std::cout << "\n\n---result: if the list has the item---\n" << std::endl;
		std::list<int>	int_list;

		int_list.push_back(100);
		int_list.push_front(150);
		int_list.push_back(200);
		std::cout << "easyfind result: " << *(easyfind(int_list, 150)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n" << std::endl;
	try
	{
		std::cout << "\n\n---result: if the list doesn't have the item---\n" << std::endl;
		std::list<int>	int_list;

		int_list.push_back(100);
		int_list.push_front(150);
		int_list.push_back(200);
		std::cout << "easyfind result: " << *(easyfind(int_list, 42)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n\n\n" << std::endl;
}

void	dequeSearchTest(void) {
	std::cout << "\n\n===easyfind() Test in std::deque===\n" << std::endl;
	try
	{
		std::cout << "\n---result: if the deque doesn't have the item---\n" << std::endl;
		std::deque<int>	int_deque;

		int_deque.push_back(7);
		int_deque.push_front(13);
		int_deque.push_back(17);
		int_deque.push_front(19);
		std::cout << "easyfind result: " << *(easyfind(int_deque, 17)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n" << std::endl;
	try
	{
		std::cout << "\n---result: if the deque doesn't have the item---\n" << std::endl;
		std::deque<int>	int_deque;

		int_deque.push_back(7);
		int_deque.push_front(13);
		int_deque.push_back(17);
		int_deque.push_front(19);
		std::cout << "easyfind result: " << *(easyfind(int_deque, 27)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n\n\n" << std::endl;
}

// void	stringTest(void) { // Error Case: invalid argument to find();
// 	try
// 	{
// 		std::vector<std::string>	str_vec;

// 		str_vec.push_back("hello");
// 		str_vec.push_back("world");
// 		str_vec.push_back("item");
// 		std::cout << "easyfind result: " << *(easyfind(str_vec, 1)) << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// }

int	main(void) {
	vectorSearchTest();
	listSearchTest();
	dequeSearchTest();
	// stringTest();
	std::cout << "\n\n===Check Memory Leaks===\n" << std::endl;
	system("leaks a.out");
	return 0;
}
