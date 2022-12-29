#include "Span.hpp"
#include <deque>
#include <cstdlib>
#include <ctime>

void	subjectTest(void) {
	std::cout << "\n\n===Test from subject pdf===\n" << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	canoniqueTest(void) {
	std::cout << "\n\n===Orthodox Canonique form Test==\n" << std::endl;
	try
	{
		Span default_span = Span();

		default_span.addNumber(10);
		default_span.addNumber(11);
		std::cout << default_span.longestSpan() << std::endl;
		std::cout << default_span.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	goCrazyTest(void) {
	std::cout << "\n\n===Go Crazy! Go Stupid!!===\n" << std::endl;
	std::cout << "\n---Test with 10000 numbers---\n" << std::endl;
	std::deque<int>	duck_deque;

	srand((unsigned int)time(NULL));
	for (size_t i = 0; i < 10000; i++)
	{
		duck_deque.push_back(rand());
	}

	std::cout << "current duck_deque size: " << duck_deque.size() << std::endl;
	std::cout << "duck_deque[0]: " << duck_deque[0] << std::endl;
	std::cout << "duck_deque[9999]: " << duck_deque[9999] << std::endl;
	Span	crazy_span = Span(10000);

	crazy_span.addNumber(duck_deque.begin(), duck_deque.end());
	try
	{
		std::cout << "\ndoes crazy_span really have 10000 nums??" << std::endl;
		std::cout << "\n=> let's try to add just one more num, 42" << std::endl;
		crazy_span.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << "\n\n" << std::endl;
	}
	std::cout << crazy_span.longestSpan() << std::endl;
	std::cout << crazy_span.shortestSpan() << std::endl;

	std::cout << "\n\n---you think this is not enough? => Test with 20000 numbers---\n" << std::endl;
	for (size_t i = 0; i < 10000; i++)
	{
		duck_deque.push_back(rand());
	}
	Span	double_crazy_span = Span(20000);

	double_crazy_span.addNumber(duck_deque.begin(), duck_deque.end());
	try
	{
		std::cout << "\ndoes double_crazy_span really have 20000 nums??" << std::endl;
		std::cout << "\n=> let's try to add just one more num, 42" << std::endl;
		double_crazy_span.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << "\n\n" << std::endl;
	}
	std::cout << double_crazy_span.longestSpan() << std::endl;
	std::cout << double_crazy_span.shortestSpan() << std::endl;
}

int	main(void) {
	subjectTest();
	canoniqueTest();
	goCrazyTest();
	std::cout << "\n\n===Check Memory Leaks===\n" << std::endl;
	system("leaks a.out");
	return 0;
}
