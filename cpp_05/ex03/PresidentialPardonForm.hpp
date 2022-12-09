#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string				target;
	void					executeFormAction() const;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string form_target);
	PresidentialPardonForm(PresidentialPardonForm const& src);
	~PresidentialPardonForm();
	PresidentialPardonForm&	operator=(PresidentialPardonForm const& src);
};

#endif
