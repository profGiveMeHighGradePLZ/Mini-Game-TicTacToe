//referencing head file
#include <stdio.h>

//define constant
#define ROW 3
#define COL 3

//define function
void initBoard(char board[ROW][COL],int row,int col);
void displayBoard(char board[ROW][COL],int row, int col);
void playerMove(char board[ROW][COL],int row,int col);