#include <iostream>
#include <fstream>
#include <cstdlib>

void	error_exit(std::string s)
{
	std::cerr << s << std::endl;
	exit(EXIT_FAILURE);
}

void	miniSed(std::ifstream &infile, std::ofstream &outfile, char **av)
{
	std::string	line;
	std::string	s1;
	std::string	s2;

	s1 = av[2];
	s2 = av[3];

	while (std::getline(infile, line)) {
		std::string	res;
		std::size_t	found;
		std::size_t	pos = 0;

		while ((found = line.find(s1, pos)) != std::string::npos) {
			res += line.substr(pos, found - pos);
			res += s2;
			pos = found + s1.length();
		}
		res += line.substr(pos);
		outfile << res << '\n';
	}
}

int	main(int ac, char **av)
{
	std::string	file1;
	std::string	file2;


	if (ac != 4)
		error_exit("Usage");

	file1 = av[1];
	file2 = file1 + ".replace";

	std::ifstream infile(file1.c_str());
	if (!infile.is_open()) 
		error_exit("Problem opening infile");
	std::ofstream outfile(file2.c_str());
	if (!outfile.is_open()) {
		// infile.close();
		error_exit("Problem opening outfile");
	}

	miniSed(infile, outfile, av);

	// infile.close();
	// outfile.close();
	return (0);
}
