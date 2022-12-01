#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Default Constructor Called" << std::endl;
}

Brain::Brain(Brain const& src) {
	std::cout << "Brain Copy Constructor Called" << std::endl;
	*this = src;
}

Brain::~Brain() {
	std::cout << "Brain Destructor Called" << std::endl;
}

Brain&	Brain::operator=(Brain const& src) {
	std::cout << "Brain Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		for (size_t i = 0; i < 100; i++)
		{
			this->ideas[i] = src.ideas[i];
		}
	}
	return *this;
}
