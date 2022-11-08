#include "contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::getFirstName()
{
	return this->first_name;
}

std::string Contact::getLastName()
{
	return this->last_name;
}

std::string	Contact::getNickName()
{
	return this->nick_name;
}

std::string	Contact::getPhoneNumber(){
	return this->phone_number;
}

std::string	Contact::getDarkestSecret(){
	return this->darkest_secret;
}

void	Contact::setFirstName(std::string first_name)
{
	this->first_name = first_name;
}

void	Contact::setLastName(std::string last_name)
{
	this->last_name = last_name;
}

void	Contact::setNickName(std::string nick_name)
{
	this->nick_name = nick_name;
}

void	Contact::setPhoneNumber(std::string phone_num)
{
	this->phone_number = phone_num;
}

void	Contact::setDarkestSecret(std::string secret)
{
	this->darkest_secret = secret;
}

bool	Contact::isValidContact()
{
	std::string	phone_num;

	phone_num = this->getPhoneNumber();
	for (unsigned int i = 0; i < phone_num.length(); i++)
	{
		if (std::isalpha(phone_num[i]))
			return (false);
	}
	return (true);
}
