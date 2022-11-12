#ifndef WHOSED_HPP
#define WHOSED_HPP

#include <iostream>
#include <fstream>

class whoSed
{
private:
	std::string	file_name;
	std::string	target_string;
	std::string	to_replace;

	std::string	replaceTargetString(std::string single);

public:
	whoSed();
	~whoSed();

	bool		hasValidVariables();
	void		putResultLineInFile();
	void		setFileName(std::string name);
	void		setTargetString(std::string target);
	void		setReplaceString(std::string replace);
};

#endif
