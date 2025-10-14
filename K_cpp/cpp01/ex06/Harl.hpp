#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <string>

class Harl
{

	public:
		Harl();
		~Harl();

		void		complain( int i );
		static int	getLevel( std::string arg );

	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

		static std::string	levels[4];

};


#endif // __HARL_HPP__
