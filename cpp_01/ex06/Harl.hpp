#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
private:
	enum level
	{
		LEVEL_DEBUG,
		LEVEL_INFO,
		LEVEL_WARNING,
		LEVEL_ERROR,
		DEFAULT
	};

	void		debug();
	void		info();
	void		warning();
	void		error();
	void		defaultComplain();
	enum level	checkInputLevel(std::string level);

public:
	Harl();
	~Harl();
	void		complain(std::string level);
};

#endif
