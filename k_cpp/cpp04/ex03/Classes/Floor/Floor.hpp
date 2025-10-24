#ifndef __FLOOR_HPP__
#define __FLOOR_HPP__

#define MAX_FLOORED 100

class AMateria;

class Floor
{

	public:
		static Floor&	getInstance( void );

		bool	dropToFloor( AMateria *m );
		void	cleanFloor( void );


	private:
		AMateria	*_floor[MAX_FLOORED];

		Floor	( void );
		Floor	( const Floor& src );
		Floor&	operator=	( const Floor& rhs );
		~Floor	( void );


};

#endif // __FLOOR_HPP__
