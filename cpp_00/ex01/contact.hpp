#pragma once
#ifndef __CONTACT_HPP__
#define __CONTACT_HPP__

#include <iostream>

class Contact
{
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string	darkest_secret;

public:
	Contact();
	~Contact();
	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickName();
	std::string	getPhoneNumber();
	std::string	getDarkestSecret();
	void	setFirstName(std::string first_name);
	void	setLastName(std::string last_name);
	void	setNickName(std::string nick_name);
	void	setPhoneNumber(std::string phone_number);
	void	setDarkestSecret(std::string darkest_secret);
};

#endif
