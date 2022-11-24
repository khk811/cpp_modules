#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
public:
	ScavTrap();
	ScavTrap(ScavTrap const& src);
	ScavTrap(std::string scav_name);
	~ScavTrap();
	void			attack(const std::string& target);
	void 			guardGate();
	ScavTrap&		operator=(ScavTrap const& src);
};

#endif

// deep copy 그
// 포인터나 참조같은걸로, 동일한 대상을 가르키는것이 아니라,
// **"완전 개별적인 메모리를 가르키도록 복사 (하나 더만듬)하는걸 깊은복사라하고요"**
// const 복사 하면 되잖아
// 얕은복사는 속성끼리 동일한 메모리를 가르키고 있어서
// 얕은복사한 얘들 한명 바꾸면은 다른얘도 바뀝니다.
// 나는 어떻게 했냐면
// 다른 CPP과제에서도 const인 어트리뷰트들 있단말이야
// 그럼 이것들도 copy operator 해야하잖아
// 그런데 const는 애초에 내가 절대 안바꾼다고 선언한거잖아
// 그래서 바뀌면 안되는거야
// 다른(안 const인 애들) 어트리뷰트는 복사해야하지만
// 복사생성자가 아닌 copy operator는 const인 어트리뷰트는 복사할수 없어

// 쩨이최가 이리 설명함

/*

그러면 그냥 경)아무것도(축 안함 해도 되는거임?

잠깐 티타임이나 가질까
와플 사논거 나누먹을래?


*/

