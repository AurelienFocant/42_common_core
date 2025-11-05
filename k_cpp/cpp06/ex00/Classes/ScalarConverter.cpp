#include "ScalarConverter.hpp"

#include <iostream>
#include <sstream>

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	(void) src;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& rhs)
{
	if (this != &rhs) {
	}
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter Object Destroyed" << std::endl;
}

void	ScalarConverter::_outputEdgeCase(int i)
{
	switch(i) {
		case (0):
			std::cout << "nan" << std::endl;
			break;
		case (1):
			std::cout << "+inf\n";
			break;
	}
}

bool	ScalarConverter::_isChar(std::string s)
{
	// if (s.length() == 1 && std::isalpha(static_cast<unsigned char>(s[0])))
	if (s.length() == 1 && std::isalpha(s[0]))
		return (true);
	return (false);
}

void	ScalarConverter::_outputChar(std::string s)
{
	char	c;
	int		n;
	float	f;
	double	d;


	c = static_cast<char>(s[0]);
	n = static_cast<int>(s[0]);
	f = static_cast<float>(s[0]);
	d = static_cast<double>(s[0]);

	std::cout << c << '\n';
	std::cout << n << '\n';
	std::cout << f << '\n';
	std::cout << d << std::endl;
}

bool	ScalarConverter::_isInt(std::string s)
{
	std::stringstream	ss(s);
	int		n;
	char	c;

	if (ss >> n && !(ss >> c))
		return (true);
	return (false);
}

void	ScalarConverter::_outputInt(std::string s)
{
	(void) s;
}

bool	ScalarConverter::_isFloat(std::string s)
{
	if (s[s.length() - 1] != 'f')	/* If last char is not f, this isn't a floar */
		return (false);

	{
		std::stringstream	ss(s.substr(0, s.length() - 1));	// take out the 'f'
		float	f;
		char	c;

		if (ss >> f && !(ss >> c))	// we stream the float part into a float. If there is no char left, we good
			return (true);
		return (false);
	}
}

void	ScalarConverter::_outputFloat(std::string s)
{
	(void) s;
}

bool	ScalarConverter::_isDouble(std::string s)
{
		std::stringstream	ss(s);
		double	d;
		char	c;

		if (ss >> d && !(ss >> c))
			return (true);
		return (false);
}

void	ScalarConverter::_outputDouble(std::string s)
{
	(void) s;
}

void	ScalarConverter::convert(std::string literal)
{
	{
		std::string	edgeCases[] = {
			"nan", "nanf",
			"+inf", "+inff",
			"-inf", "-inff"
		};

		for (int i = 0; i < 6; i++) {
			if (literal == edgeCases[i]) {
				_outputEdgeCase(i);
				return ;
			}
		}
	}

	{
		bool (*isType[])	(std::string) = {_isChar, _isInt, _isFloat, _isDouble};
		void (*outputType[])(std::string) = {_outputChar, _outputInt, _outputFloat, _outputDouble};

		for (int i = 0; i < 4; i++) {
			if (isType[i](literal)) {
				outputType[i](literal);
				return ;
			}
		}
	}

	{
		std::cout
			<< "The string litteral isn't of any known type in cpp\n";
		return ;
	}
}
