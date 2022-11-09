#include "Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

void	Harl::debug() {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void	Harl::info() {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	std::cout << std::endl;
}

void	Harl::warning() {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void	Harl::error() {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

Harl::level	Harl::checkInputLevel(std::string level) {
	if (level == "DEBUG")
		return (LEVEL_DEBUG);
	else if (level == "INFO")
		return (LEVEL_INFO);
	else if (level == "WARNING")
		return (LEVEL_WARNING);
	else if (level == "ERROR")
		return (LEVEL_ERROR);
	else
		return (DEFAULT);
}

void	Harl::complain(std::string level) {
	Harl::level	targetLevel;

	targetLevel = this->checkInputLevel(level);
	switch (targetLevel)
	{
	case LEVEL_DEBUG:
		this->debug();
	case LEVEL_INFO:
		this->info();
	case LEVEL_WARNING:
		this->warning();
	case LEVEL_ERROR:
		this->error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}
