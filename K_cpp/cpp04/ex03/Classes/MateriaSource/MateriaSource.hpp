#ifndef __MATERIASOURCE_HPP__
#define __MATERIASOURCE_HPP__

#include "IMateriaSource.hpp"

#include <string>

#define MAX_SOURCES	4

class AMateria;

class MateriaSource : public IMateriaSource
{

	public:
		MateriaSource	( void );
		MateriaSource	( const MateriaSource& src );
		MateriaSource&	operator=( const MateriaSource& rhs );
		~MateriaSource	( void );

		void		learnMateria	( AMateria* m);
		AMateria*	createMateria	( std::string const & type );

	private:
		AMateria*	_store[MAX_SOURCES];

		void	_setEmptyStore( void );
		void	_deleteStore( void );
		void	_copyStore( const MateriaSource& src );
};

#endif // __MATERIASOURCE_HPP__
