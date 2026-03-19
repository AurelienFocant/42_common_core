#include "RPN.hpp"

#include <stdexcept>

float	RPN::execute()
{
	if (!_resolve())
		throw std::runtime_error("invalid input");

	float res = static_cast<int>(_stack.top());
	_stack.pop();

	return res;
}

void RPN::_skipWhitespace(std::string::const_iterator & it)
{
	while (it != _input.end() && std::isspace(static_cast<unsigned char>(*it)))
		it++;
}

static float	operate(int const& op, float n2, float n1)
{
	switch (op) {
		case (ADD):
			return (n2 + n1); break;
		case (SUB):
			return (n2 - n1); break;
		case (MUL):
			return (n2 * n1); break;
		case (DIV):
			if (n1 == 0)
				throw std::runtime_error("Division by zero error");
			return (n2 / n1); break;
		default:
			return (0);
	}
}

bool	RPN::_resolve()
{
	std::string::const_iterator	it = _input.begin();
	for (; it != _input.end(); ++it) {

		_skipWhitespace(it);
		if (it == _input.end()) break;

		if (std::isdigit(static_cast<unsigned char>(*it))) {
			_stack.push(*it - '0');
		}

		else if (int op = RPN::isop(*it)) {

			if (_stack.size() < 2) return false;
			float n1 = _stack.top(); _stack.pop();
			float n2 = _stack.top(); _stack.pop();

			_stack.push(operate(op, n2, n1));
		}

		else return false;
	}
	_skipWhitespace(it);
	return (_stack.size() == 1);
}

int RPN::isop(char const c)
{
	switch (c) {
		case ('+'): return ADD; break;
		case ('-'): return SUB; break;
		case ('*'): return MUL; break;
		case ('/'): return DIV; break;
		default:
			return (0);
	}
}

// CONSTRUCTORS AND STUFF
RPN::RPN( void )
	: _input()
	  , _stack()
{
}

RPN::RPN(std::string input)
	: _input(input)
	  , _stack()
{
}

RPN::RPN( const RPN& src )
	: _input(src._input)
	  , _stack(src._stack)
{
}

RPN&	RPN::operator=( const RPN& rhs )
{
	if (this != &rhs) {
		_input	= rhs._input;
		_stack	= rhs._stack;
	}
	return (*this);
}

RPN::~RPN( void )
{
}
