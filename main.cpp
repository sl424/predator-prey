#include "critter.hpp"
#include "ant.hpp"
#include "doodle.hpp"
#include "state.hpp"
#include <unistd.h>
#include <cstdlib>
#include <iostream>

int main()
{

    srand(time(0));
    int timestep;
    int choice;
    int vsize;
    int hsize;
    int ants;
    int doodlebugs;

    //prompt inputs
    std::cout << "Enter the timestep: ";
    std::cin >> timestep;
    std::cout << "Enter the row: ";
    std::cin >> vsize;
    std::cout << "Enter the column: ";
    std::cin >> hsize;
    std::cout << "Enter the number of ants: ";
    std::cin >> ants;
    std::cout << "Enter the number of doodlebugs: ";
    std::cin >> doodlebugs;

    int buffer = 1;
    int m = vsize + 2 * buffer;
    int n = hsize + 2 * buffer;

    //initial critter world
    Critter ***current = spawn(m, n);
    Critter ***future = spawn(m, n);

    //randomize the ants
    do {
	int a = 1 + rand() % (vsize - 1);
	int b = 1 + rand() % (hsize - 1);
	if (ants > 0) {
	    if (current[a][b]->getChain() == 0) {
		current[a][b] = new Ant();
		ants--;
	    }
	}
    }
    while (ants > 0);

    //randomize the doodlebugs
    do {
	int a = 1 + rand() % (vsize - 1);
	int b = 1 + rand() % (hsize - 1);
	if (doodlebugs > 0) {
	    if (current[a][b]->getChain() == 0) {
		current[a][b] = new Doodle();
		doodlebugs--;
	    }
	}
    }
    while (doodlebugs > 0);


    //begin user loop
    do {
	for (int x = 0; x < timestep; ++x) {
	    std::system("clear");
	    show(current, m, n, buffer);
	    int taketurn = 0;
	    do {
		//begin array loop
		for (int i = 1; i < m - 1; i++) {
		    for (int j = 1; j < n - 1; j++) {
			//generate random move for each cell
			int s = 0;
			int r = 0;
			do {
			    r = -1 + rand() % 3;
			    if (r == 0) {
				do {
				    s = -1 + rand() % 3;
				}
				while (s == 0);
			    }
			}
			while (i + r > m - 2 || j + s > n - 2 || i + r < 1
			       || j + s < 1);

			//doodlebugs move in first turn
			if (taketurn == 0) {
			    if (current[i][j]->getChain() == 2)
				current[i][j]->move(current, future,
						    i, j, r, s, vsize,
						    hsize);
			}
			//ants move in second turn
			if (taketurn == 1) {
			    if (current[i][j]->getChain() == 1)
				current[i][j]->move(current, future,
						    i, j, r, s, vsize,
						    hsize);
			}
		    }
		}
		// switch turn
		taketurn++;
	    }
	    while (taketurn < 2);

	    //swap array and create new one
	    current = future;
	    future = spawn(m, n);
	    usleep(2 * 200000);
	}

	//user loop message
	std::cout << "Enter -1 to exit or a timestep value to continue: ";
	std::cin >> timestep;
	std::cout << std::endl;
    }
    while (timestep != -1);

    return 0;

}
