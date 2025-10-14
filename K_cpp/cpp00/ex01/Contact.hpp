#include <string>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		std::string	getFirstName( void ) const;
		std::string	getLastName	( void ) const;
		std::string	getNickName	( void ) const;
		std::string	getPhoneNb	( void ) const;
		std::string	getSecret	( void ) const;

		void		setFirstName( std::string const s);
		void		setLastName	( std::string const s);
		void		setNickName	( std::string const s);
		void		setPhoneNb	( std::string const s);
		void		setSecret	( std::string const s);
		
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_nb;
		std::string	_secret;

};
