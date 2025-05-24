#include <stdio.h>
#include <stdlib.h>
#include "Src\Functions.h"



void main()
{
    char turn = 'X';
    char** board = createBoard();
    intro();
    int mode = gameMode();

 
    switch (mode)
    {
    case 1:
        printf("Let the game begin!\n");
        drawBoard(board);

        while (winCon(board, turn) == 0)
        {
            inputBoard(board,turn);
            turn = swapTurn(turn);
        }
        break;
    
    case 2:
        printf("Let the game begin!\n");
        drawBoard(board);

        while (winCon(board, turn) == 0)
        {
            inputBoard(board, turn);
            turn = swapTurn(turn);
            randomBot(board, turn);
            turn = swapTurn(turn);
        }
        break;
    
    default:
        break;
    }
   


}