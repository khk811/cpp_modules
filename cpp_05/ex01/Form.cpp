#include "Form.hpp"

Form::Form() : name("[Untitled]"), sign_grade(75), exec_grade(75) {
	std::cout << "Form Default Constructor Called" << std::endl;
	this->is_signed = false;
}

Form::Form(Form const& src)
: name(src.name), sign_grade(src.sign_grade), exec_grade(src.exec_grade) {
	std::cout << "Form Copy Constructor Called" << std::endl;
	*this = src;
}

Form::Form(std::string form_name, int form_sign_grade, int form_exec_grade)
: name(form_name), sign_grade(form_sign_grade), exec_grade(form_exec_grade) {
	std::cout << "Form Parameter Constructor Called" << std::endl;
	this->is_signed = false;
	if (this->sign_grade < 1 || this->exec_grade < 1) {
		throw Form::GradeTooHighException();
	} else if (this->sign_grade > 150 || this->exec_grade > 150) {
		throw Form::GradeTooLowException();
	}
}

Form::~Form() {
	std::cout << "Form Destructor Called" << std::endl;
}

std::string const	Form::getName() const {
	return this->name;
}

bool	Form::getIsSigned() const {
	return this->is_signed;
}

int	Form::getSignGrade() const {
	return this->sign_grade;
}

int	Form::getExecGrade() const {
	return this->exec_grade;
}

void	Form::beSigned(Bureaucrat& bureau) {
	if (bureau.getGrade() > this->exec_grade) {
		std::cout << bureau.getName() << " couldn't sign ";
		std::cout << this->sign_grade << " because ";
		throw Form::GradeTooLowException();
	} else {
		this->is_signed = true;
	}
}

Form&	Form::operator=(Form const& src) {
	std::cout << "Form Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->is_signed = src.is_signed;
	}
	return *this;
}

const char*	Form::GradeTooHighException::what() const throw() {
	return "Form: The grade is too high";
}

const char*	Form::GradeTooLowException::what() const throw() {
	return "Form: The grade is too low";
}

std::ostream&	operator<<(std::ostream& ostrm, Form const& src) {
	ostrm << "Form " << src.getName();
	ostrm << ", signed " << src.getIsSigned();
	if (src.getIsSigned() == true) {
		ostrm << "(true)";
	} else {
		ostrm << "(false)";
	}
	ostrm << ", required sign grade " << src.getSignGrade();
	ostrm << ", required execution grade " << src.getExecGrade();
	return ostrm;
}
