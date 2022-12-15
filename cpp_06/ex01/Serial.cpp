#include "Serial.hpp"

Serial::Serial() {
	std::cout << "Serial Default Constructor Called" << std::endl;
	this->data = new Data();
	this->data->index = 42;
	this->data->content = "Fourty-two";
}

Serial::Serial(Serial const& src) {
	std::cout << "Serial Copy Constructor Called" << std::endl;
	this->data = new Data();
	*this = src;
}

Serial::~Serial() {
	std::cout << "Serial Destructor Called" << std::endl;
	delete this->data;
}

Data*	Serial::getDataAddr(void) {
	return this->data;
}

Serial&	Serial::operator=(Serial const& src) {
	std::cout << "Serial Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		delete this->data;
		this->data = new Data();
		this->data->index = src.data->index;
		this->data->content = src.data->content;
	}
	return *this;
}

uintptr_t	serialize(Data* ptr) {
	uintptr_t	ret = reinterpret_cast<uintptr_t>(ptr);
	return ret;
}

Data* 		deserialize(uintptr_t raw) {
	Data*	ret = reinterpret_cast<Data*>(raw);
	return ret;
}
