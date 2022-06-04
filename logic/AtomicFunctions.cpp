#include <iostream>

using namespace std;

/*
 * Atomic function. Draw spaces required before draw the Xs 
 * @param spacesAmount = number of spaces we want to draw.
 * @return None. This method only prints out in terminal.
 */
void drawSpaces(int spacesAmount){ //
    for (int i=0; i < spacesAmount; i++){
        cout << " ";
    }
}

/*
 * Atomic function. Draw consecutive Xs
 * @param xAmount = Xs amount we want to draw
 * @return None. This method only prints out in terminal.
 */
void drawX(int xAmount){  
    for (int i=0; i < xAmount; i++){
        cout << "X";
    }
}