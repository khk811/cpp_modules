#pragma once
#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
public:
	Harl();
	~Harl();
	void	complain(std::string level);
	void	(Harl::*func[4])(void);
};

#endif
