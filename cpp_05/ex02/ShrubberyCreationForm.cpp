#include "ShrubberyCreationForm.hpp"

void	ShrubberyCreationForm::executeFormAction() const {
	std::string		target = this->target;
	std::ofstream	ofs(target.append("_shrubbery"));

	ofs << "         #               #               #         " << std::endl;
	ofs << "        ###             ###             ###        " << std::endl;
	ofs << "        ###             ###             ###        " << std::endl;
	ofs << "       #####           #####           #####       " << std::endl;
	ofs << "       #####           #####           #####       " << std::endl;
	ofs << "      #######         #######         #######      " << std::endl;
	ofs << "      #######         #######         #######      " << std::endl;
	ofs << "     #########       #########       #########     " << std::endl;
	ofs << "     #########       #########       #########     " << std::endl;
	ofs << "    ###########     ###########     ###########    " << std::endl;
	ofs << "    ###########     ###########     ###########    " << std::endl;
	ofs << "    ###########     ###########     ###########    " << std::endl;
	ofs << "        |||             |||             |||        " << std::endl;
	ofs << "        |||             |||             |||        " << std::endl;
	ofs.close();
}

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137) {
	std::cout << "ShrubberyCreationForm Default Constructor Called" << std::endl;
	this->target = "[Unknown]";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string form_target)
: AForm("ShrubberyCreationForm", 145, 137) {
	std::cout << "ShrubberyCreationForm Parameter Constructor Called" << std::endl;
	this->target = form_target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src)
: AForm((std::string)src.getName(), (int)src.getSignGrade(), (int)src.getExecGrade()) {
	std::cout << "ShrubberyCreationForm Copy Constructor Called" << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm Destructor Called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& src) {
	std::cout << "ShrubberyCreationForm Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->target = src.target;
	}
	return *this;
}
