#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include <string>

class Brain
{
	public:
		Brain	( void );
		Brain	( const Brain& src );
		Brain&	operator=	( const Brain& rhs );
		~Brain	( void );

		Brain*		deepCopyBrain( void ) const;

		unsigned int	setIdea( const std::string & idea );
		std::string		getIdea( unsigned int i ) const;

	private:
		std::string		_ideas[100];
		unsigned int	_ideaIndex;

};

#endif // __BRAIN_HPP__
