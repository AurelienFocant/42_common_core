#ifndef MYTEMPLATES_HPP
#define MYTEMPLATES_HPP

template <typename Type>
void	swap(Type & a, Type & b)
{
	Type	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename Type>
Type	min(Type const& a, Type const& b)
{
	if (a < b)	return a;
	else		return b;
}

template <typename Type>
Type	max(Type const& a, Type const& b)
{
	return (a > b ? a : b);
}

#endif // MYTEMPLATES_HPP
