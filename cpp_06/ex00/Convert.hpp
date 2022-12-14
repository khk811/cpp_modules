#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <sstream>

class Convert
{
private:
	std::string			raw_input;
	std::stringstream	string_stream;
	bool				is_float;
public:
	Convert();
	Convert(Convert const& src);
	Convert(std::string arg);
	~Convert();
	void				printChar();
	void				printInt();
	void				printDouble();
	void				printFloat();
	Convert&			operator=(Convert const& src);
};


#endif
