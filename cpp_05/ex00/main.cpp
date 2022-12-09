#include "Bureaucrat.hpp"

void	basicTest(void){
	std::cout << "\n===Basic Test (Orthodox Canonique)===" << std::endl;
	// Default Constructor test;
	Bureaucrat			no_name;
	const Bureaucrat	alexandra("Alexandra", 24);
	// Copy Constructor test;
	std::cout << "\n---Copy Constructor Test---" << std::endl;
	Bureaucrat*			bettany = new Bureaucrat(alexandra);

	// Copy Assignment Operator test;
	std::cout << "\n---Copy Assignment Operator Test---" << std::endl;
	Bureaucrat			catherine("Catherine", 42);

	catherine = alexandra;

	std::cout << "" << std::endl;
	std::cout << "[ no_name: " << no_name << "]" << std::endl;
	std::cout << "[ alexandra: " << alexandra << "]" << std::endl;
	std::cout << "[ bettany: " << *(bettany) << "]" << std::endl;
	std::cout << "[ catherine: " << catherine << "]" << std::endl;
	std::cout << "" << std::endl;

	delete bettany;
}

void	instantiationTest(void) {
	std::cout << "\n===instantiation Test (Grade)===" << std::endl;
	Bureaucrat		valid_bureau_a("(valid_a)", 1);
	Bureaucrat		valid_bureau_b("(valid_b)", 150);

	std::cout << "\n---instantiation Test (valid)---" << std::endl;
	std::cout << "valid_bureau_a: " << valid_bureau_a << std::endl;
	std::cout << "valid_bureau_b: " << valid_bureau_b << std::endl;

	// init bureaucrat with impossible grade;

	// std::cout << "\n---instantiation Test (invalid)---" << std::endl;
	// Bureaucrat	invalid_bureau("(invalid)", 0);
	// Bureaucrat	invalid_bureau("(invalid)", 151);

}

void	gradeModificationTest(void) {
	std::cout << "\n===Grade Modification Test===" << std::endl;

	Bureaucrat	aaron("Aaron", 1);
	Bureaucrat	brian("Brian", 42);
	Bureaucrat	chris("Chris", 150);

	try
	{
		std::cout << "\n---increaseGrade() Test---" << std::endl;
		std::cout << brian << std::endl;
		brian.increaseGrade();
		std::cout << brian << std::endl;
		std::cout << aaron << std::endl;
		aaron.increaseGrade();
		std::cout << aaron << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "increaseGrade() Error: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n---decreaseGrade() Test---" << std::endl;
		std::cout << brian << std::endl;
		brian.decreaseGrade();
		std::cout << brian << std::endl;
		std::cout << chris << std::endl;
		chris.decreaseGrade();
		std::cout << chris << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "decreaseGrade() Error: " << e.what() << std::endl;
	}

}

int	main(void) {
	basicTest();
	instantiationTest();
	gradeModificationTest();
	std::cout << "\n===Check Memory Leaks===" << std::endl;
	system("leaks a.out");
	return 0;
}
