#include "Serial.hpp"

void	serialization_test(void) {
	Serial	test;

	// print Data* address from class Serial;
	std::cout << "\n\n" << std::endl;
	std::cout << "Data* address: " <<  test.getDataAddr() << "\n" << std::endl;
	Data*	test_data = test.getDataAddr();
	std::cout << "test_data index: " << test_data->index << std::endl;
	std::cout << "test_data contetn: " << test_data->content << std::endl;
	std::cout << "\n" << std::endl;

	// print result of serialize() - Data*;
	uintptr_t	data_addr_uint = serialize(test.getDataAddr());
	std::cout << "result of serialize(): " << data_addr_uint << "\n" << std::endl;


	// print result of deserialize() - uintptr_t;
	Data*		data_addr_ptr = deserialize(data_addr_uint);
	std::cout << "result of deserialize(): " << data_addr_ptr << "\n" << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "data_addr_ptr index: " << data_addr_ptr->index << std::endl;
	std::cout << "data_addr_ptr contetn: " << data_addr_ptr->content << std::endl;
	std::cout << "\n\n" << std::endl;
}

int	main(void) {
	serialization_test();
	system("leaks a.out");
	return 0;
}
