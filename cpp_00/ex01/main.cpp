#include "phonebook.hpp"

int	main(void)
{
	Phonebook	the_phonebook;
	std::string	user_command;

	while (1) {
		user_command = the_phonebook.getUserCommand();
		if (user_command == "ADD")
			the_phonebook.addContact();
		else if (user_command == "SEARCH")
			the_phonebook.searchContact();
		else if (user_command == "EXIT")
			break ;
		else {
			std::cout << "Invalid Command" << std::endl;
			continue;
		}
	}
	return (0);
}
