#include <stdio.h>
#include <stdlib.h>
#include "Src\Functions.h"



void main()
{
    char turn = 'O';
    char** board = createBoard();
    intro();
    
    printf("Let the game begin!\n");
    
    int mode = gameMode();

    switch (mode)
    {
    case 1:
        turn = swapTurn(turn);
        while (winCon(board, turn) == 0)
        {
            inputBoard(board,turn);
            turn = swapTurn(turn);
        }
        break;
    
    case 2:
        while (winCon(board, turn) == 0)
        {
            turn = swapTurn(turn);
            inputBoard(board, turn);
            turn = swapTurn(turn);
            randomBot(board, turn);
        }
        break;
    
    default:
        break;
    }
   


}