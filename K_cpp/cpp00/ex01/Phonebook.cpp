#include "PhoneBook.hpp"

#include <cstdlib>
#include <cctype>
#include <iostream>
#include <iomanip>


// Constructor and Destructor
PhoneBook::PhoneBook(void) : _index(0) {}

PhoneBook::~PhoneBook(void) {}


// Public member functions
void	PhoneBook::add(void)
{
	_index %= 8;
	this->_contacts[_index].setFirstName(_query_string("What is you first name? "));
	this->_contacts[_index].setLastName(_query_string("What is you last name? "));
	this->_contacts[_index].setNickName(_query_string("What is you nickname? "));
	this->_contacts[_index].setPhoneNb(_query_number("What is you phone number? "));
	this->_contacts[_index].setSecret(_query_string("What is you darkest secret? "));
	std::cout << std::endl;
	_index++;
}

void	PhoneBook::search(void) const
{
	_print_header();
	_print_summary();
	_print_entry(_query_index());
}

void	PhoneBook::exit(void) const
{
	std::cout << "Exiting Phonebook, thanks for using! \n";
	std::exit(EXIT_SUCCESS);
}


// Private member functions
void	PhoneBook::_print_header(void) const
{
	std::cout << std::setw(10) << "INDEX" << '|';
	std::cout << std::setw(10) << "FIRST NAME" << '|';
	std::cout << std::setw(10) << "LAST NAME" << '|';
	std::cout << std::setw(10) << "NICKNAME" << '|';
	std::cout << std::endl;
}

static std::string	truncate(std::string const &s)
{
	if (s.length() > 10)
		return (s.substr(0, 9) + ".");
	return (s);
}

void	PhoneBook::_print_summary(void) const
{
	for (int i = 0; i < 8; i++) {
		if (!_contacts[i].getFirstName().empty()) {
			std::cout << std::setw(10) << i + 1 << '|';
			std::cout << std::setw(10) << truncate(_contacts[i].getFirstName()) << '|';
			std::cout << std::setw(10) << truncate(_contacts[i].getLastName()) << '|';
			std::cout << std::setw(10) << truncate(_contacts[i].getNickName()) << '|';
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

bool	PhoneBook::_is_valid_index(int n) const
{
	return (n >= 1 && n <= 8 && !this->_contacts[n - 1].getFirstName().empty());
}

int	PhoneBook::_query_index(void) const
{
	std::string	input;
	int	n;

	std::cout << "Which contact do you want to know about ?" << std::endl;
	while (true) {
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << std::endl;
			std::exit(EXIT_FAILURE);
		}
		if (input.length() == 1) {
			n = std::atoi(input.c_str());
			if (_is_valid_index(n))
				break ;
		}
		std::cout << "Invalid index" << std::endl;
	}
	return (n - 1);
}

void	PhoneBook::_print_entry(int index) const
{
	std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickName() << std::endl;
	std::cout << "Phone number: " << _contacts[index].getPhoneNb() << std::endl;
}



static bool	is_all_whitespace(std::string const &s)
{
	for (std::string::const_iterator i = s.begin(); i < s.end(); ++i) {
		if (!std::isspace((unsigned char) *i))
			return (false);
	}
	return (true);
}

static bool	are_all_digits(std::string const &s)
{
	for (std::string::const_iterator i = s.begin(); i < s.end(); ++i) {
		if (!std::isdigit((unsigned char) *i))
			return (false);
	}
	return (true);
}

std::string	PhoneBook::_query_string(std::string const &input) const
{
	std::string res;

	while (res.empty() || is_all_whitespace(res)) {
		std::cout << input << std::flush;
		std::getline(std::cin, res);
		if (std::cin.eof()) {
			std::cout << std::endl;
			std::exit(EXIT_FAILURE);
		}
	}
	return (res);
}

std::string	PhoneBook::_query_number(std::string const &input) const
{
	std::string res;

	std::cout << input << std::flush;
	std::getline(std::cin, res);
	while (res.length() < 8 || !are_all_digits(res)) {
		std::cout << "This is not a number, try again" << std::endl;
		std::cout << input << std::flush;
		std::getline(std::cin, res);
		if (std::cin.eof()) {
			std::cout << std::endl;
			std::exit(EXIT_FAILURE);
		}
	}
	return (res);
}
