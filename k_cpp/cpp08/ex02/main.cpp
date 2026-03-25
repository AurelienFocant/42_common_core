#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>

int	main()
{
	{
		MutantStack<int>	mutant;
		mutant.push(5);
		mutant.push(9);
		mutant.push(3);

		MutantStack<int>::const_iterator	c_it = mutant.begin();
		for (; c_it != mutant.end(); c_it++) {
			std::cout << *c_it << '\n';
		}

		std::cout << "========================\n";

		MutantStack<int>::iterator	it = mutant.begin();
		for (; it != mutant.end(); it++) {
			*it += 42;
			std::cout << *it << '\n';
		}

		std::cout << "========================\n";

		std::cout << "size of mutant is " << mutant.size() << std::endl;
		std::cout << "top element is " << mutant.top() << std::endl;
		mutant.pop();
		std::cout << "size of mutant is " << mutant.size() << std::endl;

		std::cout << "========================\n";
	}

	{
		MutantStack<int, std::list<int> >	mutant;
		mutant.push(5);
		mutant.push(9);
		mutant.push(3);

		MutantStack<int, std::list<int> >::const_iterator	c_it = mutant.begin();
		for (; c_it != mutant.end(); c_it++) {
			std::cout << *c_it << '\n';
		}

		std::cout << "========================\n";

		MutantStack<int, std::list<int> >::iterator	it = mutant.begin();
		for (; it != mutant.end(); it++) {
			*it += 42;
			std::cout << *it << '\n';
		}

		std::cout << "========================\n";

		std::cout << "size of mutant is " << mutant.size() << std::endl;
		std::cout << "top element is " << mutant.top() << std::endl;
		mutant.pop();
		std::cout << "size of mutant is " << mutant.size() << std::endl;

		std::cout << "========================\n";
	}
}
