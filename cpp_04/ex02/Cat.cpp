#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat Default Constructor Called" << std::endl;
	this->type = "Cat";
	this->cat_brain = new Brain();
}

Cat::Cat(Cat const& src) {
	std::cout << "Cat Copy Constructor Called" << std::endl;
	this->cat_brain = new Brain();
	*this = src;
}

Cat::~Cat() {
	delete this->cat_brain;
	std::cout << "Cat Destructor Called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Cat makeSound() Called" << std::endl;
	std::cout << "Meow Meow" << std::endl;
}

Brain*	Cat::getBrain() const {
	return this->cat_brain;
}

Cat&	Cat::operator=(Cat const& src) {
	std::cout << "Cat Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->type = src.type;
		*(this->cat_brain) = *(src.cat_brain);
		/*

		이 *()이게 개 중요한 이유
		cat_brain은 Brain * 형 데이터에여
		*하면 자료형이 Brain으로 바뀝니다.
		그러면 대입 연산을 시켰을때, Brain 클래스의 대입연산이 일어나게 됩니다.
		양쪽에 *() 이거 안해주면 포인터 = 포인터 형태라서, 그냥 포인터가 복붙되게 되는데
		*() 해주면, 브레인 몸체 = 브레인 몸체 가 되어서 아까 위에서 정의한 내용복사가 일어나게 되는거죠

		---
		그니까 지금 상황이 객체1, 객체2(src)가 있고,
		객체 1의 Brain을 객체2의 Brain으로 ???
		그러면 Brain은 하나만 있는건가요?
		방금 제가 생성자 전부에서 new Brain을 시켜주는걸로 코드를 바꿨어요
		그다음에, Cat 클래스 단위의 대입이 일어나는데, 거기서 다시 Brain 클래스 단위의 대입이 일어납니다.
		그러면 Brain Class 단위의 =를 오버로딩 해놨던 그 작업이 드가는거에요

		---
		저기 지금 std::string을 그냥 = 로 처리했잖아요
		그러면 그냥 복사가 int 처럼 ㅇ어디 std:;string
		네 저건 std::string 클래스 자체에서 =를 정의하기를 저렇게 되어있을겁니다.


		*/
		// need deep copy of brain arr;
	}
	return *this;
}
