#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string				target;
	void					executeFormAction() const;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string form_target);
	ShrubberyCreationForm(ShrubberyCreationForm const& src);
	~ShrubberyCreationForm();
	ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& src);
};

#endif
