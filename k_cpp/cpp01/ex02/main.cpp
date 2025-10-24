#include <iostream>

int	main()
{
	std::string	s = "HI THIS IS BRAIN";
	std::string	*stringPTR;
	std::string	&stringREF = s;

	stringPTR = &s;

	std::cout	<< "the string's adress is "<< &s << '\n'
				<< "stringPTR adress is "	<< &stringPTR << '\n'
				<< "stringREF adress is "	<< &stringREF << '\n' << std::endl;

	std::cout	<< "the string is "			<< s << '\n'
				<< "stringPTR points to "	<< *stringPTR << '\n'
				<< "stringREF refers to "	<< stringREF << std::endl;

	return (0);
}
