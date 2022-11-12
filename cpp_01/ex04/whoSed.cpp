#include "whoSed.hpp"

whoSed::whoSed() {
}

whoSed::~whoSed() {
}

std::string	whoSed::replaceTargetString(std::string single) {
	int			index = 0;
	size_t		found = single.find(this->target_string, index);
	std::string	ret;

	if (found != std::string::npos) {
		while (found != std::string::npos) {
			ret.append(single.substr(index, found - index));
			ret.append(this->to_replace);
			index = found + this->target_string.length();
			found = single.find(this->target_string, index);
		}
		ret.append(single.substr(index));
		return ret;
	}
	else
		return single;
}

bool	whoSed::hasValidVariables() {

	std::ifstream	ifs(this->file_name);

	if (ifs.good() == false) {
		std::cout << "Error: Cannot open infile" << std::endl;
		ifs.close();
		return false;
	}
	ifs.close();
	if (this->target_string == "") {
		std::cout << "Error: Empty target string" << std::endl;
		return false;
	}
	return true;
}

void	whoSed::putResultLineInFile() {
	std::ifstream	ifs(this->file_name);
	std::ofstream	ofs(this->file_name.append(".replace"));
	std::string		single_line;

	while (ifs.eof() == false) {
		std::getline(ifs, single_line);
		if (ifs.eof() == true)
			break ;
		ofs << this->replaceTargetString(single_line) << std::endl;
		single_line.clear();
	}
	ifs.close();
	ofs.close();
}

void	whoSed::setFileName(std::string name) {
	file_name = name;
}

void	whoSed::setTargetString(std::string target) {
	target_string = target;
}

void	whoSed::setReplaceString(std::string replace) {
	to_replace = replace;
}
