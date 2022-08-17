#pragma once
#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__

#include "contact.hpp"

class Phonebook
{
private:
	Contact	contacts[8];
	int	next_target_index;

public:
	Phonebook();
	~Phonebook();
	Contact	getContact();
	int	getCurrentTargetIndex();
	void	setContact(std::string index, std::string first_name, \
	std::string last_name, std::string nick_name);
};

#endif
