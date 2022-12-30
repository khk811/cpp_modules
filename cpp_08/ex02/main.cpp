#include "MutantStack.hpp"
#include <list>

void	subjectMutantStackTest(void) {
	std::cout << "\n\n===Test from subject pdf : MutantStack===\n" << std::endl;
	MutantStack<int> mstack;

	std::cout << "\n=> push(5) to MutantStack" << std::endl;
	mstack.push(5);
	std::cout << "\n=> push(17) to MutantStack" << std::endl;
	mstack.push(17);

	std::cout << "\n\n---top element of MutantStack---\n" << std::endl;
	std::cout << mstack.top() << std::endl;

	std::cout << "\n=> pop() to MutantStack" << std::endl;
	mstack.pop();

	std::cout << "\n\n---Size of MutantStack after pop()---\n" << std::endl;
	std::cout << mstack.size() << std::endl;

	std::cout << "\n=> push(3) to MutantStack" << std::endl;
	mstack.push(3);
	std::cout << "\n=> push(5) to MutantStack" << std::endl;
	mstack.push(5);
	std::cout << "\n=> push(737) to MutantStack" << std::endl;
	mstack.push(737);
	//[...]
	std::cout << "\n=> push(0) to MutantStack" << std::endl;
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	std::cout << "\n\n---print element from MutantStack---\n" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	std::cout << "\n\n---Extra: reverse print element from MutantStack---\n" << std::endl;
	for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend() ; it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << "\n\n" << std::endl;
}

void	subjectListTest(void) {
	std::cout << "\n\n===Test from subject pdf : std::list===\n" << std::endl;
	std::list<int>	test_list;

	std::cout << "\n=> push_back(5) to std::list" << std::endl;
	test_list.push_back(5);
	std::cout << "\n=> push_back(17) to std::list" << std::endl;
	test_list.push_back(17);

	std::cout << "\n\n---last(top) element from std::list---\n" << std::endl;
	std::cout << test_list.back() << std::endl;

	std::cout << "\n=> pop_back() to std::list" << std::endl;
	test_list.pop_back();

	std::cout << "\n\n---Size of std::list after pop_back()---\n" << std::endl;
	std::cout << test_list.size() << std::endl;

	std::cout << "\n=> push_back(3) to std::list" << std::endl;
	test_list.push_back(3);
	std::cout << "\n=> push_back(5) to std::list" << std::endl;
	test_list.push_back(5);
	std::cout << "\n=> push_back(737) to std::list" << std::endl;
	test_list.push_back(737);
	std::cout << "\n=> push_back(0) to std::list" << std::endl;
	test_list.push_back(0);

	std::list<int>::iterator	it = test_list.begin();
	std::list<int>::iterator 	ite = test_list.end();

	++it;
	--it;

	std::cout << "\n\n---print element from std::list---\n" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	extraTest(void) {
	std::cout << "\n\n===Extra Test: MutantStack with std::string===\n" << std::endl;
	MutantStack<std::string>	string_mutant_stack;

	string_mutant_stack.push("Hello");
	string_mutant_stack.push("World");
	string_mutant_stack.push("42 Seoul");

	std::cout << "\n\n---print element with const_iterator---\n" << std::endl;
	for (MutantStack<std::string>::const_iterator c_itr = string_mutant_stack.begin();\
	 c_itr != string_mutant_stack.end(); c_itr++)
	{
		std::cout << "=> " << *(c_itr) << std::endl;
	}
	std::cout << "\n\n---print element with const_reverse_iterator---\n" << std::endl;
	for (MutantStack<std::string>::const_reverse_iterator c_ritr = string_mutant_stack.rbegin();\
	 c_ritr != string_mutant_stack.rend(); c_ritr++)
	{
		std::cout << "=> " << *(c_ritr) << std::endl;
		// *(c_ritr) = "*"; // Error: method is not marked const
	}
	std::cout << "\n\n=> Modifying MutantStack elements with iterator: Elements change to '*'" << std::endl;
	for (MutantStack<std::string>::iterator itr = string_mutant_stack.begin();\
	 itr != string_mutant_stack.end(); itr++)
	{
		*(itr) = "*";
	}
	std::cout << "\n\n---print element reverse_iterator---\n" << std::endl;
	for (MutantStack<std::string>::reverse_iterator ritr = string_mutant_stack.rbegin();\
	 ritr != string_mutant_stack.rend(); ritr++)
	{
		std::cout << *(ritr) << std::endl;
	}
	std::cout << "\n\n" << std::endl;
}

int	main(void) {
	subjectMutantStackTest();
	subjectListTest();
	extraTest();
	std::cout << "\n\n===Check Memory Leaks===\n" << std::endl;
	system("leaks a.out");
	return 0;
}
