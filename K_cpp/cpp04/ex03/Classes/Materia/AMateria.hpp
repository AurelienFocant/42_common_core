#ifndef __AMATERIA_HPP__
#define __AMATERIA_HPP__

#include <string>

class ICharacter;

class AMateria
{
	public:
		AMateria	( void );
		AMateria	( const AMateria& src );
		AMateria&	operator=( const AMateria& rhs );
		virtual ~AMateria	( void );

		AMateria	( std::string const & type );

		std::string const &	getType() const;

		virtual AMateria*	clone( void ) const = 0;
		virtual void		use( ICharacter& target );

	protected:
		std::string	_type;
};

#endif // __AMATERIA_HPP__
