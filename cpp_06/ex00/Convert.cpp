#include "Convert.hpp"

Convert::Convert()
: raw_input("42"), string_stream(""), is_float(false) {
	std::cout << "Convert Default Constructor Called" << std::endl;
}

Convert::Convert(Convert const& src) {
	std::cout << "Convert Copy Constructor Called" << std::endl;
	*this = src;
}

Convert::Convert(std::string arg)
: raw_input(arg), string_stream(""), is_float(false) {
	std::cout << "Convert Parameter Constructor Called" << std::endl;
	if (this->raw_input.length() - 1 == this->raw_input.find('f')) {
		this->raw_input = this->raw_input.erase(this->raw_input.find('f'), 1);
		this->is_float = true;
	}
}

Convert::~Convert() {
	std::cout << "Convert Destructor Called" << std::endl;
}

void	Convert::printChar() {
}

void	Convert::printInt() {
}

void	Convert::printDouble() {
}

void	Convert::printFloat() {
}

Convert&	Convert::operator=(Convert const& src) {
	std::cout << "Convert Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->raw_input = src.raw_input;
		// this->string_stream = src.string_stream;
		this->is_float = src.is_float;
	}
	return *this;
}
