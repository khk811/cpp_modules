#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__

#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	int	curr_index;

	void	printContactFields(int index);
	std::string	getUserInputString(std::string format_string);
	int		getUserInputIndex();
	void	updateCurrentIndex();
	void	findContact();

public:
	static int	filled_contact_num;

	PhoneBook();
	~PhoneBook();
	bool	addContact();
	void	searchContact();
	std::string	getUserCommand();
};

#endif
