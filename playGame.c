/*
This program plays the game ConnectN ;D
*/
# include <stdio.h>
# include <stdbool.h>
# include "inputValidate.h"

void print_cur_board(int numRows, int numCols, char** board){
    /*   
    board looks like this if the input is 3 rows and 3 cols
    2 * * *
    1 * * *
    0 * * *
      0 1 2 
    */

    for(int i = numRows - 1 ; i >= 0; --i){
        printf("%d ", i);
        for(int j = 0; j < numCols; ++j){
            printf("%c ", board[(numRows - 1) - i][j]);
        }
        printf("\n");
    }

    //last row 
    printf("  ");
    for(int i = 0;i < numRows; ++i){
        printf("%d ", i);
    }
    printf("\n");
}

//the purpose: scan from the bottom of matrix to find first empty spot
int find_firstEmpty(int numRows,int currentCol, char** board){
    int rowAvailable;  //also known as i, the iteration variable 
    for(rowAvailable = numRows - 1; rowAvailable >= 0; --rowAvailable){
        if(board[rowAvailable][currentCol] == '*'){
            break;
        }
    }
    return rowAvailable;
}

bool spotIsValid(int numArgsRead, int numRows, int numCols, int currentCol, char** board, char blankSpot){
    return is_inputInRange(numArgsRead, numCols, currentCol) && find_firstEmpty(numRows, currentCol, board) >= 0;
}

void pick_validSpot(int numRows, int numCols, char** board, char blankSpot, char playerPiece){
    int numArgsRead;
    int currentCol;
    do{
        printf("Enter a column between 0 and %d to play in: ", numCols);
        numArgsRead = scanf("%d", &currentCol);
    }while(spotIsValid(numArgsRead, numRows, numCols, currentCol, board, blankSpot) == false);
    int rowAvailable = find_firstEmpty(numRows, currentCol, board);
    board[rowAvailable][currentCol] = playerPiece;
    

}

// current player plays!!!!
void curPlayer_takeMove(int numRows, int numCols, char** board, char blankSpot, char playerPiece){
    //int currentRow;

    print_cur_board(numRows, numCols, board);
    pick_validSpot(numRows, numCols, board,  blankSpot, playerPiece);
}

int cur_player_index(int cur_turn) { // needed to figure out which player win
    /*
    playerPiece[0] == 'X'
    playerPiece[1] == 'O'
    */
    if (cur_turn % 2 == 0)// if its even
    {
        return 1; // 'O'
    }
    else
    {
        return 0; // 'X'
    }
}

char getCurrentPlayerPiece(int cur_turn) { //finding the index of current player
    /*
    playerPiece[0] == 'X'
    playerPiece[1] == 'O'
    */
    if (cur_turn % 2 == 0)// if its even
    {
        return 'O';
    }
    else
    {
        return 'X';
    }
}

void playGame(int numRows, int numCols, char blankSpot, char** board, int pieceConnect){
    int currentTurn = 1;
    do{
        char curPlayerPiece =  getCurrentPlayerPiece(currentTurn);
        curPlayer_takeMove(numRows, numCols, board, blankSpot, curPlayerPiece);
        currentTurn += 1; 
    }while(true);//while(gameOver() == false);  //in another program
    
    currentTurn += 1; // switch back to previous player if gameOver is true
    //announce_result();

}