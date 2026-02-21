#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
	public:
		typedef typename	Container::iterator				iterator;
		typedef typename	Container::const_iterator		const_iterator;

		iterator		begin()		    { return (this->c.begin());	}
		iterator		end()		    { return (this->c.end());	}
		const_iterator	begin()	const   { return (this->c.begin());	}
		const_iterator	end()	const 	{ return (this->c.end());	}


		MutantStack	() {};
		~MutantStack() {};
		MutantStack	( const MutantStack& src ) : std::stack<T, Container>(src) {};
		MutantStack&	operator= ( const MutantStack& rhs ) {
			if (this != &rhs) {
				this->c = rhs.c;
			}
			return (*this);
		};
};

#endif // MUTANTSTACK_HPP
