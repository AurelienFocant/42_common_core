#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	public:
		ScalarConverter	(void);
		ScalarConverter	(const ScalarConverter& src);
		ScalarConverter&	operator= (const ScalarConverter& rhs);
		~ScalarConverter	(void);

		static void	convert(std::string literal);

	private:
		static void	_outputEdgeCase(int i);
		static bool	_isChar(std::string s);
		static void	_outputChar(std::string s);
		static bool	_isInt(std::string s);
		static void	_outputInt(std::string s);
		static bool	_isFloat(std::string s);
		static void	_outputFloat(std::string s);
		static bool	_isDouble(std::string s);
		static void	_outputDouble(std::string s);
};

#endif // SCALARCONVERTER_HPP
