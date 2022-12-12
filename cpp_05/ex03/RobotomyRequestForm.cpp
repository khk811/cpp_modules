#include "RobotomyRequestForm.hpp"

void RobotomyRequestForm::executeFormAction() const {
	int	chance = rand() % 100 + 1;

	std::cout << "(insert drilling noize here)" << std::endl;
	if (chance % 2 == 0) {
		std::cout << "Success: " << this->target << " has been robotomized" << std::endl;
	} else {
		std::cout << "Fail: Robotomize "<< this->target << " failed" << std::endl;
	}
}

RobotomyRequestForm::RobotomyRequestForm()
: AForm("robotomy request", 72, 45) {
	std::cout << "RobotomyRequestForm Default Constructor Called" << std::endl;
	this->target = "[Unknown]";
}

RobotomyRequestForm::RobotomyRequestForm(std::string form_target)
: AForm("robotomy request", 72, 45) {
	std::cout << "RobotomyRequestForm Parameter Constructor Called" << std::endl;
	this->target = form_target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src) {
	std::cout << "RobotomyRequestForm Copy Constructor Called" << std::endl;
	*this = src;
}
RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm Desstructor Called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& src) {
	std::cout << "RobotomyRequestForm Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		*(this) = src;
	}
	return *this;
}
