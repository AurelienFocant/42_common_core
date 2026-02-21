#include "Span.hpp"

#include <iostream>
#include <stdint.h>

#include <algorithm>

uint32_t	Span::shortestSpan()
{
	if (_size <= 1)
		throw std::runtime_error("Array is too small to have a span");

	std::vector<int32_t>	_sorted_arr(_arr);
	std::sort(_sorted_arr.begin(), _sorted_arr.end());

	uint32_t	shortest_span = _sorted_arr[1] - _sorted_arr[0];
	uint32_t	span;
	for (uint32_t i = 2; i < _size; i++) {
		span = _sorted_arr[i] - _sorted_arr[i-1];
		shortest_span = std::min(shortest_span, span);
	}
	return (shortest_span);
}

uint32_t	Span::longestSpan()
{
	if (_size <= 1)
		throw std::runtime_error("Array is too small to have a span");

	std::vector<int>::iterator min_it = std::min_element(_arr.begin(), _arr.end());
	std::vector<int>::iterator max_it = std::max_element(_arr.begin(), _arr.end());

	return (*max_it - *min_it);
}

void	Span::addNumber(int32_t n)
{
	if (_count == _size) {
		throw std::runtime_error("Array is already full");
	}

	++_count;
	_arr.push_back(n);
}



/* Constructors and Stuff */
Span::Span( void )
	: _size	(0)
	, _count(0)
	, _arr	()
{
}

Span::Span( uint32_t N)
	: _size	(N)
	, _count(0)
	, _arr	()
{
}

Span::Span( const Span& src )
	: _size	(src._size)
	, _count(src._count)
	, _arr	(src._arr)
{
}

Span&	Span::operator=( const Span& rhs )
{
	if (this != &rhs) {
		_size	= rhs._size;
		_count	= rhs._count;
		_arr	= rhs._arr;
	}
	return (*this);
}

Span::~Span( void )
{
	std::cout << "Span Object Destroyed" << std::endl;
}
