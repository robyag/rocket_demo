#include <iostream>
#include "../utils/InputRows.h"
#include "AtomicFunctions.h"

using namespace std;


/*
 * Calculate how many times we have to draw a space depending of the rowNumber
 * @param rowNumber = Row number. It let us to know how many spaces we have to draw
 * @return None
 */
void calculateSpacesToDraw(int rowNumber){
    for (int spaces = inputRows - rowNumber; spaces > 1; spaces--){
        drawSpaces(1);
    }
}

/*
 * Draws the spike (|) at the top of the rocket after many spaces
 * @param None
 * @return None. This method only prints out in terminal.
 */
void drawSpike(){
    calculateSpacesToDraw(0); //always zero because it's the spike
    cout << "|" << endl;
}

/*
 * Draws the 3 Xs in the bottom of the rocket 
 * @param None
 * @return None. This method only prints out in terminal.
 */
void drawFeet(){ 
    drawX(1);
    for (int i = 0; i < 2; i++){ // it will be always 2 times after the first bottom X.
        drawSpaces(inputRows - 2);
        drawX(1);
    }
    cout << endl;
}

/*
 * Draws a row, compossed by spaces and X.
 * @param rowNumber = Row number. It let us to know how many spaces and Xs we have to draw
 * @return None.
 */
void drawRow(int rowNumber){
    calculateSpacesToDraw(rowNumber);
    drawX(2 * rowNumber + 1);
}



/*
 * Main method to draw a normal rocket. It will call to smaller methods.
    Composed by: draw spike, draw the middle rows, and draw the feet of the rocket.
 * @param None
 * @return None.
 */
void drawNormalRocket(){
    drawSpike();
    for(int currentRow = 0; currentRow < inputRows; currentRow++){
        drawRow(currentRow);
        cout << endl;
    }
    drawFeet();
}

/*
 * Draws the 3 Xs in the bottom of the rocket 
 * @param None
 * @return None.
 */
void drawInvertedRocket(){
    drawFeet();
    for(int currentRow = inputRows - 1; currentRow >= 0; currentRow--){
        drawRow(currentRow);
        cout << endl;
    }
    drawSpike();
}
