#include "PresidentialPardonForm.hpp"

void	PresidentialPardonForm::executeFormAction() const {
	std::cout << this->target;
	std::cout << " been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5) {
	std::cout << "PresidentialPardonForm Default Constructor Called" << std::endl;
	this->target = "[Unknown]";
}

PresidentialPardonForm::PresidentialPardonForm(std::string form_target)
: AForm("PresidentialPardonForm", 25, 5) {
	std::cout << "PresidentialPardonForm Parameter Constructor Called" << std::endl;
	this->target = form_target;

}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src) {
	std::cout << "PresidentialPardonForm Copy Constructor Called" << std::endl;
	*this = src;

}
PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm Destructor Called" << std::endl;

}
PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& src) {
	std::cout << "PresidentialPardonForm Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		*(this) = src;
	}
	return *this;
}
