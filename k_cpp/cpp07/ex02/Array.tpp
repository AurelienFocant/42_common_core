#include <stdexcept>

template <typename T>
Array<T>::Array()
	: _size(0)
	, _arr(NULL)
{
}

template <typename T>
Array<T>::Array(uint32_t n)
	: _size(n)
{
    _arr = (n == 0) ? NULL : new T[n]();
}

template <typename T>
Array<T>::Array(Array const& src)
	: _size(src._size)
	, _arr(NULL)
{
	if (_size) {
		_arr	= new T[_size]();
		for (uint32_t i = 0; i < _size; i++) {
			_arr[i] = src._arr[i];
		}
	}
}

template <typename T>
Array<T>&	Array<T>::operator=(Array const& rhs)
{
	if (this != &rhs) {
		if (_arr) delete[] _arr;

		_size	= rhs._size;
		_arr	= _size ? new T[_size]() : NULL;
		for (uint32_t i = 0; i < _size; i++) {
			_arr[i] = rhs._arr[i];
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _arr;
}

template <typename T>
uint32_t Array<T>::size() const
{
	return _size;
}

template <typename T>
T& Array<T>::operator[](uint32_t index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _arr[index];
}

template <typename T>
const T& Array<T>::operator[](uint32_t index) const
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _arr[index];
}
