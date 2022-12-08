#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string const	name;
	bool				is_signed;
	int const			sign_grade;
	int const			exec_grade;
public:
	AForm();
	AForm(AForm const& src);
	AForm(std::string form_name, int form_sign_grade, int form_exec_grade);
	virtual				~AForm();
	std::string const	getName() const;
	bool				getIsSigned() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	void				beSigned(Bureaucrat& bureau);
	void				execute(Bureaucrat const& executor) const;
	virtual void		executeFormAction() const = 0;
	AForm&				operator=(AForm const& src);
	class GradeTooHighException : public std::exception
	{
		const char*		what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char*		what() const throw();
	};
	class FormNotSigned : public std::exception
	{
		const char*		what() const throw();
	};
	class FormAlreadySigned : public std::exception
	{
		const char*		what() const throw();
	};
};

std::ostream&			operator<<(std::ostream& ostrm, AForm const& src);

#endif
