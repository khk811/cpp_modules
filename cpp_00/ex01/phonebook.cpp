//#include "phonebook.hpp"
#include "phonebook.hpp"

Phonebook::Phonebook()
{
	this->next_target_index = 0;
}

Phonebook::~Phonebook()
{
}

Contact	Phonebook::getContact()
{
	return this->contacts[0];
}

int	Phonebook::getCurrentTargetIndex()
{
	return this->next_target_index;
}

void	Phonebook::setContact(std::string index, std::string first_name, \
std::string last_name, std::string nick_name)
{
	Contact	*target_contact;

	target_contact = &(this->contacts[this->next_target_index]);
	// if (this->next_target_index < 8) {
		// target_contact = &(this->contacts[this->next_target_index]);
	// }
	if (this->next_target_index < 7) {
		this->next_target_index += 1;
	}
	else if (this->next_target_index == 7) {
		this->next_target_index = 0;
	}
	target_contact->setIndex(index);
	target_contact->setFirstName(first_name);
	target_contact->setLastName(last_name);
	target_contact->setNickName(nick_name);
}

int	main(void)
{
	Phonebook	the_phonebook;
	std::string	index;
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;

	std::cout << "index: ";
	std::getline(std::cin, index);
	if (index.length() > 1 || (index[0] == '8' || index[0] == '9')) {
		std::cout << "invalid input index" << std::endl;
		return 1;
	}
	std::cout << "first name: ";
	std::getline(std::cin, first_name);
	std::cout << "last name: ";
	std::getline(std::cin, last_name);
	std::cout << "nick name: ";
	std::getline(std::cin, nick_name);
	the_phonebook.setContact(index, first_name, last_name, nick_name);
	std::cout << the_phonebook.getContact().getIndex() << std::endl;
	std::cout << the_phonebook.getContact().getFirstName() << std::endl;
	std::cout << the_phonebook.getContact().getLastName() << std::endl;
	std::cout << the_phonebook.getContact().getNickName() << std::endl;
	std::cout << "the next target index: " << the_phonebook.getCurrentTargetIndex() << std::endl;
	return (0);
}
