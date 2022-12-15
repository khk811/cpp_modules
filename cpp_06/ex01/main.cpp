#include "Serial.hpp"

int	main(void) {
	Serial	test;

	// print Data* address from class Serial;
	std::cout << "\n\n" << std::endl;
	std::cout << "Data* address: " <<  test.getDataAddr() << "\n" << std::endl;

	// print result of serialize() - Data*;
	uintptr_t	data_addr_uint = serialize(test.getDataAddr());
	std::cout << "result of serialize(): " << data_addr_uint << "\n" << std::endl;


	// print result of deserialize() - uintptr_t;
	Data*		data_addr_ptr = deserialize(data_addr_uint);
	std::cout << "result of deserialize(): " << data_addr_ptr << "\n" << std::endl;
	std::cout << "\n\n" << std::endl;

	system("leaks a.out");
	return 0;
}
