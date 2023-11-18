/*
This is the setting up in ConnectN
char** create_board: dynamically allocate 2D array as our board and place '*' in blank spots 
void game_setups: create the board 
void cleanup: clean up after game ends
*/

# include <stdio.h>
# include <stdlib.h>

char** create_board(int numRows, int numCols, char blankSpot){
    // allocating 2D space for 
    char** board = (char**)calloc(numRows, sizeof(char*));
    for(int i = 0; i < numCols; ++i){
        board[i] = (char*)calloc(numCols, sizeof(char));   // board[i] == (*board) + i //
    }
    // assign '*' to every spot on board 
    for(int i = 0; i < numRows; ++i){
        for(int j = 0; j < numCols; ++j){
            board[i][j] = blankSpot;
        }
    }
    return board;
}

/*
int cur_player_index(int cur_turn) { //finding the index of current player
    //playerPiece[0] == 'X'
    //playerPiece[1] == 'O'
    
    if (cur_turn % 2 == 0)
    {
        return 1; // 'O'
    }
    else
    {
        return 0; // 'X'
    }
} */

// some setups
void game_setups(int numRows, int numCols, char blankSpot, char** *board){

    *board = create_board(numRows, numCols, blankSpot);

    // char* playerPiece = (char*)calloc(2,sizeof(char));  // an pointer: *playerPiece = 'X' and (*playerPiece)+1 = 'O'
    // *playerPiece = 'X';
    // *(playerPiece + 1)  = 'O';
}

//some clean ups
void cleanup(int numRows, char** *board){
    for(int i = 0; i < numRows; ++i){
        free(*(*board + i));  // *(*board + i) == (*board)[i]
    }
    free(*board);
}


