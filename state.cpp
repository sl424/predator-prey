/*****************************************
* Program Filename: critter.cpp
* Author: Chewie Lin
* Date: 06 Feb 2016
* Description: critter class functions
*****************************************/
#include "state.hpp"
#include "critter.hpp"
#include <iostream>

/*****************************************
* Function: \\deallocate()
* Description: deallocate the dynamic array
* NOT USED IN THE PROGRAM
*****************************************/
void deallocate(Critter*** dealloc, int m, int n ) {
		for ( int i = 0; i < m; ++i ) {
			for ( int j= 0; j < n; ++j ) {
				if (dealloc[i][j]->getChain() != 0) {
				dealloc[i][j] = new Critter();
				}
				//delete dealloc[i][j];
			}
			//delete [] dealloc[i];
		}
		//delete [] dealloc;
		//dealloc = 0;
}

/*****************************************
* Function: spawn()
* Description: create new array
*****************************************/
Critter*** spawn(int m, int n) {
	Critter ***temp;
	temp = new Critter**[m];
	for ( int i = 0; i < m; i++ ) {
		temp[i] = new Critter*[n];
		for (int j = 0; j < n; j++ ) {
			temp[i][j] = new Critter();
		}
	}
	return temp;
}

/*****************************************
* Function: show()
* Description: display the critter in each cell
*****************************************/
void show (Critter*** current, int m, int n, int buffer) {
	std::cout << "\n";
	for ( int i = buffer; i < m - buffer; i++ ) {
		for ( int j = buffer; j < n - buffer; j++ ) {
			current[i][j]->expose();
		}
		std::cout << "\n";
	}
	std::cout << std::endl;
}
