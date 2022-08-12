//#include "phonebook.hpp"
#include "contact.hpp"

int	main(void)
{
	Contact	c;

	c.SetIndex(1);
	c.SetFirstName("josh");
	c.SetLastName("bourdit");
	std::cout << c.GetIndex() << std::endl;
	std::cout << c.GetFirstName() << std::endl;
	std::cout << c.GetLastName() << std::endl;
	return (0);
}
