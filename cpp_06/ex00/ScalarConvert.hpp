#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <stdexcept>

class ScalarConvert
{
private:
	enum scalar_type
	{
		TYPE_CHAR = 0,
		TYPE_INT,
		TYPE_FLOAT,
		TYPE_DOUBLE,
		TYPE_INFNAN,
		TYPE_INFNANF,
		TYPE_ERROR
	};
	std::string					raw_input;
	ScalarConvert::scalar_type	input_type;
	bool						isInputInfNan();
	bool						isInputChar();
	void						countStringComponent(int& dot, int& f, int& non_digit);
	bool						isInputScalarType();
	void						printChar(char to_print);
	void						printInt(int to_print);
	void						printFloat(float to_print);
	void						printDouble(double to_print);
public:
	ScalarConvert();
	ScalarConvert(std::string raw_arg);
	ScalarConvert(ScalarConvert const& src);
	~ScalarConvert();
	void						printInputNType();
	void	strToChar();
	void	strToCInt();
	void	strToFloat();
	void	strToDouble();
	ScalarConvert&				operator=(ScalarConvert const& src);
	class InvalidInput : public std::exception
	{
		const char*				what() const throw();
	};
	class inputOutOfRange : public std::exception
	{
		const char*				what() const throw();
	};
};

#endif
