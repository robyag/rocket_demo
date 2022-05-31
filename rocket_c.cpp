#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int inputRows; //global variable. It will be the input of the user. ONLY CHANGES ONCE

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

/*
 * Root method. Checks the input params by user and calls to one of the two main functions:
    drawNormalRocket or drawInvertedRocket.
 * @param   argc: number of arguments given by the user.
            argv: The list of arguments given by the user.
 * @return None. It stops the execution of the program if any of the input parameters are not valid.
 */
void root(int argc, char *argv[]){
    inputRows = atoi(argv[2]); // inputRows will be a constant along the execution of the program. Only changes here
    if ((argc < 3) || (strcmp(argv[1], "-l") != 0) || (inputRows < 2)){
        cout << "Invalid input params" << endl;
        cout << "./rocket    -l   (number > 1)    [-i]" << endl;
        exit(1);
    }
    
    if ((argc == 4) && (strcmp(argv[3], "-i") == 0)) //with && operator it won't evaluate second condition if first one is false. It's safe!
        drawInvertedRocket();
    else
        drawNormalRocket();
}

int main(int argc, char *argv[]){
    root(argc, argv);
    return 0;
}
