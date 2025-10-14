#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string	Contact::getFirstName( void ) const
{
	return (this->_first_name);
}

std::string	Contact::getLastName( void ) const
{
	return (this->_last_name);
}

std::string	Contact::getNickName( void ) const
{
	return (this->_nickname);
}

std::string	Contact::getPhoneNb( void ) const
{
	return (this->_phone_nb);
}

std::string	Contact::getSecret( void ) const
{
	return (this->_secret);
}

void	Contact::setFirstName(std::string s)
{
	this->_first_name = s;
}

void	Contact::setLastName(std::string s)
{
	this->_last_name = s;
}

void	Contact::setNickName(std::string s)
{
	this->_nickname = s;
}

void	Contact::setPhoneNb(std::string s)
{
	this->_phone_nb = s;
}

void	Contact::setSecret(std::string s)
{
	this->_secret = s;
}
