#pragma once
#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__

#include <iomanip>
#include <ctype.h>
#include "contact.hpp"

class Phonebook
{
private:
	Contact	contacts[8];
	int	curr_index;
	int	max_index;

public:
	Phonebook();
	~Phonebook();
	Contact	getContact();
	std::string	getUserInputString(std::string format_string);
	int		getUserInputIndex();
	void	updateCurrentIndex();
	void	updateMaxIndex();
	void	addContact();
	void	printContactFields(int index);
	void	searchContact();
	void	findContact();
	std::string	getUserCommand();
};

#endif
