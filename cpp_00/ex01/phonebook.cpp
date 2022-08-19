#include "phonebook.hpp"

Phonebook::Phonebook(){
	this->curr_index = 0;
	this->max_index = 0;
}

Phonebook::~Phonebook(){
}

Contact	Phonebook::getContact(){
	return this->contacts[0];
}

std::string	Phonebook::getUserInputString(std::string format_string){
	std::string	user_input;

	std::cout << format_string;
	std::getline(std::cin, user_input);
	return user_input;
}

int	Phonebook::getUserInputIndex() {
	std::string user_input;
	int			input_index;

	user_input = this->getUserInputString("Enter the index: ");
	if (user_input.length() > 2 || !isdigit(user_input[0]))
		return (-1);
	input_index = user_input[0] - '0';
	return input_index;
}

void	Phonebook::updateCurrentIndex() {
	if (this->curr_index < 7)
		this->curr_index++;
	else if (this->curr_index == 7)
		this->curr_index = 0;
}

void	Phonebook::updateMaxIndex() {
	if (this->max_index < 8)
		this->max_index++;
	else
		return ;
}

void	Phonebook::addContact(){
	Contact*	target;

	target = &(this->contacts[this->curr_index]);
	target->setFirstName(this->getUserInputString("First name: "));
	target->setLastName(this->getUserInputString("Last name: "));
	target->setNickName(this->getUserInputString("Nick name: "));
	target->setPhoneNumber(this->getUserInputString("Phone Number: "));
	target->setDarkestSecret(this->getUserInputString("Darkest Secret: "));
	this->updateCurrentIndex();
	this->updateMaxIndex();
}

void	Phonebook::printContactFields(int index) {
	std::cout << std::setw(10);
	std::cout << index;
	std::cout << "|";
	std::cout << std::setw(10);
	if (this->contacts[index].getFirstName().length() > 10)
		std::cout << this->contacts[index].getFirstName().substr(0, 9) + ".";
	else
		std::cout << this->contacts[index].getFirstName();
	std::cout << "|";
	std::cout << std::setw(10);
	if (this->contacts[index].getLastName().length() > 10)
		std::cout << this->contacts[index].getLastName().substr(0, 9) + ".";
	else
		std::cout << this->contacts[index].getLastName();
	std::cout << "|";
	std::cout << std::setw(10);
	if (this->contacts[index].getNickName().length() > 10)
		std::cout << this->contacts[index].getNickName().substr(0, 9) + ".";
	else
		std::cout << this->contacts[index].getNickName();
	std::cout << std::endl;
}

void	Phonebook::searchContact(){
	for (int index = 0; index < this->max_index; index++) {
		printContactFields(index);
	}
	findContact();
	return ;
}

void	Phonebook::findContact(){
	int	target_index;

	target_index = getUserInputIndex();
	if (target_index == -1 || target_index > this->max_index) {
		std::cout << "Invalid index. Please try again." << std::endl;
		return ;
	}
	std::cout << this->contacts[target_index].getFirstName() << std::endl;
	std::cout << this->contacts[target_index].getLastName() << std::endl;
	std::cout << this->contacts[target_index].getNickName() << std::endl;
	std::cout << this->contacts[target_index].getPhoneNumber() << std::endl;
	std::cout << this->contacts[target_index].getDarkestSecret() << std::endl;
}

std::string	Phonebook::getUserCommand() {
	std::string	user_command;

	std::cout << "<< Available Commands >>" << std::endl;
	std::cout << "|  ADD, SEARCH, EXIT   |" << std::endl;
	std::cout << "Enter the Command: ";
	std::getline(std::cin, user_command);
	return user_command;
}
