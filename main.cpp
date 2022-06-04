#include <iostream>
#include <math.h>
#include <string.h>
#include "logic/DrawLogic.h"
#include "utils/InputRows.h"

using namespace std;
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
