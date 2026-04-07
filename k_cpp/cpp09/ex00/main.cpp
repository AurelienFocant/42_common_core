#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <ctime>
#include <map>
#include <climits>

int	error_and_exit(std::string msg)
{
	std::cerr << msg << std::endl;
	std::exit(1);
}

bool	validateFirstLine(std::string const& sep, std::string const& line, std::string const& first, std::string const& second)
{
			size_t	pos = line.find(sep);
			size_t	last_pos = line.find_last_of(sep) - sep.size() + 1;
			if (pos == std::string::npos || pos != last_pos)
				return (false);
			if (line.substr(0, pos) != first)
				return (false);
			if (line.substr(pos + sep.size(), line.size()) != second)
				return (false);

			return (true);
}

std::time_t	validateDate(std::string const& date, std::ifstream & file)
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
			file.close();
			error_and_exit("Invalid year");
		}
		ss >> month;
		if (ss.fail() || !(ss >> c) || c != '-') {
			file.close();
			error_and_exit("Invalid month");
		}
		ss >> day;
		if (ss.fail() || !day || ss >> c) {
			file.close();
			error_and_exit("Invalid day");
		}

		tm.tm_year	= year - 1900;
		tm.tm_mon	= month - 1;
		tm.tm_mday	= day;

		if (tm.tm_year <= 0 || tm.tm_mon < 0 || tm.tm_mday <= 0) {
			file.close();
			error_and_exit("Invalid date");
		}
	}

	std::tm	copy = tm;
	std::time_t	t = std::mktime(&tm);
	if	(	tm.tm_year	!= copy.tm_year
		||	tm.tm_mon	!= copy.tm_mon
		||	tm.tm_mday	!= copy.tm_mday) {
		file.close();
		error_and_exit("Invalid date");
	}
	return (t);
}

float	validateValue(std::string const& value, std::ifstream & file)
{
	float	f = 0;
	char	c = 0;
	std::stringstream	ss(value);

	ss >> f;
	if (ss >> c || f < 0) {
		file.close();
		error_and_exit("Invalid value");
	}
	return (f);
}

float	validateNumber(std::string const& value, std::ifstream & file)
{
	double	d = 0;
	std::stringstream	ss(value);

	ss >> d;
	if (d > INT_MAX || d < 0) {
		file.close();
		error_and_exit("Invalid number");
	}
	return (validateValue(value, file));
}

void	fillMapWithPrices(std::map<std::time_t, float> & priceMap)
{
	std::ifstream	csvfile("./data.csv");
	if (!csvfile.is_open())
		error_and_exit("Invalid csv file");

	std::string	line;
	std::getline(csvfile, line);
	if (!validateFirstLine(",", line, "date", "exchange_rate")) {
		csvfile.close();
		error_and_exit("Invalid first line in csv file");
	}

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
}

std::map<std::time_t, float>::iterator	findClosestTime(std::time_t time, std::map<std::time_t, float> & priceMap)
{
	std::map<std::time_t, float>::iterator	it = priceMap.lower_bound(time);

	if (it == priceMap.begin() || it == priceMap.end())
		return (it);

	if (it->first == time)
		return (it);

	return (--it);
}

std::string	epochToLocalTime(std::time_t time)
{
	struct tm *tm_info = localtime(&time);

    char buffer[256];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", tm_info);
	return (std::string(buffer));
}

int	main(int ac, char **av)
{
	if (ac != 2)
		error_and_exit("Usage: ./btc <input file>");

	std::map<std::time_t, float>	priceMap;
	fillMapWithPrices(priceMap);


	std::ifstream	infile(av[1]);
	if (!infile.is_open())
		error_and_exit("Invalid input file");

	std::string	line;
	std::getline(infile, line);
	std::string	sep(" | ");
	if (!validateFirstLine(sep, line, "date", "value")) {
		infile.close();
		error_and_exit("Invalid first line in input file");
	}
	while (std::getline(infile, line)) {
		size_t pipe = line.find(sep);
		if (pipe == std::string::npos || pipe != line.find_last_of(sep) - sep.size() + 1) {
			infile.close();
			error_and_exit("Invalid line in input file");
		}

		std::string	date	= line.substr(0, pipe);
		std::string	value	= line.substr(pipe + sep.size(), line.size());

		std::time_t	time	= validateDate(date, infile);
		float		number	= validateNumber(value, infile);

		std::map<std::time_t, float>::iterator	it;
		it = findClosestTime(time, priceMap);
		if (it == priceMap.begin() || it == priceMap.end()) {
			std::cout << "value out of table\n";
		}
		else {
			std::cout	<< epochToLocalTime(time) << " => "
						<< number * it->second
						<< std::endl;
		}
	}
}
