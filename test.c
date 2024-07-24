#include "game.h"

//home page
void gameStart(){
    printf("********************\n");
    printf("********************\n");
    printf("*****  1,play  *****\n");
    printf("*****  0,quit  *****\n");
    printf("********************\n");
    printf("********************\n");
}

//game page
void game(){
    char board[ROW][COL];
    initBoard(board,ROW,COL);
    displayBoard(board,ROW,COL);
    char ret;
    while(1){
        playerMove(board,ROW,COL);
        displayBoard(board,ROW,COL);
        
        enemyMove(board,ROW,COL);
        displayBoard(board,ROW,COL);
        // ret = isWin(board,ROW,COL);
        // if(ret != 'C'){
        //     break;
        // }
    }
        if(ret == '*'){
            printf("You Win\n");
        }
        if(ret == 'Q'){
            printf("This Game Is A Draw\n");
        }
       if(ret == '#'){
            printf("You Lose\n");
        }
}
int main(){
    int input = 0;
    srand((unsigned int)time(NULL));
    do{
        gameStart();
        printf("whether to start the game\n");
        printf("please enter(1/0):");
        scanf("%d",&input);
        switch(input){
            case 1:
                game();
                break;
            case 2:
                printf("GAME OVER\n");
                break;
            default:
            printf("error,please input again\n");
                break;
        }
    }while(input);
    return 0;
}