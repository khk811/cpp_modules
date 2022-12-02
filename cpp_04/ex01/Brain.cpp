#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Default Constructor Called" << std::endl;
	this->idea_idx = 0;
}

Brain::Brain(Brain const& src) {
	std::cout << "Brain Copy Constructor Called" << std::endl;
	*this = src;
}

Brain::~Brain() {
	std::cout << "Brain Destructor Called" << std::endl;
}

std::string	Brain::getIdea(unsigned int target_idx) const {
	if (this->idea_idx >= target_idx) {
		return this->ideas[target_idx];
	}
	else {
		return NULL;
	}
}

void	Brain::printAllIdeas() const {
	for (unsigned int i = 0; i < idea_idx; i++)
	{
		std::cout << "idea[" << i << "]: " << this->ideas[i] << std::endl;
	}
}

void	Brain::setIdea(std::string idea) {
	if (this->idea_idx < 100) {
		this->ideas[this->idea_idx] = idea;
		this->idea_idx++;
	}
	else {
		std::cout << "Error: the brain is full" << std::endl;
	}
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
