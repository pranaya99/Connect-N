#ifndef WIN_H
    #define WIN_H
    bool all_same(char* characters, int size);
    bool someone_won(char** board, int numRows,int numCols, char blank_space);
    bool someone_won_horizontally(char** board, int numRows,int numCols, char blank_space);
    char* get_column(int column_index, char** board, int numRows);
    bool someone_won_vertically(char** board, int numRows,int numCols, char blank_space);
    #endif