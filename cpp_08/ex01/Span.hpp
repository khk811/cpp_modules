#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

class Span
{
private:
	std::vector<int>	storage;
	unsigned int		stored_num;
	unsigned int		storage_size;
public:
	Span();
	Span(unsigned int N);
	Span(Span const& src);
	~Span();
	void				addNumber(int to_add);
	template<typename Itr>
	void				addNumber(Itr i_begin, Itr i_end);
	int					shortestSpan();
	int					longestSpan();
	Span&				operator=(Span const& src);
	class	SpanAlreadyFull : public std::exception {
		const char*		what() const throw();
	};
	class	NotEnoughNumbers : public std::exception {
		const char*		what() const throw();
	};
};

template<typename Itr>
void					addNumber(Itr i_begin, Itr i_end) {
	for (Itr i_itr = i_begin; i_itr != i_end; i_itr++) {
		addNumber(*(i_itr));
	}
}

#endif
