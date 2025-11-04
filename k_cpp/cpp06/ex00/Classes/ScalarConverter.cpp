#include "ScalarConverter.hpp"

#include <iostream>

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

bool	ScalarConverter::_isChar(std::string s)
{
	if (s.length() == 1 && std::isalpha(static_cast<unsigned char>(s[0])))
		return (true);
	return (false);
}

void	ScalarConverter::_outputChar(std::string s)
{
	unsigned char	c;

	c = static_cast<unsigned char>(s[0]);
	std::cout << "this is a char\n";
}

bool	ScalarConverter::_isFloat(std::string s)
{
	std::string::iterator it;
	std::string::iterator end;

	if (s.find("f") == s.length() - 1) {	/* if last char is 'f' */
		it = s.begin();
		end = s.end();
		while (it < end) {
			while (std::isdigit(static_cast<unsigned char>(it)))
				it++;
		}
		return (true);
	}
	return (false);
}

void	ScalarConverter::_outputFloat(std::string s)
{
	unsigned char	c;

	c = static_cast<unsigned char>(s[0]);
	std::cout << "this is a float\n";
}

void	ScalarConverter::convert(std::string literal)
{
	bool	(*isType[])(std::string) = {_isChar, _isFloat};
	void	(*outputType[])(std::string) = {_outputChar, _outputFloat};

	for (int i = 0; i < 2; i++) {
		if (isType[i](literal))
			outputType[i](literal);
	}
}
