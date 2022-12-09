#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	enum form_type
	{
		FORM_SHRUBBERY = 0,
		FORM_ROBOTOMY,
		FORM_PRESIDENTIAL,
		FORM_NOTFOUND
	};
	enum form_type	searchMatchingForm(std::string form_name);
public:
	Intern();
	Intern(Intern const& src);
	~Intern();
	AForm*			makeForm(std::string form_name, std::string target);
	Intern&			operator=(Intern const& src);
	class FormNotFound : public std::exception
	{
		const char*	what() const throw();
	};
};

#endif
