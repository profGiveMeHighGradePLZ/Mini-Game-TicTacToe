#include "game.h"

void initBoard(char board[ROW][COL],int row, int col){
    int i = 0;
    int j = 0;
    for(i = 0;i<row;i++){
        for(j=0;j<col;j++){
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[ROW][COL],int row, int col){
    /*ideal demo:
    |---|---|---|
    | # | # |   |
    |---|---|---|
    |   | * |   |
    |---|---|---|
    |   | * | # |
    |---|---|---|*/

    int i = 0;
    for(i=0;i<row;i++){
    //print |---|---|---|
        int j1 = 0;
        for(j1=0;j1<=col;j1++){
            if(j1!=col){
                printf("|---");
            }
            else{
                printf("|\n");
            }
        }
    //print | * |   | # |
        int j2 = 0;
        for(j2=0;j2<=col;j2++){
            if(j2!=col){
                printf("| %c ",board[i][j2]);
            }
            else{
                printf("|\n");
            }
        }
    }
        int j = 0;
        for(j=0;j<=col;j++){
            if(j!=col){
                printf("|---");
            }
            else{
                printf("|\n");
            }
        }
}

void playerMove(char board[ROW][COL],int row,int col){
    //player input a coordinate
    printf("Player Round,please enter a coordinate:");
    while(1){
        int a = 0;
        int b = 0;
        scanf("%d %d",&a,&b);
        // check whether within the board
        if(1<=a && a<=row && 1<=b && b<=col){
            //check whether the coordinate is useful
            if(board[a-1][b-1] == ' '){
                board[a-1][b-1] = '*';
                break;
            }
            else{
                printf("error,please enter another coordinate\n");
            }
        }
        else{
        printf("error,please enter again\n");
        }
    }
    
}