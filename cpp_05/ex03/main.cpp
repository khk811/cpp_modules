#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void) {
	Bureaucrat	rupaul("RuPaul", 1);
	Bureaucrat	steve("Steve", 140);
	Bureaucrat	romeo("Romeo", 75);
	Intern		julio;
	AForm*		new_form = NULL;

	try {
		new_form = julio.makeForm("PresidentialPardonForm", "hyunkkim");
		// rupaul.signForm(*new_form);
		// rupaul.executeForm(*new_form);
		romeo.signForm(*new_form);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << rupaul << std::endl;
	std::cout << steve << std::endl;
	std::cout << romeo << std::endl;
	if (new_form != NULL) {
		delete new_form;
	}
	std::cout << "\n===Check Memory Leak===" << std::endl;
	system("leaks a.out");
	return 0;
}
