//referencing head file
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//define constant
#define ROW 3
#define COL 3

//define function
void initBoard(char board[ROW][COL],int row,int col){
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
    printf(">>Player Round,please enter a coordinate:");
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
                printf(">>error,please enter another coordinate\n");
            }
        }
        else{
        printf(">>error,please enter again\n");
        }
    }
    
}

void enemyMove(char board[ROW][COL],int row,int col){
    //random generate a coordinate
    printf(">>Enemy round\n");
    int x = 0;
    int y = 0;
    while(1){
        x = rand()%3;//0~2
        y = rand()%3;//0~2
        if(board[x][y] == ' '){
            board[x][y] = '#';
            break;
        }
    }
}

int full(char board[ROW][COL],int row,int col){
    int i = 0;
    int j = 0;
    for(i = 0;i<row;i++){
        for(j = 0;j<col;j++){
            if(board[i][j] == ' '){
                return 0;
            }
        }
    }
    return 1;
}



 char isWin(char board[ROW][COL],int row,int col){
        /*isWIn return value:
        if player win:return '*'
        if enemy win:return '#'
        if is a draw: return 'Q'
        else : return 'C'
        */
    int i = 0;
    for(i=0;i<row;i++){
        if((board[i][0] ==board[i][1]) && (board[i][1] == board[i][2]) && (board[i][1] != ' ')){
            return board[i][1];
        }
    }
    int j = 0;
    for(j=0;j<col;j++){
        if((board[0][j] ==board[1][j]) && (board[1][j] == board[2][j]) && (board[1][j] != ' ')){
            return board[1][j];
        }
    }
    if((board[0][0]== board[1][1]) && (board[1][1] == board[2][2]) && (board[1][1] != ' ')){
        return board[1][1];
    }
    if((board[0][2]== board[1][1]) && (board[1][1] == board[2][0]) && (board[1][1] != ' ')){
        return board[1][1];
    }       
    if(full(board,row,col)){
        return 'Q';
    }
        return 'C';
 }