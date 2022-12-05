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

void	Brain::printIdeaNAddr(unsigned int idx) const {
	if (idx >= this->idea_idx) {
		std::cout << "Error: Invalid input index" << std::endl;
	}
	else {
		std::cout << "the Idea: " << this->ideas[idx] << std::endl;
		std::cout << "the idea address: " << &(this->ideas[idx]) << std::endl;
	}
}

void	Brain::printAllIdeas() const {
	if (idea_idx == 0) {
		std::cout << "Error: Have no idea(s)" << std::endl;
	}
	else {
		for (unsigned int i = 0; i < idea_idx; i++)
		{
			std::cout << "idea[" << i << "]: " << this->ideas[i] << std::endl;
		}
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
	this->idea_idx = src.idea_idx;
	if (this != &src) {
		for (unsigned int i = 0; i < src.idea_idx; i++)
		{
			this->ideas[i] = src.ideas[i];
		}
	}
	return *this;
}
