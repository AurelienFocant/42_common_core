#include "myTemplates.hpp"

#include <iostream>
#include <string>

void	resetVariables(std::string & s1, std::string & s2, int & n1, int & n2, float & f1, float & f2)
{
	s1 = "string1";
	s2 = "string2";
	n1 = 1;
	n2 = 2;
	f1 = 1.1;
	f2 = 2.2;
}

int	main()
{
	std::string	s1;
	std::string	s2;
	int			n1;
	int			n2;
	float		f1;
	float		f2;

	std::cout << "---------------------\n";
	resetVariables(s1, s2, n1, n2, f1, f2);
	std::cout << "My swap:\n";
	::swap<std::string>(s1, s2);
	std::cout << s1 << '\n';
	::swap<int>(n1, n2);
	std::cout << n1 << '\n';
	::swap<float>(f1, f2);
	std::cout << f1 << '\n';
	std::cout << "---------------------\n";

	std::cout << "std::swap:\n";
	resetVariables(s1, s2, n1, n2, f1, f2);
	std::swap<std::string>(s1, s2);
	std::swap<int>(n1, n2);
	std::swap<float>(f1, f2);
	std::cout << s1 << '\n';
	std::cout << n1 << '\n';
	std::cout << f1 << '\n';
	std::cout << "---------------------\n";

	std::cout << "---------------------\n";
	resetVariables(s1, s2, n1, n2, f1, f2);
	std::cout << "My min:\n";
	std::cout << ::min<std::string>(s1, s2) << '\n';
	std::cout << ::min<int>(n1, n2) << '\n';
	std::cout << ::min<float>(f1, f2) << '\n';
	std::cout << "---------------------\n";

	std::cout << "std::min:\n";
	resetVariables(s1, s2, n1, n2, f1, f2);
	std::cout << std::min<std::string>(s1, s2) << '\n';
	std::cout << std::min<int>(n1, n2) << '\n';
	std::cout << std::min<float>(f1, f2) << '\n';
	std::cout << "---------------------\n";

	std::cout << "---------------------\n";
	resetVariables(s1, s2, n1, n2, f1, f2);
	std::cout << "My max:\n";
	std::cout << ::max<std::string>(s1, s2) << '\n';
	std::cout << ::max<int>(n1, n2) << '\n';
	std::cout << ::max<float>(f1, f2) << '\n';
	std::cout << "---------------------\n";

	std::cout << "std::max:\n";
	resetVariables(s1, s2, n1, n2, f1, f2);
	std::cout << std::max<std::string>(s1, s2) << '\n';
	std::cout << std::max<int>(n1, n2) << '\n';
	std::cout << std::max<float>(f1, f2) << '\n';
	std::cout << "---------------------\n";
}
