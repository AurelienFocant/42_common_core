#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>
#include <algorithm>

template <typename T>	
typename T::iterator easyfind(T & container, int target)
{
	typename T::iterator it = std::find(container.begin(), container.end(), target);

	if (it == container.end())
		throw std::runtime_error("easyfind: no match found");

	return (it);
}

template <typename T>	
typename T::const_iterator easyfind(T const& container, int target)
{
	return std::find(container.begin(), container.end(), target);
}

#endif // EASYFIND_HPP
