#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

};

#endif

// deep copy 그
// 포인터나 참조같은걸로, 동일한 대상을 가르키는것이 아니라 완전 개별적인 메모리를 가르키도록 복사 (하나 더만듬)하는걸 깊은복사라하고요
// 얕은복사는 속성끼리 동일한 메모리를 가르키고 있어서
// 얕은복사한 얘들 한명 바꾸면은 다른얘도 바뀝니다.
