/*****************************************
 * ** Header: ant.hpp
 * ** Description: header file for ant class
 * ****************************************/
#ifndef ANT_HPP
#define ANT_HPP
#include "critter.hpp"

class Ant:public Critter {
	protected:
		int cycle;
	public:
		Ant();
		~Ant();
		int getChain();
		void move( Critter***, Critter***, int, int, int, int, int, int);
		void breed(Critter***, Critter***, int, int, int, int);
		void expose();
};
#endif
