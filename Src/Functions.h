#include <stdio.h>


void clear(){ printf("\e[1;1H\e[2j"); }


int intro(){
    clear();
    char input;
    printf("Welcome to my TIC-TAC-TOE game \n want to start? \npress [Y] to yes or [N] to exit \n");
    do
    {
        if (scanf("%c", input) != 'Y'){
            printf("Invalid input, try again");
        }
        else{ starGame();}

    } while (input != 'N');
    

        
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


void startGame()
{

}