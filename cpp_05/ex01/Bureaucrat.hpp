#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	std::string const	name;
	int					grade;
public:
	Bureaucrat();
	Bureaucrat(Bureaucrat const& src);
	Bureaucrat(std::string const bureau_name, int bureau_grade);
	~Bureaucrat();
	std::string const	getName() const;
	int					getGrade() const;
	void				increaseGrade();
	void				decreaseGrade();
	void				signForm(Form& to_sign);
	Bureaucrat&			operator=(Bureaucrat const& src);
	class GradeTooHighException : public std::exception
	{
		const char*		what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char*		what() const throw();
	};

};

std::ostream&			operator<<(std::ostream& ostrm, Bureaucrat const& src);

#endif
