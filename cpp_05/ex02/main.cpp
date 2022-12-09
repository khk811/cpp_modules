#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	basicTest(void){
	std::cout << "\n===Basic Test (Orthodox Canonique)===" << std::endl;
	// Default Constructor test;
	const ShrubberyCreationForm		default_shru;
	const RobotomyRequestForm		default_robo;
	const PresidentialPardonForm	default_presi;

	// Copy Constructor test;
	std::cout << "\n---Copy Constructor Test---" << std::endl;
	AForm*	copy_shru = new ShrubberyCreationForm(default_shru);
	AForm*	copy_robo = new RobotomyRequestForm(default_robo);
	AForm*	copy_presi = new PresidentialPardonForm(default_presi);

	// Copy Assignment Operator test;
	std::cout << "\n---Copy Assignment Operator Test---" << std::endl;
	ShrubberyCreationForm	dummy_shru("Dummy1");
	RobotomyRequestForm		dummy_robo("Dummy2");
	PresidentialPardonForm	dummy_presi("Dummy3");

	dummy_shru = default_shru;
	dummy_robo = default_robo;
	dummy_presi = default_presi;

	std::cout << "" << std::endl;
	std::cout << "\n---Object From Default Constructor---" << std::endl;
	std::cout << "[default_shru : " << default_shru << "]" << std::endl;
	std::cout << "[default_robo : " << default_robo << "]" << std::endl;
	std::cout << "[default_presi: " << default_presi << "]" << std::endl;
	std::cout << "\n---Object From Copy Constructor---" << std::endl;
	// something wrong here: the name is not right;
	std::cout << "[copy_shru : " << *copy_shru << "]" << std::endl;
	std::cout << "[copy_robo : " << *copy_robo << "]" << std::endl;
	std::cout << "[copy_presi: " << *copy_presi << "]" << std::endl;
	std::cout << "\n---Object From Copy Assignment Operator---" << std::endl;
	std::cout << "[dummy_shru : " << dummy_shru << "]" << std::endl;
	std::cout << "[dummy_robo : " << dummy_robo << "]" << std::endl;
	std::cout << "[dummy_presi: " << dummy_presi << "]" << std::endl;
	std::cout << "" << std::endl;

	delete copy_presi;
	delete copy_robo;
	delete copy_shru;
}

void	instantiationTest(void) {
	std::cout << "\n===instantiation Test (AForm and derived class)===" << std::endl;
	ShrubberyCreationForm	valid_shru("(valid_a)");
	RobotomyRequestForm		valid_robo("(valid_b)");
	PresidentialPardonForm	valid_presi("(valid_c)");

	std::cout << valid_shru << std::endl;
	std::cout << valid_robo << std::endl;
	std::cout << valid_presi << std::endl;

	// AForm					abstract_form();
	// std::cout << abstract_form << std::endl;
}

void	shrubberyTest(void) {
	std::cout << "\n===class ShrubberyCreationForm Test()===" << std::endl;
	AForm*		gaepo_cluster = new ShrubberyCreationForm("Gaepo-ro_416");
	AForm*		seocho_cluster = new ShrubberyCreationForm("Gangnamdae-ro_327");
	Bureaucrat	aaron("Aaron", 140);
	Bureaucrat	brian("Brian", 130);
	Bureaucrat	chris("Chris", 150);

	std::cout << "\n---Before sign, execute---" << std::endl;
	std::cout << *gaepo_cluster << std::endl;
	std::cout << *seocho_cluster << std::endl;
	try
	{
		std::cout << "\n---signForm(), executeForm() : Grade " << brian.getGrade() << "---" << std::endl;
		brian.signForm(*gaepo_cluster);
		std::cout << "=>" << *gaepo_cluster << std::endl;
		brian.executeForm(*gaepo_cluster);
		std::cout << "\n---signForm(), executeForm() : Grade " << chris.getGrade() << "---" << std::endl;
		chris.signForm(*seocho_cluster);
		std::cout << "=>" << *seocho_cluster << std::endl;
		chris.executeForm(*seocho_cluster);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n---signForm(), executeForm() : Grade " << aaron.getGrade() << "---" << std::endl;
		aaron.signForm(*seocho_cluster);
		std::cout << "=>" << *seocho_cluster << std::endl;
		aaron.executeForm(*seocho_cluster);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete gaepo_cluster;
	delete seocho_cluster;
}

void	robotomyTest(void) {
	std::cout << "\n===class RobotomyRequestForm Test()===" << std::endl;
	AForm*		alpha = new RobotomyRequestForm("Alpha");
	AForm*		gamma = new RobotomyRequestForm("Gamma");
	Bureaucrat	alexandra("Alexandra", 60);
	Bureaucrat	bettany("Bettany", 40);
	Bureaucrat	catherine("Catherine", 80);

	std::cout << "\n---Before sign, execute---" << std::endl;
	std::cout << *alpha << std::endl;
	std::cout << *gamma << std::endl;
	try
	{
		std::cout << "\n---signForm(), executeForm() : Grade " << bettany.getGrade() << "---" << std::endl;
		bettany.signForm(*alpha);
		std::cout << "=>" << *alpha << std::endl;
		bettany.executeForm(*alpha);
		std::cout << "\n---signForm(), executeForm() : Grade " << catherine.getGrade() << "---" << std::endl;
		catherine.signForm(*gamma);
		std::cout << "=>" << *gamma << std::endl;
		catherine.executeForm(*gamma);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n---signForm(), executeForm() : Grade " << alexandra.getGrade() << "---" << std::endl;
		alexandra.signForm(*gamma);
		std::cout << "=>" << *gamma << std::endl;
		alexandra.executeForm(*gamma);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete alpha;
	delete gamma;
}

void	presidentialTest(void) {
	std::cout << "\n===class PresidentialPardonForm Test()===" << std::endl;
	AForm*		epsilon = new PresidentialPardonForm("Epsilon");
	AForm*		omega = new PresidentialPardonForm("Omega");
	Bureaucrat	agent_a("Agent A", 10);
	Bureaucrat	agent_b("Agent B", 5);
	Bureaucrat	agent_c("Agent C", 30);

	std::cout << "\n---Before sign, execute---" << std::endl;
	std::cout << *epsilon << std::endl;
	std::cout << *omega << std::endl;
	try
	{
		std::cout << "\n---signForm(), executeForm() : Grade " << agent_b.getGrade() << "---" << std::endl;
		agent_b.signForm(*epsilon);
		std::cout << "=>" << *epsilon << std::endl;
		agent_b.executeForm(*epsilon);
		std::cout << "\n---signForm(), executeForm() : Grade " << agent_c.getGrade() << "---" << std::endl;
		agent_c.signForm(*omega);
		std::cout << "=>" << *omega << std::endl;
		agent_c.executeForm(*omega);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n---signForm(), executeForm() : Grade " << agent_a.getGrade() << "---" << std::endl;
		agent_a.signForm(*omega);
		std::cout << "=>" << *omega << std::endl;
		agent_a.executeForm(*omega);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete epsilon;
	delete omega;
}

int	main(void) {
	basicTest();
	instantiationTest();
	shrubberyTest();
	robotomyTest();
	presidentialTest();
	std::cout << "\n===Check Memory Leak===" << std::endl;
	system("leaks a.out");
	return 0;
}
