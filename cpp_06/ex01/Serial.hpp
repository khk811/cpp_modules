#ifndef SERIAL_HPP
#define SERIAL_HPP

#include <iostream>
#include <cstdint>


struct Data
{
	int			index;
	std::string	content;
};

class Serial
{
private:
	Data*	data;
	// Data가 여기에 들어가는지 아닌지 모르겠음.
public:
	Serial();
	Serial(Serial const& src);
	~Serial();
	Data*	getDataAddr(void);
	Serial&	operator=(Serial const& src);
};

uintptr_t	serialize(Data* ptr);
Data* 		deserialize(uintptr_t raw);

#endif

