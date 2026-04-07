#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <ctime>
#include <map>

int	error_and_exit(std::string msg)
{
	std::cerr << msg << std::endl;
	std::exit(1);
}

bool	validateFirstLine(std::string const& line)
{
			size_t comma = line.find(",");
			if (comma == std::string::npos || comma != line.find_last_of(","))
				return (false);
			if (line.substr(0, comma) != "date")
				return (false);
			if (line.substr(comma+ 1, line.size()) != "exchange_rate")
				return (false);

			return (true);
}

std::time_t	validateDate(std::string const& date, std::ifstream & csvfile)
{
	std::tm tm;
	std::memset(&tm, 0, sizeof(std::tm));
	tm.tm_isdst = -1;
	{
		std::stringstream	ss(date);
		ss >> std::noskipws;

		int	year;
		int	month;
		int	day;
		char c;

		ss >> year;
		if (ss.fail() || !(ss >> c) || c != '-') {
			csvfile.close();
			error_and_exit("Invalid year");
		}
		ss >> month;
		if (ss.fail() || !(ss >> c) || c != '-') {
			csvfile.close();
			error_and_exit("Invalid month");
		}
		ss >> day;
		if (ss.fail() || !day || ss >> c) {
			csvfile.close();
			error_and_exit("Invalid day");
		}

		tm.tm_year	= year - 1900;
		tm.tm_mon	= month - 1;
		tm.tm_mday	= day;

		if (tm.tm_year <= 0 || tm.tm_mon < 0 || tm.tm_mday <= 0) {
			csvfile.close();
			error_and_exit("Invalid date");
		}
	}

	std::tm	copy = tm;
	std::time_t	t = std::mktime(&tm);
	if	(	tm.tm_year	!= copy.tm_year
		||	tm.tm_mon	!= copy.tm_mon
		||	tm.tm_mday	!= copy.tm_mday) {
		csvfile.close();
		error_and_exit("Invalid date");
	}
	return (t);
}

float	validateValue(std::string const& value, std::ifstream & csvfile)
{
	float	f = 0;
	char	c = 0;
	std::stringstream	ss(value);

	ss >> f;
	if (ss >> c) {
		csvfile.close();
		error_and_exit("Invalid value");
	}
	return (f);
}

std::map<std::time_t, float>	fillMapWithPrices()
{
	std::ifstream	csvfile("./data.csv");
	if (!csvfile.is_open())
		error_and_exit("Invalid csv file");

	std::string	line;
	std::getline(csvfile, line);
	if (!validateFirstLine(line)) {
		csvfile.close();
		error_and_exit("Invalid first line in csv file");
	}

	std::map<std::time_t, float>	priceMap;
	while (std::getline(csvfile, line)) {
		size_t comma = line.find(",");
		if (comma == std::string::npos || comma != line.find_last_of(",")) {
			csvfile.close();
			error_and_exit("Invalid line in csv file");
		}

		std::string	date	= line.substr(0, comma);
		std::string	value	= line.substr(comma + 1, line.size());

		std::time_t	time	= validateDate(date, csvfile);
		float		price	= validateValue(value, csvfile);

		priceMap.insert(std::make_pair(time, price));
	}
	csvfile.close();

	return (priceMap);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		error_and_exit("Usage: ./btc <input file>");

	std::map<std::time_t, float>	priceMap;
	priceMap = fillMapWithPrices();

	std::string	arg(av[1]);
}
