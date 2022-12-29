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
	try
	{
		std::vector<int>	og_vector;

		og_vector.push_back(11);
		og_vector.push_back(23);
		og_vector.push_back(42);
		og_vector.push_back(77);
		og_vector.push_back(98);

		Span	range_span = Span(og_vector.size());

		range_span.addNumberByRange(og_vector.begin(), og_vector.end());
		std::cout << "longest span range_span: " << range_span.longestSpan() << std::endl;
		std::cout << "shortest span range_span: " << range_span.shortestSpan() << std::endl;
		std::cout << "\n" << std::endl;

		Span	copy_span = Span(range_span);
		std::cout << "longest span copy_span: " << copy_span.longestSpan() << std::endl;
		std::cout << "shortest span copy_span: " << copy_span.shortestSpan() << std::endl;
		std::cout << "\n\n" << std::endl;
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
	std::cout << "\n---Check the duck_deque---\n" << std::endl;
	std::cout << "current duck_deque size: " << duck_deque.size() << "\n" << std::endl;
	std::cout << "duck_deque[0]: " << duck_deque[0] << std::endl;
	std::cout << "duck_deque[1234]: " << duck_deque[1234] << std::endl;
	std::cout << "duck_deque[9999]: " << duck_deque[9999] << std::endl;
	std::cout << "\n\n" << std::endl;
	Span	crazy_span = Span(10000);

	crazy_span.addNumberByRange(duck_deque.begin(), duck_deque.end());
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
	std::cout << "longestSpan() from duck_deque(size 10000): " << crazy_span.longestSpan() << std::endl;
	std::cout << "shortestSpan() from duck_deque(size 10000): " << crazy_span.shortestSpan() << std::endl;

	std::cout << "\n\n---you think this is not enough? => Test with 20000 numbers---\n" << std::endl;
	for (size_t i = 0; i < 10000; i++)
	{
		duck_deque.push_back(rand());
	}
	std::cout << "\n---Check the duck_deque---\n" << std::endl;
	std::cout << "current duck_deque size: " << duck_deque.size() << "\n" << std::endl;
	std::cout << "duck_deque[9999]: " << duck_deque[9999] << std::endl;
	std::cout << "duck_deque[12345]: " << duck_deque[12345] << std::endl;
	std::cout << "duck_deque[19999]: " << duck_deque[19999] << std::endl;
	std::cout << "\n\n" << std::endl;
	Span	double_crazy_span = Span(20000);

	double_crazy_span.addNumberByRange(duck_deque.begin(), duck_deque.end());
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
	std::cout << "longestSpan() from duck_deque(size 20000): " << double_crazy_span.longestSpan() << std::endl;
	std::cout << "shortestSpan() from duck_deque(size 20000): " << double_crazy_span.shortestSpan() << std::endl;
}

int	main(void) {
	subjectTest();
	canoniqueTest();
	goCrazyTest();
	std::cout << "\n\n===Check Memory Leaks===\n" << std::endl;
	system("leaks a.out");
	return 0;
}
