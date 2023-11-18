#include <stdbool.h>
#include <stdlib.h>
#include "win.h"

bool all_same(char* characters, int size){
    for(int i = 1; i < size; ++i){
        if(characters[i] != characters[0]){
            return false;
        }
    }
    return true;
}
bool someone_won(char** board, int numRows,int numCols, char blank_space){
    return someone_won_horizontally(board, int numRows,int numCols, blank_space) ||
           someone_won_vertically(board,int numRows,int numCols, blank_space) || 
           someone_won_diagonally(board,int numRows,int numCols, blank_space);
}
bool someone_won_horizontally(char** board, int numRows,int numCols, char blank_space)
{
    for(int i = 0; i < numRows; ++i){
        if(board[i][0] != blank_space && all_same(board[i],numCols)){
            return true;
        }
    }
    return false;
}
char* get_column(int column_index, char** board, int numRows){
    char* column = (char*)calloc(dimensions, sizeof(char));
    for(int i = 0; i < numRows; ++i){
        column[i] = board[i][column_index];
    }
    return column;
}
bool someone_won_vertically(char** board, int numRows,int numCols, char blank_space)
{
    for(int i = 0; i < numRows; ++i){
        char* column = get_column(i, board, numRows);
        if(column[0] != blank_space && all_same(column, numRows)){
            free(column);
            return true;
        }
        free(column);
    }
    return false;
}
bool someone_won_diagonally()
