/***************************************************
 * Program Filename: ant.cpp
 * Author: Chewie Lin
 * Date: 06 Feb 2016
 * Description: ant class functions
 ***************************************************/
#include "ant.hpp"
#include <iostream>
#include <cstdlib>

/*****************************************
 * Function: ant()
 * Description: default constructor
 ******************************************/
Ant::Ant() {
	cycle = 0;
	chain = 1;
	//std::cout << "new ant" << std::endl;
}
/*****************************************
 * Function://destructor
 * Description: default destructor
 ******************************************/
Ant::~Ant(){
	std::cout << "kill ant" << std::endl;
}

/*****************************************
 * Function: getChain()
 * Description: return food chain number
 ******************************************/
int Ant::getChain() {
	return chain;
}

/*****************************************
 * Function: move()
 * Description: move() for ant
 ******************************************/
void Ant::move( Critter ***current, Critter ***future, 
		int i, int j, int r, int s, int m, int n) {
		cycle++;
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

/*****************************************
 * Function: //breed()
 * Description: breed function
 ******************************************/
void Ant::breed(Critter ***current, Critter ***future, 
		int i, int j, int m, int n) {
	if ( cycle == 3 ) {
	
		int ntry = 0;
		bool stry = false;

		do {
			int s = 0;
			int r = 0;
		do {
		r = -1 + rand() % 3;
		if ( r == 0 ){
			do {
				s = -1 + rand() % 3;
			} while ( s == 0 );
		}
		} while (i+r < 1 || j+s < 1 || i+r > m-1 || j+s > n-1);

		ntry++;
		
		if ( current[i+r][j+s]->getChain() == 0 
				&& future[i+r][j+s]->getChain() == 0){
			future[i+r][j+s] = new Ant();
			stry = true;
		}
		} while ( ntry < 8 && stry == false );

		cycle = 0;
	}
}

/*****************************************
 * Function: //expose() 
 * Description: display ascii symbol
 ******************************************/
void Ant::expose() {
	std::cout << " \u2584";
}
