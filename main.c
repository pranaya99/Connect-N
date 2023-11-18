/*
This program is in charge of:
Getting user input from command line argument
Calling other function of ConnectN game 
*/
# define addressOf(x) (&x)
# define valueAt(x) (*x)

# include <stdio.h>
# include <stdlib.h> // enable exit()

# include "inputValidate.h"
# include "settingUp.h"
# include "playGame.h"

void get_input_commandLineArgs(int argc, char** argv, int* row, int* col, int* piece){
    if(argc > 4){
        printf("Too many arguments entered\n");
        printf("Usage connectn.out num_rows num_columns \nnumber_of_pieces_in_a_row_needed_to_win");
        exit(1);
    }
    if(argc < 4){
        printf("Not enough arguments entered\n");
        printf("Usage connectn.out num_rows num_columns \nnumber_of_pieces_in_a_row_needed_to_win");
        exit(1);
    }
    char blankSpot;
    // first integer argument 
    int first_arg_read = sscanf(argv[1], "%d %c", row, &blankSpot); // sscanf read one %d %c as one argument 
    if(first_arg_read != 1){   // if sscanf reads string, it doesn't match with %d so sscanf is going to stop reading 
        printf("Rows need to be integer. Found %s\n", argv[1]);
        exit(1);
    }
    if(*row < 1){
        printf("Rows need to be at least 1 but the input is %d\n", *row);
        exit(1);
    }
    //second integer argument
    int second_arg_read = sscanf(argv[2], "%d %c", col, &blankSpot);
    if(second_arg_read != 1){
        printf("Columns need to be integer. Found %s\n", argv[2]);
        exit(1);
    }
    if(*col < 1){
        printf("Columns need to be at least 1 but the input is %d\n", *col);
        exit(1);
    }
    //third integer argument
    int third_arg_read = sscanf(argv[3], "%d %c", piece, &blankSpot);
    if(third_arg_read != 1){
        printf("N needs to be integer. Found %s\n", argv[3]);
        exit(1);
    }
    if(*col < 2){
        printf("N needs to be at least 2 but the input is %d\n", *piece);
        exit(1);
    }


}

int main(int argc, char** argv){
    int numRows;
    int numCols;
    int pieceConnect;//N piece to connect to win
    const char spaceOnBoard = '*';

    //const int numPlayers = 2;
    //int currentPlayer = 1;
    //int *currentPlayer = (int*)calloc(2,sizeof(int)); //2 players 

    //char* playerPiece = (int*)calloc(2,sizeof(int));  // an pointer: *playerPiece = 'X' and *(playerPiece+1) = 'O'
    
    char** board;  //this is our board 
    get_input_commandLineArgs(argc, argv, &numRows, &numCols, &pieceConnect);
    game_setups(numRows, numCols, spaceOnBoard, &board);
    playGame(numRows, numCols, spaceOnBoard, board, pieceConnect );

    cleanup(numRows, &board);

    return 0;
}