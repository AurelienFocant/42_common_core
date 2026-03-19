#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

#define	ADD	1
#define	SUB	2
#define	MUL	3
#define	DIV	4

class RPN
{
	private:

		std::string			_input;
		std::stack<float>	_stack;
		float				_res;

		bool	_stackChar(std::string::const_iterator & it);
		bool	_resolve();

		void _skipWhitespace(std::string::const_iterator & it);
		float	_operate(int op, float n1, float n2);


		RPN	( void );


	public:
		float	execute();

		static int isop(char const c);

		RPN	(std::string input);
		RPN	( const RPN& src );
		RPN&	operator= ( const RPN& rhs );
		~RPN	( void );

};

#endif // RPN_HPP
