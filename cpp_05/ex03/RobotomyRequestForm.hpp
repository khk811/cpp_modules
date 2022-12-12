#ifndef ROMOTOMYREQUESTFORM_HPP
#define ROMOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
private:
	std::string				target;
	void					executeFormAction() const;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string form_target);
	RobotomyRequestForm(RobotomyRequestForm const& src);
	~RobotomyRequestForm();
	RobotomyRequestForm&	operator=(RobotomyRequestForm const& src);
};

#endif
