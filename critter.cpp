/*****************************************
* Program Filename: critter.cpp
* Author: Chewie Lin
* Date: 06 Feb 2016
* Description: critter class functions
*****************************************/
#include "critter.hpp"
#include <cstdlib>
#include <iostream>

/*****************************************
* Function: critter()
* Description: default constructor
****************************************/
Critter::Critter() {
	//std::cout << "critter borned" << std::endl;
	chain = 0;
}

/*****************************************
* Function: ~critter()
* Description: default destrctor
****************************************/
Critter::~Critter(){
	//std::cout << "critter killed" << std::endl;
}

/*****************************************
* Function: //getchain()
* Description: return food chain number
****************************************/
int Critter::getChain() {
	return chain;
}

/*****************************************
* Function:  //virtual move()
* Description: virtual move function
****************************************/
void Critter::move(Critter*** current, Critter*** future, 
		int i, int j, int r, int s, int m, int n) {
}

/*****************************************
* Function:  //virtual //breed
* Description: virtual breed function
****************************************/
void Critter::breed(Critter***, Critter***, int, int, int, int) {
}

/*****************************************
* Function:  //virtual expose()
* Description: virtual expose() function
****************************************/
void Critter::expose() {
	std::cout << " _";
}
