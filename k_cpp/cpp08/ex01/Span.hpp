#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdint.h>
#include <vector>

#include <iostream>

class Span
{
	private:
		uint32_t				_size;
		uint32_t				_count;
		std::vector<int32_t>	_arr;

		Span	( void );

	public:
		uint32_t	shortestSpan();
		uint32_t	longestSpan();
		void		addNumber(int32_t n);

		template <typename Iterator>
		void	addRange(Iterator begin, Iterator end)
		{
			uint32_t count = std::distance(begin, end);
			if (_count + count > _size)
				throw std::runtime_error("Array is too small for this range");

			_count += count;
			_arr.insert(_arr.end(), begin, end);
		};


		Span	( uint32_t N );
		Span	( const Span& src );
		Span&	operator= ( const Span& rhs );
		~Span	( void );

};

#endif // SPAN_HPP
