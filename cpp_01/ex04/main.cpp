#include "whoSed.hpp"

int	main(int argc, char **argv) {
	whoSed	hi_im_sed;

	if (argc != 4)
		return 1;
	hi_im_sed.setFileName((std::string)argv[1]);
	hi_im_sed.setTargetString((std::string)argv[2]);
	hi_im_sed.setReplaceString((std::string)argv[3]);
	if (hi_im_sed.hasValidVariables() == false)
		return 1;
	hi_im_sed.putResultLineInFile();
	return 0;
}
