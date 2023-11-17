# include <stdio.h>

void print_cur_board(int numRows, int numCols, char board[][3]){
    /*   
    initial board looks like this, 3 rows 3 cols
    2 * * *
    1 * * *
    0 * * *
      0 1 2 
    */

    for(int i = numRows - 1 ; i >= 0; --i){
        printf("%d ", i);
        for(int j = 0; j < numCols; ++j){
            printf("%c ", board[numRows - i][j]);
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

int main(){
    int numRows = 3;
    int numCols = 3;
    char board[3][3];

    for(int i = 0; i < numRows; ++i){
        for(int j = 0; j < numCols; ++j){
            board[i][j] = '*';
        }
    }
    print_cur_board(numRows, numCols, board);
    return 0;
}