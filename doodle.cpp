/***************************************************
 * Program Filename: doodle.cpp
 * Author: Chewie Lin
 * Date: 06 Feb 2016
 * Description:doodle class functions
 ***************************************************/
#include "doodle.hpp"
#include <iostream>
#include <cstdlib>

/*****************************************
 * Function: Ant()
 * Description: default constructor
 ******************************************/
Doodle::Doodle() {
	cycle = 0;
	chain = 2;
	meal = 0;
	//std::cout << "new ant" << std::endl;
}

/*****************************************
 * Function: ~doodle()
 * Description: default destructor
 ******************************************/
Doodle::~Doodle(){
	//std::cout << "kill ant" << std::endl;
}

/*****************************************
 * Function: getChain()
 * Description: //return food chain number
 ******************************************/
int Doodle::getChain() {
	return chain;
}


/*****************************************
 * Function:move() 
 * Description //make a move
 ******************************************/
void Doodle::move( Critter ***current, Critter ***future, 
		int i, int j, int r, int s, int m, int n) {

	starve(current, i, j);
	cycle++;
	bool setbreak = false;
	int pickone = 1;
	switch ( pickone ) {
		case 1:
			if ( current[i+1][j]->getChain() == 1 ) {
				future[i+1][j] = current[i][j];
				current[i+1][j] = new Critter();
		breed(current, future, i+1, j, m, n);
				setbreak = true;
				break;
			}
		case 2:
			if ( current[i-1][j]->getChain() == 1 ) {
				future[i-1][j] = current[i][j];
				current[i-1][j] = new Critter();
				breed(current, future, i-1, j, m, n);
				setbreak = true;
				break;
			}
		case 3:
			if ( current[i][j+1]->getChain() == 1 ) {
				future[i][j+1] = current[i][j];
				current[i][j+1] = new Critter();
				breed(current, future, i, j+1, m, n);
				setbreak = true;
				break;
			}
		case 4:
			if ( current[i][j-1]->getChain() == 1 ) {
				future[i][j-1] = current[i][j];
				current[i][j-1] = new Critter();
				breed(current, future, i, j-1, m, n);
				setbreak = true;
				break;
			}
	}
	if ( setbreak == true ) {
		meal =0;
	}
	if ( setbreak == false ) {
		meal++;
		if ( current[i+r][j+s]->getChain() == 0 
				&& future[i+r][j+s]->getChain() == 0 ) {
			future[i+r][j+s] = current[i][j];
		breed(current, future, i+r, j+s, m, n);
		}
	
		else {
			future[i][j] = current[i][j];
		breed(current, future, i, j, m, n);
		}
	}

}

/*****************************************
 * Function: // starve()
 * Description: check and set if doodlebug will perish
 ******************************************/
void Doodle::starve(Critter ***current, int i, int j) {
	if ( meal == 3 ) {
		current[i][j] = new Critter();
	}
}

/*****************************************
 * Function: //breed()
 * Description: check and set new doodlebug will hatch
 ******************************************/
void Doodle::breed(Critter ***current, Critter ***future, 
		int i, int j, int m, int n) {
	if ( cycle >= 8 ) {

		int ntry = 0;
		bool stry = false;

		do {
			int s= 0;
			int r = 0;
			do{
		r = -1 + rand() % 3;
		if ( r == 0 ){
			do {
				s = -1 + rand() % 3;
			} while ( s == 0 );
		}
			} while ( i+r <1 || j+s <1 || i+r > m-1 || j+s > n-1 );

		ntry++;
		
		if ( current[i+r][j+s]->getChain() == 0 
				&& future[i+r][j+s]->getChain() == 0 ){
			future[i+r][j+s] = new Doodle();
			stry = true;
		}
		} while ( ntry < 20 && stry == false );

		if (stry == false) {
		cycle = 0;
		}

	}
}

/*****************************************
 * Function: //expose() 
 * Description: return the ascii symbol
 ******************************************/
void Doodle::expose() {
	std::cout << " \u2746";
}
