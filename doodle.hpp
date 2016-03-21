/*****************************************
* Program Filename: doodle.hpp
* Author: Chewie Lin
* Date: 06 Feb 2016
* Description: doodle class prototypes
*****************************************/
#ifndef DOODLE_HPP
#define DOODLE_HPP
#include "critter.hpp"

class Doodle:public Critter {
	protected:
		int meal;
		int cycle;
	public:
		Doodle();
		~Doodle();
		int getChain();
		void move(Critter***, Critter***, int, int, int, int, int, int);
		void breed(Critter***, Critter***, int, int, int, int);
		void starve(Critter***, int, int);
		void expose();
};
#endif
