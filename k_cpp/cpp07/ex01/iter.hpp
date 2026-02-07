#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib>

template <typename T>
void iter(T arr[], const size_t size, void (*f)(T & arg))
{
	if (!arr || !f)
		return;

	for (size_t i = 0; i < size; ++i) {
		f(arr[i]);
	}
}

template <typename T>
void iter(T arr[], const size_t size, void (*f)(T const& arg))
{
	if (!arr || !f)
		return;

	for (size_t i = 0; i < size; ++i) {
		f(arr[i]);
	}
}

#endif // ITER_HPP
