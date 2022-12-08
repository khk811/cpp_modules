#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const	name;
	bool				is_signed;
	int const			sign_grade;
	int const			exec_grade;
public:
	Form();
	Form(Form const& src);
	Form(std::string form_name, int form_sign_grade, int form_exec_grade);
	~Form();
	std::string const	getName() const;
	bool				getIsSigned() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	void				beSigned(Bureaucrat& bureau);
	Form&				operator=(Form const& src);
	class GradeTooHighException : public std::exception
	{
		const char*		what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char*		what() const throw();
	};
};

std::ostream&			operator<<(std::ostream& ostrm, Form const& src);

#endif
