#include "Span.hpp"

Span::Span() : stored_num(0), storage_size(1) {
	std::cout << "Span Default Constructor Called" << std::endl;
}

Span::Span(unsigned int N) : stored_num(0), storage_size(N) {
	std::cout << "Span Parameter Constructor Called" << std::endl;
}

Span::Span(Span const& src) {
	std::cout << "Span Copy Constructor Called" << std::endl;
	*this = src;
}

Span::~Span() {
	std::cout << "Span Destructor Called" << std::endl;
}

void	Span::addNumber(int to_add) {
	if (this->stored_num < this->storage_size) {
		this->stored_num++;
		storage.push_back(to_add);
	} else {
		throw SpanAlreadyFull();
	}
}

int		Span::shortestSpan() {
	std::vector<int>	v_sorted = this->storage;

	std::sort(v_sorted.begin(), v_sorted.end());

	int	shortest_span = 0;

	if (stored_num > 1) {
		for (std::vector<int>::iterator itr = v_sorted.begin(); \
		itr != v_sorted.end(); itr++) {
			if (itr == v_sorted.begin()) {
				shortest_span = *(itr + 1) - *(itr);
			} else {
				if (shortest_span > (*(itr) - *(itr - 1))) {
					shortest_span = *(itr) - *(itr - 1);
				}
			}
		}
		return shortest_span;
	} else {
		throw NotEnoughNumbers();
	}
}

int		Span::longestSpan() {
	if (stored_num > 1) {
		int	max_value = *(std::max_element(this->storage.begin(), this->storage.end()));
		int	min_value = *(std::min_element(this->storage.begin(), this->storage.end()));
		return max_value - min_value;
	} else {
		throw NotEnoughNumbers();
	}
}

Span&	Span::operator=(Span const& src) {
	std::cout << "Span Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->storage = src.storage;
		this->stored_num = src.stored_num;
		this->storage_size = src.storage_size;
	}
	return *this;
}

const char*	Span::SpanAlreadyFull::what() const throw() {
	return "Span storage is already full";
}

const char*	Span::NotEnoughNumbers::what() const throw() {
	return "Span doesn't have enough numbers";
}
