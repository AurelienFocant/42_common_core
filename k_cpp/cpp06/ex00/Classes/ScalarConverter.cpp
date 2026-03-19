#include "ScalarConverter.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <cfloat>

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	*this = src;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& rhs)
{
	if (this != &rhs) {
	}
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
}

void	ScalarConverter::_outputEdgeCase(int i)
{
	std::string outputs[4];

	switch (i)
	{
	case (0):
	case (1):
		outputs[0] = "impossible";
		outputs[1] = "impossible";
		outputs[2] = "nanf";
		outputs[3] = "nan";
		break;
	case (2):
	case (3):
		outputs[0] = "impossible";
		outputs[1] = "impossible";
		outputs[2] = "+inff";
		outputs[3] = "+inf";
		break;
	case (4):
	case (5):
		outputs[0] = "impossible";
		outputs[1] = "impossible";
		outputs[2] = "-inff";
		outputs[3] = "-inf";
		break;
	}

	std::cout << "char:	"		<< outputs[0] << '\n';
	std::cout << "int:	"		<< outputs[1] << '\n';
	std::cout << "float:	"	<< outputs[2] << '\n';
	std::cout << "double:	"	<< outputs[3] << std::endl;
}

bool ScalarConverter::_isChar(std::string s)
{
	if (s.length() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]))
		return (true);
	return (false);
}

void ScalarConverter::_outputChar(std::string s)
{
	std::stringstream ss(s);
	char c;

	ss.get(c);
	if (std::isprint(c))
		std::cout << "char:	" << c << '\n';
	else
		std::cout << "char:	Non displayable\n";
	std::cout << "int:	"		<< static_cast<int>(c) << '\n';
	std::cout << "float:	"	<< static_cast<float>(c) << ".0f\n";
	std::cout << "double:	"	<< static_cast<double>(c) << ".0" << std::endl;
}

bool ScalarConverter::_isInt(std::string s)
{
	std::stringstream ss(s);
	int n;
	long l;
	char c;

	if (ss >> l && (l < INT_MIN || l > INT_MAX))
		return (false);
	if (ss >> n && !(ss >> c))
		return (true);
	return (false);
}

void ScalarConverter::_outputInt(std::string s)
{
	std::stringstream ss(s);
	int n;

	ss >> n;
	if (n < 0 || n > 127)
		std::cout << "char:	impossible\n";
	else if (std::isprint(static_cast<char>(n)))
		std::cout << "char:	" << static_cast<char>(n) << '\n';
	else
		std::cout << "char:	Non displayable\n";
	std::cout << "int:	" << n << '\n';
	std::cout << "float:	" << static_cast<float>(n) << ".0f\n";
	std::cout << "double:	" << static_cast<double>(n) << ".0\n";
}

bool ScalarConverter::_isFloat(std::string s)
{
	if (s[s.length() - 1] != 'f') /* If last char is not f, this isn't a floar */
		return (false);

	{
		std::stringstream ss(s.substr(0, s.length() - 1)); // take out the 'f'
		float f;
		char c;

		if (ss >> f && !(ss >> c)) // we stream the float part into a float. If there is no char left, we good
			return (true);
		return (false);
	}
}

void ScalarConverter::_outputFloat(std::string s)
{
	std::stringstream ss(s.substr(0, s.length() - 1)); // take out the 'f'
	float f;

	ss >> f;
	if (f < 0 || f > 127)
		std::cout << "char:	impossible\n";
	else if (std::isprint(static_cast<char>(f)))
		std::cout << "char:	" << static_cast<char>(f) << '\n';
	else
		std::cout << "char:	Non displayable\n";

	if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
		std::cout << "int:	impossible\n";
	else
		std::cout << "int:	" << static_cast<int>(f) << '\n';

	if (f == static_cast<int>(f))
		std::cout << "float:	" << f << ".0f\n";
	else
		std::cout << "float:	" << f << "f\n";

	if (f == static_cast<int>(f))
		std::cout << "double:	" << static_cast<double>(f) << ".0" << std::endl;
	else
		std::cout << "double:	" << static_cast<double>(f) << std::endl;
}

bool ScalarConverter::_isDouble(std::string s)
{
	std::stringstream ss(s);
	double d;
	char c;

	if (ss >> d && !(ss >> c))
		return (true);
	return (false);
}

void ScalarConverter::_outputDouble(std::string s)
{
	std::stringstream ss(s);
	double d;

	ss >> d;

	if (d < 0 || d > 127)
		std::cout << "char:	impossible\n";
	else if (std::isprint(static_cast<char>(d)))
		std::cout << "char:	" << static_cast<char>(d) << '\n';
	else
		std::cout << "char:	Non displayable\n";

	if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
		std::cout << "int:	impossible\n";
	else
		std::cout << "int:	" << static_cast<int>(d) << '\n';

	if (d < -FLT_MAX || d > FLT_MAX)
		std::cout << "float:	impossible\n";
	else
	{
		if (d == static_cast<int>(d))
			std::cout << "float:	" << d << ".0f\n";
		else
			std::cout << "float:	" << d << "f\n";
	}

	if (d == static_cast<int>(d))
		std::cout << "double:	" << d << ".0" << std::endl;
	else
		std::cout << "double:	" << (d) << std::endl;
}

void ScalarConverter::convert(std::string literal)
{
	{
		std::string edgeCases[] = {
			"nan", "nanf",
			"+inf", "+inff",
			"-inf", "-inff"};

		for (int i = 0; i < 6; i++)
		{
			if (literal == edgeCases[i])
			{
				_outputEdgeCase(i);
				return;
			}
		}
	}

	{
		bool (*isType[])(std::string)		= {_isChar, _isInt, _isFloat, _isDouble};
		void (*outputType[])(std::string)	= {_outputChar, _outputInt, _outputFloat, _outputDouble};

		for (int i = 0; i < 4; i++)
		{
			if (isType[i](literal))
			{
				outputType[i](literal);
				return;
			}
		}
	}

	{
		std::cout
			<< "The string litteral isn't of any known type in cpp\n";
		return;
	}
}
