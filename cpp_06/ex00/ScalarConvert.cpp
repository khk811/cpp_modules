#include "ScalarConvert.hpp"

bool	ScalarConvert::isInfNan(std::string input) {
	std::string	inf_nan[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	for (int i = 0; i < 6; i++)
	{
		if (input == inf_nan[i]) {
			this->input_type = TYPE_INFNAN;
			return true;
		}
	}
	return false;
}

bool	ScalarConvert::isChar(std::string input) {
	if (input.length() == 1 && !isdigit(input[0])) {
		this->input_type = TYPE_CHAR;
		return true;
	}
	return false;
}

bool	ScalarConvert::isDot(char target_char) {
	if (target_char == '.') {
		return true;
	}
	return false;
}

bool	ScalarConvert::isValidChar(char first_char) {
	if (first_char == '+' || first_char == '-') {
		return true;
	} else  if (isdigit(first_char) || isDot(first_char)) {
		return true;
	}
	return false;
}

bool	ScalarConvert::isScalarType(std::string input) {
	size_t	idx = 0;
	int		total_dot = 0;

	if (isValidChar(input[idx]) == false) {
		return false;
	}
	if (isDot(input[idx]) == true) {
		total_dot++;
	}
	idx++;
	for (size_t i = idx; i < input.length(); i++)
	{
		// for 문 안에 심각한 문제가 있음.
		// 지나치게 덩어리가 크다!!
		if (!isdigit(input[i])) {
			if (isDot(input[i])) {
				total_dot++;
				if (total_dot != 1) {
					return false;
				}
			} else if (input[i] == 'f') {
				if (i != input.length() - 1) {
					return false;
				} else {
					this->input_type = TYPE_FLOAT;
					return true;
				}
			} else {
				return false;
			}
		}
	}
	if (total_dot == 0) {
		this->input_type = TYPE_INT;
	} else {
		this->input_type = TYPE_DOUBLE;
	}
	return true;
}

ScalarConvert::ScalarConvert() : raw_input("42"), input_type(TYPE_INT) {
	std::cout << "ScalarConvert Default Constructor Called" << std::endl;
}

ScalarConvert::ScalarConvert(std::string raw_arg) : raw_input(raw_arg) {
	std::cout << "ScalarConvert Parameter Constructor Called" << std::endl;
	if (isChar(raw_arg) == false && isInfNan(raw_arg) == false) {
		if (isScalarType(raw_arg) == false) {
			this->input_type = TYPE_ERROR;
			throw InvalidInput();
		}
	}
}

ScalarConvert::ScalarConvert(ScalarConvert const& src) {
	std::cout << "ScalarConvert Copy Constructor Called" << std::endl;
	*this = src;
}

ScalarConvert::~ScalarConvert() {
	std::cout << "ScalarConvert Destructor Called" << std::endl;
}

void	ScalarConvert::printInputNType() {
	switch (this->input_type)
	{
	case TYPE_CHAR:
		std::cout << "input is Char" << std::endl;
		break;
	case TYPE_INT:
		std::cout << "input is Int" << std::endl;
		break;
	case TYPE_FLOAT:
		std::cout << "input is Float" << std::endl;
		break;
	case TYPE_DOUBLE:
		std::cout << "input is Double" << std::endl;
		break;
	case TYPE_INFNAN:
		std::cout << "input is Inf(or NaN)" << std::endl;
		break;
	default:
		throw InvalidInput();
		break;
	}
}

ScalarConvert&	ScalarConvert::operator=(ScalarConvert const& src) {
	std::cout << "ScalarConvert Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->raw_input = src.raw_input;
		this->input_type = src.input_type;
	}
	return *this;
}

const char*	ScalarConvert::InvalidInput::what() const throw() {
	return "the input is invalid";
}
