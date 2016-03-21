/*****************************************
 * ** Header: critter.hpp
 * ** Description: header file for critter class
 * ****************************************/
#ifndef CRITTER_HPP
#define CRITTER_HPP

class Critter {
	protected:
		int chain;
	public:
		Critter();
		~Critter();
		virtual int getChain();
		virtual void breed(Critter***, Critter***, int, int, int, int);
		virtual void move(Critter***, Critter***, 
				int, int, int, int, int, int);
		virtual void expose();
};
#endif
