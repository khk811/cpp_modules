#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <iostream>

class Contact
{
private:
	int	index;
	std::string	first_name;
	std::string	last_name;

public:
	Contact();
	Contact(int index, std::string first_name, std::string last_name);
	~Contact();
	int	GetIndex();
	std::string	GetFirstName();
	std::string	GetLastName();
	void	SetIndex(int index);
	void	SetFirstName(std::string FirstName);
	void	SetLastName(std::string LastName);
};

// overloading generator!!

Contact::Contact()
{
}

Contact::Contact(int index, std::string first_name, std::string last_name)
{
	this->index = index;
	this->first_name = first_name;
	this->last_name = last_name;
}

Contact::~Contact()
{
}

int Contact::GetIndex()
{
	return this->index;
}

std::string Contact::GetFirstName()
{
	return this->first_name;
}

std::string Contact::GetLastName()
{
	return this->last_name;
}

void	Contact::SetIndex(int index)
{
	this->index = index;
}
void	Contact::SetFirstName(std::string FirstName)
{
	this->first_name = FirstName;
}

void	Contact::SetLastName(std::string LastName)
{
	this->last_name = LastName;
}
#endif
