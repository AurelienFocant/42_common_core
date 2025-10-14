#include "PhoneBook.hpp"

#include <iostream>

int	main()
{
	PhoneBook	phonebook;
	std::string	input;

	while (true) {
		std::cout << "Input Phonebook command:\nADD -- SEARCH -- EXIT\n";
		std::getline(std::cin, input);

		if (std::cin.eof()) {
			std::cin.clear();
			break ;
		}

		if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT") {
			phonebook.exit();
		}
	}
}
