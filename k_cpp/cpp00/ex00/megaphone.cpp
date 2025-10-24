#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	for (int i = 1; i < argc; i++) {
		std::string s = argv[i];
		for (long unsigned j = 0; j < s.length(); j++) {
			std::cout << static_cast<char>(std::toupper(argv[i][j]));
		}
	}
	std::cout << std::endl;
	return (0);
}
