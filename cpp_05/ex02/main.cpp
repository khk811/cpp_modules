#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void) {
	Bureaucrat	james("James", 100);
	Bureaucrat	thomas("Thomas", 1);
	Bureaucrat	steve("Steve", 140);
	// Bureaucrat	harry("Harry", 0);
	Bureaucrat	romeo("Romeo", 75);
	AForm*		shrubbery = new ShrubberyCreationForm("home");

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
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
		// delete shrubbery;
	}
	std::cout << james << std::endl;
	std::cout << thomas << std::endl;
	std::cout << steve << std::endl;
	std::cout << romeo << std::endl;
	delete shrubbery;
	system("leaks a.out");
	return 0;
}
