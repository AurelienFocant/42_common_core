#include <ctime>
#include <cstdlib>
#include <iostream>

#include "Classes.hpp"

Base*	generate(void)
{
	int	n = std::rand();
	if (n % 3 == 1)
		return (new A);
	if (n % 3 == 2)
		return (new B);
	return (new C);
}

void	identify(Base* p)
{
	if (A* a_ptr = dynamic_cast<A*>(p))
		std::cout << "ptr to A at address " << a_ptr << std::endl;
	else if (B* b_ptr = dynamic_cast<B*>(p))
		std::cout << "ptr to B at address " << b_ptr << std::endl;
	else if (C* c_ptr = dynamic_cast<C*>(p))
		std::cout << "ptr to C at address " << c_ptr << std::endl;
}

void	identify(Base& p)
{
	try {
		A& a_ref = dynamic_cast<A&>(p);
		std::cout << "ref to A at address " << &a_ref << std::endl;
		return ;
	}
	catch (std::bad_cast const& e) {
	}

	try {
		B& b_ref = dynamic_cast<B&>(p);
		std::cout << "ref to B at address " << &b_ref << std::endl;
		return ;
	}
	catch (std::bad_cast const& e) {
	}

	try {
		C& c_ref = dynamic_cast<C&>(p);
		std::cout << "ref to C at address " << &c_ref << std::endl;
		return ;
	}
	catch (std::bad_cast const& e) {
	}
}

int	main()
{
	std::srand(std::time(NULL));


	Base*	ptr = generate();

	identify(ptr);
	identify(*ptr);

	delete(ptr);
	ptr = NULL;
}
