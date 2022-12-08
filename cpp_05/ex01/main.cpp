#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	Bureaucrat	james("James", 100);
	Bureaucrat	thomas("Thomas", 1);
	Bureaucrat	steve("Steve", 150);
	// Bureaucrat	harry("Harry", 0);
	Bureaucrat	romeo("Romeo", 75);

	Form		immigrant_form("Immigrant Form", 100, 100);

	try {
		james.increaseGrade();
		// thomas.increaseGrade();
		// steve.decreaseGrade();
		thomas.decreaseGrade();
		steve.increaseGrade();
		steve.signForm(immigrant_form);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << james << std::endl;
	std::cout << thomas << std::endl;
	std::cout << steve << std::endl;
	std::cout << romeo << std::endl;
	std::cout << immigrant_form << std::endl;
	// system("leaks a.out");
	return 0;
}
