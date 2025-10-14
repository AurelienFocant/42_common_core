#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add(void);
		void	search(void) const;
		void	exit(void) const;

	private:
		Contact _contacts[8];
		int		_index;

		void		_print_header(void)		const;
		void		_print_summary(void)	const;
		void		_print_entry(int index)	const;

		std::string	_query_string(std::string const &input)	const;
		std::string	_query_number(std::string const &input)	const;
		int			_query_index(void)		const;
		bool		_is_valid_index(int n)	const;
};
