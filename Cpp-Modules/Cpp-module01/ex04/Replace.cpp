#include "Replace.hpp"

void	Replace::ft_replace(std::string const &filename, char *s1, char *s2) {

	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		line;

	infile.open(filename);
	if (!infile) {

		std::cout << "couldn't open the input file" << std::endl;
		return;
	}
	outfile.open(filename + ".replace", std::ios::trunc);
	if (!outfile) {

		infile.close();
		std::cout << "couldn't open the output file" << std::endl;
		return;
	}
	while (std::getline(infile, line)) {

		size_t	n = strlen(s1);
		size_t	pos = line.find(s1);

		while (pos != std::string::npos) {

			line.erase(pos, n);
			line.insert(pos, s2);

			pos += strlen(s2);
			pos = line.find(s1, pos, n);
		}

		outfile << line;
		if (!infile.eof())
			outfile << '\n';
	}
	infile.close();
	outfile.close();
}
