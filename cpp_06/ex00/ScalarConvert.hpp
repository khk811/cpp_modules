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
		TYPE_INFNANF
	};
	std::string					raw_input;
	ScalarConvert::scalar_type	input_type;
	bool						isInputInfNan();
	bool						isInputChar();
	void						countStringComponent(int& dot, int& f, int& non_digit);
	bool						isInputScalarType();
	bool						isOverflow(ScalarConvert::scalar_type type);
	void						printChar(char to_print);
	void						printInt(int to_print);
	void						printFloat(float to_print);
	void						printDouble(double to_print);
	void						printInfNan();
	void						strToChar();
	void						strToCInt();
	void						strToFloat();
	void						strToDouble();
public:
	ScalarConvert();
	ScalarConvert(std::string raw_arg);
	ScalarConvert(ScalarConvert const& src);
	~ScalarConvert();
	void						printInputNType();
	ScalarConvert&				operator=(ScalarConvert const& src);
	class InvalidInput : public std::exception
	{
		const char*				what() const throw();
	};
	class InputOutOfRange : public std::exception
	{
		const char*				what() const throw();
	};
};

#endif
