#include <iostream>
#include <fstream>

int	main(int argc, char **argv) {
	if (argc != 4)
		return (1);
	std::string		file_name = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	std::ifstream	ifs(file_name);
	std::ofstream	ofs(file_name.append(".replace"));
	std::string		single_line;
	std::string		output_line;
	while (ifs.eof() == false) {
		std::getline(ifs, single_line);
		if (ifs.eof() == true)
			break ;
		int			index = 0;
		std::size_t	found = single_line.find(s1, index);
		if (found != std::string::npos) {
			while (found != std::string::npos) {
				output_line.append(single_line.substr(index, found - index));
				output_line.append(s2);
				index = found + s1.length();
				found = single_line.find(s1, index);
			}
			output_line.append(single_line.substr(index));
		}
		else
			output_line.append(single_line);
		ofs << output_line << std::endl;
		output_line.clear();
	}
	ifs.close();
	ofs.close();
	return 0;
}
