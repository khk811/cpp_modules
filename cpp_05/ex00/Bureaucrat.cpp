#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("[no_name]"), grade(75) {
	std::cout << "Bureaucrat Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const& src) {
	std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
	*this = src;
}

Bureaucrat::Bureaucrat(std::string const bureau_name, int bureau_grade)
: name(bureau_name) {
	std::cout << "Bureaucrat String, Int Constructor Called" << std::endl;
	if (bureau_grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else if (bureau_grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->grade = bureau_grade;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Destructor Called" << std::endl;
}

std::string const	Bureaucrat::getName() {
	return this->name;
}

int	Bureaucrat::getGrade() {
	return this->grade;
}

void	Bureaucrat::increaseGrade() {
	std::cout << "increseGrade() Called" << std::endl;
	if (this->grade > 1) {
		this->grade--;
	} else {
		throw Bureaucrat::GradeTooHighException();
	}
}

void	Bureaucrat::decreaseGrade() {
	std::cout << "decreseGrade() Called" << std::endl;
	if (this->grade < 150) {
		this->grade++;
	} else {
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& src) {
	std::cout << "Bureaucrat Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->grade = src.grade;
	}
	return *this;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "The grade is too high";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "The grade is too low";
}
