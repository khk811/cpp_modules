#include "Bureaucrat.hpp"
#include "Form.hpp"

void	basicTest(void){
	std::cout << "\n===Basic Test (Orthodox Canonique)===" << std::endl;
	// Default Constructor test;
	Form				untitled;
	const Form			immigrant("Immigrant form", 42, 24);
	// Copy Constructor test;
	std::cout << "\n---Copy Constructor Test---" << std::endl;
	Form*				waste_disposal = new Form(immigrant);

	// Copy Assignment Operator test;
	std::cout << "\n---Copy Assignment Operator Test---" << std::endl;
	Form				tax_return("tax_return", 142, 124);

	tax_return = immigrant;

	std::cout << "" << std::endl;
	std::cout << "[ untitled: " << untitled << "]" << std::endl;
	std::cout << "[ immigrant: " << immigrant << "]" << std::endl;
	std::cout << "[ waste_disposal: " << *(waste_disposal) << "]" << std::endl;
	std::cout << "[ tax_return: " << tax_return << "]" << std::endl;
	std::cout << "" << std::endl;

	delete waste_disposal;
}

void	instantiationTest(void) {
	std::cout << "\n===instantiation Test (sign_grade, exec_grade)===" << std::endl;
	Form		valid_form_a("(valid_a)", 1, 150);
	Form		valid_form_b("(valid_b)", 150, 1);

	std::cout << "\n---instantiation Test (valid)---" << std::endl;
	std::cout << "valid_form_a: " << valid_form_a << std::endl;
	std::cout << "valid_form_b: " << valid_form_b << std::endl;

	// init Form with impossible grade;

	// std::cout << "\n---instantiation Test (invalid)---" << std::endl;
	// Form	invalid_form("(invalid)", 0, 75);
	// Form	invalid_form("(invalid)", 75, 0);
	// Form	invalid_form("(invalid)", 151, 75);
	// Form	invalid_form("(invalid)", 75, 151);

}

void	beSignedTest(void) {
	std::cout << "\n===beSigned() Test===" << std::endl;
	Bureaucrat	alexandra("Alexandra", 42);
	Form		atomic_bomb("Fire atomic bomb form", 1, 1);
	Form		breathing_allow("breathing allow form", 124, 142);

	try
	{
		std::cout << "\n---beSigned() : breathing_allow---" << std::endl;
		std::cout << breathing_allow << std::endl;
		breathing_allow.beSigned(alexandra);
		std::cout << "=>" << breathing_allow << std::endl;
		std::cout << "\n---beSigned() : atomic_bomb---" << std::endl;
		std::cout << atomic_bomb << std::endl;
		atomic_bomb.beSigned(alexandra);
		std::cout << "=>" << atomic_bomb << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	signFormTest(void) {
	std::cout << "\n===signForm() Test===" << std::endl;
	Bureaucrat	bettany("bettany", 42);
	Form		atomic_bomb("Fire atomic bomb form", 1, 1);
	Form		breathing_allow("breathing allow form", 124, 142);

	try
	{
		std::cout << "\n---signForm() : breathing_allow---" << std::endl;
		std::cout << breathing_allow << std::endl;
		bettany.signForm(breathing_allow);
		std::cout << "=>" << breathing_allow << std::endl;
		std::cout << "\n---signForm() : atomic_bomb---" << std::endl;
		std::cout << atomic_bomb << std::endl;
		bettany.signForm(atomic_bomb);
		std::cout << "=>" << atomic_bomb << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

int	main(void) {
	basicTest();
	instantiationTest();
	beSignedTest();
	signFormTest();
	std::cout << "\n===Check Memory Leaks===" << std::endl;
	system("leaks a.out");
	return 0;
}
