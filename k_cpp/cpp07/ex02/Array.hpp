#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdint.h>

template <typename T>
class Array
{
	private:
		uint32_t	_size;
		T*			_arr;

	public:
		Array();
		Array(uint32_t n);
		Array(const Array& src);
		Array& operator=(const Array& rhs);
		~Array();

		uint32_t	size() const;
				T&	operator[](uint32_t index);
		const	T&	operator[](uint32_t index) const;
};

#include "Array.tpp"

#endif
