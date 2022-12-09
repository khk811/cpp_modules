#include "AForm.hpp"

AForm::AForm() : name("[Untitled]"), sign_grade(75), exec_grade(75) {
	std::cout << "AForm Default Constructor Called" << std::endl;
	this->is_signed = false;
}

AForm::AForm(AForm const& src)
: name(src.name), sign_grade(src.sign_grade), exec_grade(src.exec_grade) {
	std::cout << "AForm Copy Constructor Called" << std::endl;
	*this = src;
}

AForm::AForm(std::string form_name, int form_sign_grade, int form_exec_grade)
: name(form_name), sign_grade(form_sign_grade), exec_grade(form_exec_grade) {
	std::cout << "AForm Parameter Constructor Called" << std::endl;
	this->is_signed = false;
	if (this->sign_grade < 1 || this->exec_grade < 1) {
		throw AForm::GradeTooHighException();
	} else if (this->sign_grade > 150 || this->exec_grade > 150) {
		throw AForm::GradeTooLowException();
	}
}

AForm::~AForm() {
	std::cout << "AForm Destructor Called" << std::endl;
}

std::string const	AForm::getName() const {
	return this->name;
}

bool	AForm::getIsSigned() const {
	return this->is_signed;
}

int	AForm::getSignGrade() const {
	return this->sign_grade;
}

int	AForm::getExecGrade() const {
	return this->exec_grade;
}

void	AForm::beSigned(Bureaucrat& bureau) {
	if (this->is_signed == false && bureau.getGrade() <= this->sign_grade) {
		this->is_signed = true;
	} else {
		std::cout << bureau.getName() << " couldn't sign ";
		std::cout << this->name << " because ";
		if (bureau.getGrade() > this->sign_grade) {
			throw AForm::GradeTooLowException();
		} else {
			throw AForm::FormAlreadySigned();
		}
	}
}

void	AForm::execute(Bureaucrat const& executor) const {
	if (this->is_signed == true && executor.getGrade() <= this->exec_grade) {
		this->executeFormAction();
	} else {
		std::cout << executor.getName();
		std::cout << " couldn't execute " << this->name << " because ";
		if (executor.getGrade() > this->sign_grade) {
			throw AForm::GradeTooLowException();
		} else {
			throw AForm::FormNotSigned();
		}
	}
}

AForm&	AForm::operator=(AForm const& src) {
	std::cout << "AForm Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->is_signed = src.is_signed;
	}
	return *this;
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return "the grade is too high";
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "the grade is too low";
}

const char*	AForm::FormNotSigned::what() const throw() {
	return "the form haven't signed";
}

const char*	AForm::FormAlreadySigned::what() const throw() {
	return "the form has already signed";
}

std::ostream&	operator<<(std::ostream& ostrm, AForm const& src) {
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
