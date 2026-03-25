#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
	std::vector<int>	vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	try {
		std::cout << *easyfind<std::vector <int> >(vec, 3) << '\n';
		std::cout << *easyfind(vec, 6) << '\n';
	}
	catch (std::exception const& e) {
		std::cerr << e.what() << std::endl;
	}


	std::list<int>	list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);

	try {
		std::cout << *easyfind<std::list<int> >(list, 3) << '\n';
		std::cout << *easyfind(list, 6) << '\n';
	}
	catch (std::exception const& e) {
		std::cerr << e.what() << std::endl;
	}

	const std::list<int> constlist(list);

	std::list<int>::const_iterator it;
	it = easyfind<std::list <int> >(constlist, 3);
	(it != constlist.end()) ? std::cout << *it : std::cout << "not found";
	std::cout << '\n';

	it = easyfind<std::list <int> >(constlist, 6);
	(it != constlist.end()) ? std::cout << *it : std::cout << "not found\n";
	std::cout << '\n';

}
