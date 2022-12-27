#include "Span.hpp"

void	subjectTest(void) {
	std::cout << "\n\n---Test from subject pdf---\n" << std::endl;
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
	std::cout << "\n\n---Orthodox Canonique Test---\n" << std::endl;
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

int	main(void) {
	subjectTest();
	canoniqueTest();
	std::cout << "\n\n===Check Memory Leaks===\n" << std::endl;
	system("leaks a.out");
	return 0;
}
