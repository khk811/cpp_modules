#include "ScalarConvert.hpp"

bool	ScalarConvert::isInputInfNan() {
	std::string	inf_nan[3] = {"-inf", "+inf", "nan"};
	std::string	inff_nanf[3] = {"-inff", "+inff", "nanf"};

	for (int i = 0; i < 3; i++)
	{
		if (this->raw_input == inf_nan[i]) {
			this->input_type = TYPE_INFNAN;
			return true;
		} else if (this->raw_input == inff_nanf[i]) {
			this->input_type = TYPE_INFNANF;
			return true;
		}
	}
	return false;
}

bool	ScalarConvert::isInputChar() {
	if (this->raw_input.length() == 1 && !isdigit(this->raw_input[0])) {
		this->input_type = TYPE_CHAR;
		return true;
	}
	return false;
}

void	ScalarConvert::countStringComponent(int& dot, int& f, int& non_digit) {
	size_t	idx = 0;

	if (!isdigit(this->raw_input[idx])) {
		if (this->raw_input[idx] == '.') {
			dot++;
		} else if (this->raw_input[idx] != '+' && this->raw_input[idx] != '-') {
			non_digit++;
		}
		idx++;
 	}
	for (size_t i = idx; i < raw_input.length(); i++)
	{
		if (!isdigit(this->raw_input[i])) {
			if (this->raw_input[i] == '.') {
				dot++;
			} else if (this->raw_input[i] == 'f' && i + 1 == raw_input.length()) {
				f++;
			} else {
				non_digit++;
			}
		}
	}
}

bool	ScalarConvert::isInputScalarType() {
	int		total_dot = 0;
	int		total_f = 0;
	int		total_non_digit = 0;

	countStringComponent(total_dot, total_f, total_non_digit);
	if (total_non_digit == 0 && total_dot <= 1 && total_f <= 1) {
		if (total_dot == 1) {
			if (total_f == 1) {
				this->input_type = TYPE_FLOAT;
			} else {
				this->input_type = TYPE_DOUBLE;
			}
		} else {
			this->input_type = TYPE_INT;
		}
		return true;
	} else {
		return false;
	}
}

ScalarConvert::ScalarConvert() : raw_input("42"), input_type(TYPE_INT) {
	std::cout << "ScalarConvert Default Constructor Called" << std::endl;
}

ScalarConvert::ScalarConvert(std::string raw_arg) : raw_input(raw_arg) {
	std::cout << "ScalarConvert Parameter Constructor Called" << std::endl;
	if (isInputChar() == false && isInputInfNan() == false) {
		if (isInputScalarType() == false) {
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
	case TYPE_INFNANF:
		std::cout << "input is Inff(or NaNf)" << std::endl;
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
