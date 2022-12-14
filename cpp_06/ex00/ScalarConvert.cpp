#include "ScalarConvert.hpp"

// private member function;
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

bool	ScalarConvert::isOverflow(ScalarConvert::scalar_type type) {
	long double char_max = static_cast<long double>(std::numeric_limits<char>::max());
	long double char_min = static_cast<long double>(std::numeric_limits<char>::lowest());
	long double int_max = static_cast<long double>(std::numeric_limits<int>::max());
	long double int_min = static_cast<long double>(std::numeric_limits<int>::lowest());
	long double	float_max = static_cast<long double>(std::numeric_limits<float>::max());
	long double	float_min = static_cast<long double>(std::numeric_limits<float>::lowest());
	long double	double_max = static_cast<long double>(std::numeric_limits<double>::max());
	long double	double_min = static_cast<long double>(std::numeric_limits<double>::lowest());

	std::stringstream	ss(this->raw_input);
	long double			to_cmp;

	if (type == TYPE_CHAR) {
		ss >> to_cmp;
		if (char_min <= to_cmp && to_cmp <= char_max) {
			return false;
		}
	} else if (type == TYPE_INT) {
		ss >> to_cmp;
		if (int_min <= to_cmp && to_cmp <= int_max) {
			return false;
		}
	} else if (type == TYPE_FLOAT) {
		ss >> to_cmp;
		if (float_min <= to_cmp && to_cmp <= float_max) {
			return false;
		}
	} else {
		ss >> to_cmp;
		if (double_min <= to_cmp && to_cmp <= double_max) {
			return false;
		}
	}
	return true;
}

void	ScalarConvert::printChar(char to_print) {
	int	char_ascii = static_cast<int>(to_print);

	std::cout << "char: ";
	if (isOverflow(TYPE_CHAR) == false) {
		if (33 <= char_ascii && char_ascii <= 126) {
			std::cout << "'" << to_print << "'" << std::endl;
		} else {
			std::cout << "Non displayable" << std::endl;
		}
	} else {
		std::cout << "impossible" << std::endl;
	}
}

void	ScalarConvert::printInt(int to_print) {
	std::cout << "int: ";
	if (isOverflow(TYPE_INT) == false) {
		std::cout << to_print << std::endl;
	} else {
		std::cout << "impossible" << std::endl;
	}
}

void	ScalarConvert::printFloat(float to_print) {
	int	to_print_int = static_cast<int>(to_print);

	std::cout << "float: ";
	if (isOverflow(TYPE_FLOAT) == false) {
		if (to_print == to_print_int) {
			std::cout << to_print << ".0f" << std::endl;
		} else {
			std::cout << to_print << "f" << std::endl;
		}
	} else {
		std::cout << "impossible" << std::endl;
	}
}

void	ScalarConvert::printDouble(double to_print) {
	int	to_print_int = static_cast<int>(to_print);

	std::cout << "double: ";
	if (isOverflow(TYPE_DOUBLE) == false) {
		if (to_print == to_print_int) {
			std::cout << to_print << ".0" << std::endl;
		} else {
			std::cout << to_print << std::endl;
		}
	} else {
		std::cout << "impossible" << std::endl;
	}
}

void	ScalarConvert::printInfNan() {
	if (this->input_type == TYPE_INFNANF) {
		this->raw_input.erase(this->raw_input.length() - 1);
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << this->raw_input << "f" << std::endl;
	std::cout << "double: " << this->raw_input << std::endl;
}

void	ScalarConvert::strToChar() {
	std::stringstream	ss(this->raw_input);
	char				to_print;

	ss >> to_print;
	printChar(to_print);
	printInt(static_cast<int>(to_print));
	printFloat(static_cast<float>(to_print));
	printDouble(static_cast<double>(to_print));
}

void	ScalarConvert::strToCInt() {
	std::stringstream	ss(this->raw_input);
	int					to_print;

	if (isOverflow(TYPE_INT) == false) {
		ss >> to_print;
		printChar(static_cast<char>(to_print));
		printInt(to_print);
		printFloat(static_cast<float>(to_print));
		printDouble(static_cast<double>(to_print));
	} else {
		throw InputOutOfRange();
	}
}

void	ScalarConvert::strToFloat() {
	this->raw_input = this->raw_input.erase(this->raw_input.find('f'));
	std::stringstream	ss(this->raw_input);
	float				to_print;

	if (isOverflow(TYPE_FLOAT) == false) {
		ss >> to_print;
		printChar(static_cast<char>(to_print));
		printInt(static_cast<int>(to_print));
		printFloat(to_print);
		printDouble(static_cast<double>(to_print));
	} else {
		throw InputOutOfRange();
	}

}
void	ScalarConvert::strToDouble() {
	std::stringstream	ss(this->raw_input);
	double				to_print;

	if (isOverflow(TYPE_DOUBLE) == false) {
		ss >> to_print;
		printChar(static_cast<char>(to_print));
		printInt(static_cast<int>(to_print));
		printFloat(static_cast<float>(to_print));
		printDouble(to_print);
	} else {
		throw InputOutOfRange();
	}
}

// public member function;
ScalarConvert::ScalarConvert() : raw_input("42"), input_type(TYPE_INT) {
	std::cout << "ScalarConvert Default Constructor Called" << std::endl;
}

ScalarConvert::ScalarConvert(std::string raw_arg) : raw_input(raw_arg) {
	std::cout << "ScalarConvert Parameter Constructor Called" << std::endl;
	if (isInputChar() == false && isInputInfNan() == false) {
		if (isInputScalarType() == false) {
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
		strToChar();
		break;
	case TYPE_INT:
		strToCInt();
		break;
	case TYPE_FLOAT:
		strToFloat();
		break;
	case TYPE_DOUBLE:
		strToDouble();
		break;
	default:
		printInfNan();
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

const char*	ScalarConvert::InputOutOfRange::what() const throw() {
	return "the input is out of range";
}
