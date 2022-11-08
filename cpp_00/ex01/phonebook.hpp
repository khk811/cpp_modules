#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__

#include <iomanip>
#include "contact.hpp"

class Phonebook
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

	Phonebook();
	~Phonebook();
	bool	addContact();
	void	searchContact();
	std::string	getUserCommand();
};

#endif
