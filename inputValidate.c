/*
This program is the input validation for ConnectN
check_validFormat: check input, must be one integer 
get_inputInRange: check input during the game, input needs to be between 0 to numCols
*/

# include <stdio.h>
# include <stdbool.h>
# include <ctype.h>
# include <stdlib.h>

bool check_validFormat(int numArgsNeeded, int numArgsRead){ 
    bool validFormat = numArgsNeeded == numArgsRead;
    char lastChar;
    do{
        scanf("%c", &lastChar);
        if(!isspace(lastChar)){ //if scanf reads a char which is not space, then user must inputted char instead of int
            validFormat = false;
        }
    }while(lastChar != '\n');
    return validFormat;
}

bool is_inputInRange(int numArgsRead, int numCols, int currentCol){
    int numArgsNeeded = 1;
    //int number;
    //int numArgsRead = scanf("%d", &number);
    if(check_validFormat(numArgsNeeded, numArgsRead) == true){
        if(currentCol >= 0 && currentCol < numCols){   // in range
            return true;
        }
        //else{
            //printf("Number out of range.\n");
            //exit(1);
        //}
    }
   
    //printf("Format error.\n");
    //exit(1);
    return false;  
}

// // testing, needs to be deleted
// int main(){
//     int numCols = 3;
//     printf("Enter a column between 0 and %d to play in: ", numCols);
//     int numberInput = is_inputInRange(numCols);
//     printf("You inputted: %d\n", numberInput);

//     return 0;
// }



