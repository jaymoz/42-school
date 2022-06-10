#include "Replace.hpp"

int	main(int argc, char **argv) {

	if (argc != 4) {

		std::cout << "Invalid number of arguments" << std::endl;
		return 1;
	}

	Replace::ft_replace(argv[1], argv[2], argv[3]);

	return 0;
}