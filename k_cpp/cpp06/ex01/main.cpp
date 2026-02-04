#include "Serializer.hpp"
#include "Data.hpp"

#include <iostream>
#include <string>
#include <stdint.h>

int	main()
{
	Data	*data_ptr = new Data;
	data_ptr->s = "hello";
	data_ptr->n = 42;


	uintptr_t	serialized_nbr = Serializer::serialize(data_ptr);
	Data*		deserialized_ptr = Serializer::deserialize(serialized_nbr);

	std::cout	<< data_ptr			<< '\n'
				<< std::hex
				<< serialized_nbr	<< '\n'
				<< deserialized_ptr	<< '\n';

	delete (data_ptr);
	data_ptr = NULL;
	deserialized_ptr = NULL;
	return (0);
}
