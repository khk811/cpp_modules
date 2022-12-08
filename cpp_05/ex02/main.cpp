#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	Bureaucrat	james("James", 100);
	Bureaucrat	thomas("Thomas", 1);
	Bureaucrat	riam("Riam", 2);
	Bureaucrat	steve("Steve", 140);
	// Bureaucrat	harry("Harry", 0);
	Bureaucrat	romeo("Romeo", 75);
	AForm*		shrubbery = new ShrubberyCreationForm("home");
	AForm*		robot = new RobotomyRequestForm("delta");
	AForm*		robot2 = new RobotomyRequestForm("gamma");
	AForm*		wtf = new PresidentialPardonForm("Alexandra the mutant");
	// AForm*		qwer = new PresidentialPardonForm("dummy");

	try {
		james.increaseGrade();
		// thomas.increaseGrade();
		// steve.decreaseGrade();
		thomas.decreaseGrade();
		steve.increaseGrade();
		// steve.signForm(*shrubbery);
		// shrubbery->execute(steve);
		romeo.signForm(*shrubbery);
		shrubbery->execute(romeo);
		thomas.signForm(*robot);
		robot->execute(thomas);
		riam.signForm(*robot2);
		robot2->execute(riam);
		// thomas.signForm(*wtf);
		// wtf->execute(thomas);
		// thomas.signForm(*wtf);
		romeo.signForm(*wtf);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		// delete shrubbery;
	}
	std::cout << james << std::endl;
	std::cout << thomas << std::endl;
	std::cout << steve << std::endl;
	std::cout << romeo << std::endl;
	delete shrubbery;
	delete robot;
	delete robot2;
	std::cout << "\n===Check Memory Leak===" << std::endl;
	system("leaks a.out");
	return 0;
}
