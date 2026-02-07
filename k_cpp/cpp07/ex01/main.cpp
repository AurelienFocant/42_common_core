#include "iter.hpp"

#include <iostream>
#include <string>

void	myupper(std::string & s)
{
	std::string::iterator it;
	for (it = s.begin(); it != s.end(); it++) {
		std::cout << static_cast<char>(std::toupper(*it));
	}
	std::cout << std::endl;
}

void	increment_char(char & c)
{
	++c;
}

void	increment_int(int & i)
{
	++i;
}

template<typename T>
void increment(T & t)
{
	++t;
}

template<typename T>
void printAsChar(T const& t)
{
	if (t > 255)
		std::cout << "impossible";
	else if (!std::isprint(t))
		std::cout << "non displayable";
	else
		std::cout << static_cast<char>(t);
}

template<typename T>
void	printArray(T arr[], size_t size)
{
		for (size_t i = 0; i < size; ++i) {
			std::cout << arr[i];
		}
		std::cout << '\n';
}

int	main()
{
	{
		char	char_arr[]	= {'a', 'b', 'c'};
		int		int_arr[]	= {65, 66, 67};
		size_t	char_len	= sizeof(char_arr) / sizeof(char_arr[0]);
		size_t	int_len		= sizeof(int_arr) / sizeof(int_arr[0]);

		iter(char_arr, char_len, increment<char>);
		printArray(char_arr, char_len);

		iter(int_arr, int_len, increment<int>);
		printArray(int_arr,  int_len);
		std::cout << "---------------\n";


		iter(int_arr, int_len, printAsChar);
		std::cout << "\n---------------\n";
	}

	{
		std::string	s[] = {"hello", "world"};
		size_t	s_len	= sizeof(s) / sizeof(s[0]);
		iter(s, s_len, myupper);
	}
}
