#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>
#include <cstdlib>

int	main( void )
{
	try {
		Form	f;
		Form	g("forminette", 25, 15);
		Bureaucrat	john("john", 12);
		Bureaucrat	albert("albert", 45);

		// std::cout << f;
		// std::cout << g;
		// std::cout << john;

		john.signForm(g);
		albert.signForm(g);

		std::cout << "This Happened Anyway" << std::endl;
	}
	catch (std::exception const& e) {
		std::cout << "An exception occured: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}


	std::cout << "This happened as well" << std::endl;
	return (EXIT_SUCCESS);
}
