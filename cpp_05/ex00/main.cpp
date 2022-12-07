#include "Bureaucrat.hpp"

int	main(void) {
	Bureaucrat	james("James", 100);
	Bureaucrat	thomas("Thomas", 1);
	Bureaucrat	steve("Steve", 150);
	// Bureaucrat	harry("Harry", 0);
	Bureaucrat	romeo("Romeo", 75);

	try {
		james.increaseGrade();
		// thomas.increaseGrade();
		// steve.decreaseGrade();
		thomas.decreaseGrade();
		steve.increaseGrade();
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "James's grade: " << james.getGrade() << std::endl;
	std::cout << "Thomas's grade: " << thomas.getGrade() << std::endl;
	std::cout << "Steve's grade: " << steve.getGrade() << std::endl;
	std::cout << "Romeo's grade: " << romeo.getGrade() << std::endl;
	// system("leaks a.out");
	return 0;
}
