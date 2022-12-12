#include "Intern.hpp"

Intern::form_type	Intern::searchMatchingForm(std::string form_name) {
	std::string			form_type[3] = {"shrubbery creation", \
										"robotomy request", \
										"presidential pardon"};
	Intern::form_type	search_result = FORM_NOTFOUND;

	for (int i = 0; i < 3; i++)
	{
		if (form_type[i] == form_name) {
			std::cout << "Intern creates " << form_name << std::endl;
			search_result = (Intern::form_type)i;
		}
	}
	return search_result;
}

Intern::Intern() {
	std::cout << "Intern Default Constructor Called" << std::endl;
}

Intern::Intern(Intern const& src) {
	std::cout << "Intern Copy Constructor Called" << std::endl;
	*this = src;
}

Intern::~Intern() {
	std::cout << "Intern Destructor Called" << std::endl;
}

AForm*	Intern::makeForm(std::string form_name, std::string target) {
	Intern::form_type	matched_form = this->searchMatchingForm(form_name);
	AForm*				new_form = NULL;

	switch (matched_form)
	{
	case FORM_SHRUBBERY:
		new_form = new ShrubberyCreationForm(target);
		break;
	case FORM_ROBOTOMY:
		new_form = new RobotomyRequestForm(target);
		break;
	case FORM_PRESIDENTIAL:
		new_form = new PresidentialPardonForm(target);
		break;
	default:
		throw Intern::FormNotFound();
		break;
	}
	return new_form;
}

Intern&	Intern::operator=(Intern const& src) {
	std::cout << "Intern Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		(void)src;
	}
	return *this;
}

const char*	Intern::FormNotFound::what() const throw() {
	return "the form is not found";
}
