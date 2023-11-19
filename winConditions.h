# ifndef WINCONDITIONS_H
# define WINCONDITIONS_H
    bool horizontal_win(int numCols, char blankSpot, char** board, char playerPiece, int pieceConnect);
    bool win(int numRows, int numCols, char blankSpot, char** board, char playerPiece, int pieceConnect);
    bool tie(int numRows, int numCols, char** board, char blankSpot);
    bool gameOver(int numRows, int numCols, char blankSpot, char** board, char curPlayerPiece, int pieceConnect);
# endif