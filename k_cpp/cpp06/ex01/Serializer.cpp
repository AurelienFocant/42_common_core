#include "Serializer.hpp"

#include <iostream>

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t res = reinterpret_cast<uintptr_t>(ptr);
	return (res);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

Serializer::Serializer( void )
{
}

Serializer::Serializer( const Serializer& src )
{
	(void) src;
}

Serializer&	Serializer::operator=( const Serializer& rhs )
{
	if (this != &rhs) {
	}
	return (*this);
}

Serializer::~Serializer( void )
{
	std::cout << "Serializer Object Destroyed" << std::endl;
}
