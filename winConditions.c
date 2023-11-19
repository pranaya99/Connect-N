/*
This program checks winning conditions 
The method for checking is: Keep track of current piece, check its left side and right side 
the loop conditions for each winning (vertical, horizonal, diagonal) needs to be changed
this is the example for loop condition for horizontal condition 
left side: (i = 0; i < currentPiece; ++i)
right side: (i = currentPiece; i < numCols; ++ i)
Two int functions is going to return how many CONSECUTIVE pieces are on each side of current piece
BREAK the loop if the piece next to it is not the same piece, return the number of same piece next to it
Current player wins if two function returing numbers adds up to (pieceConnect - 1)

new thought:
make the loops runs from 0 to numCols - 1
we make and initionalize counter to 0
we check if the element in column = current playerPiece
then check next element 
if next element is * || another player's piece
reinitialize counter's value to 0 
if the next element is current playerPiece
counter += 1
current player wins if counter == pieceConnect (return true)

# include <stdio.h>
# include <stdbool.h>
# include "playGame.h"


int leftSide_check(int currentRow, int currentCol, char** board){
    char currentPiece = board[currentRow][currentCol];
    int countSame = 0;
    for(int i  = currentCol - 1; i >= 0; --i){
        if(board[currentRow][i] == currentPiece){//[row of the current piece]
            countSame += 1;
        }
        else{
            break;
        }
    }
    return countSame;
}

int rightSide_check(int numCols, int currentRow, int currentCol, char** board){
    char currentPiece = board[currentRow][currentCol];
    int countSame = 0;
    for(int i  = currentCol + 1; i <= numCols; ++i){
        if(board[currentRow][i] == currentPiece){//[row of the current piece]
            countSame += 1;
        }
        else{
            break;
        }
    }
    return countSame;
}

bool horizontal_win(int numRows, int numCols, char** board, char blankSpot, char playerPiece, int pieceConnect){
    //get current piece location by calling these 2 funtion from playGame.c
    int currentCol = pick_validSpot(numRows, numCols, board, blankSpot, playerPiece);
    int currentRow = find_firstEmpty(numRows, currentCol, board);

    int leftMatch;
    int rightMatch;
    leftMatch = leftSide_check(currentRow, currentCol, board);
    rightMatch = rightSide_check(numCols, currentRow, currentCol, board);

    if (leftMatch + rightMatch == pieceConnect - 1){
        return true;
    }    
    else{
        return false;
    }
}
*/

# include <stdio.h>
# include <stdbool.h>
# include "playGame.h"

bool horizontal_win(int numRows, int numCols, char blankSpot, char** board, char playerPiece, int pieceConnect){
    int countSame = 0;
    printf("%c", playerPiece);
    for (int i = 0; i < numCols; ++i){
        if(board[0][i] == playerPiece){
            countSame += 1;
        }
        else{
            countSame = 0;
        }
    }
    printf("%d", countSame);
    if (countSame == pieceConnect){
        return true;
    }
    else{
        return false;
    }

}

bool win(int numRows, int numCols, char blankSpot, char** board, char playerPiece, int pieceConnect){
    return horizontal_win(numRows, numCols, blankSpot, board, playerPiece, pieceConnect); // || vertical_win() || diagonal_win();
}

bool tie(int numRows, int numCols, char** board, char blankSpot){
    for(int i = 0; i < numRows; ++i){
        for(int j = 0; j < numCols; ++j){
            if(board[i][j] == blankSpot){
                return false;
            }
        }
    }
    return true;
}

bool gameOver(int numRows, int numCols, char blankSpot, char** board, char curPlayerPiece, int pieceConnect){
    return win(numRows, numCols, blankSpot, board, curPlayerPiece, pieceConnect); // || tie(numRows, numCols, board, blankSpot);
}
