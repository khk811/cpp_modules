#include "Bureaucrat.hpp"
#include "Intern.hpp"

void	basicTest(void) {
	std::cout << "\n===Basic Test (Orthodox Canonique)===" << std::endl;
	const Intern	const_default_intern;
	std::cout << "\n---Copy Constructor Test---" << std::endl;
	Intern*			copy_construct_intern = new Intern(const_default_intern);

	std::cout << "\n---Copy Assignment Operator Test---" << std::endl;
	Intern			copy_assign_intern;

	copy_assign_intern = const_default_intern;
	delete copy_construct_intern;
}

void	makeFormTest(void) {
	Bureaucrat	agent_a("Agent_a", 1);
	Intern		intern_b;
	AForm*		the_form = NULL;

	std::cout << "\n===class Intern makeForm() Test===" << std::endl;
	try
	{
		std::cout << "\n---Try makeForm() with exist form type---" << std::endl;
		the_form = intern_b.makeForm("robotomy request", "Bender");
		agent_a.signForm(*the_form);
		agent_a.executeForm(*the_form);
		delete the_form;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n---Try makeForm() with non-exist form type---" << std::endl;
		the_form = intern_b.makeForm("waste disposal", "target_c");
		agent_a.signForm(*the_form);
		agent_a.executeForm(*the_form);
		delete the_form;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

int	main(void) {
	basicTest();
	makeFormTest();
	std::cout << "\n===Check Memory Leak===" << std::endl;
	system("leaks a.out");
	return 0;
}
