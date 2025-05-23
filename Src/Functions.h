#include <stdio.h>
#include <stdlib.h>
void clearCMD(){
    printf("\e[1;1H\e[2J");
}

void clearInputBuffer(){ 
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
 }

void startGame()
{
    printf("certo");
}

int intro(){
    char input;
    printf("Welcome to my TIC-TAC-TOE game \nWant to start? \nPress [Y] to play or [N] to exit \n");
    fflush(stdout);

    while(1)
    {

        if (scanf("%c", &input) != 1)
        {
            clearInputBuffer();
            printf("Invalid input, try again\npress [Y] to play or [N] to exit \n");
        }
        
        clearInputBuffer();
        
        clearCMD();

        if(input == 'Y') {
            printf("Let the game begin!\n");
            startGame();
            break;
        } else if(input == 'N'){
            break;
        }else{ 
            printf("Invalid input, try again\npress [Y] to play or [N] to exit \n");
        }
    }
    

    return 0;
}


void createBoard()
{

}


void updateBoard()
{
    
}

void drawBoard()
{

}

