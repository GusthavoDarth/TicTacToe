#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void clearCMD(){
    printf("\e[1;1H\e[2J");
}

void clearInputBuffer() { int c; while ((c = getchar()) != '\n' && c != EOF); }

 char swapTurn(char turn) { return (turn == 'X') ? (turn = 'O') : (turn = 'X'); }

void drawBoard(char** board)
{
    clearCMD();
    printf("    0     1    2     \n");
    printf("0   %c  |  %c  |  %c \n",board[0][0],board[0][1],board[0][2]);
    printf("   ----+-----+----   \n");
    printf("1   %c  |  %c  |  %c \n",board[1][0],board[1][1],board[1][2]);
    printf("   ----+-----+----   \n");
    printf("2   %c  |  %c  |  %c \n",board[2][0],board[2][1],board[2][2]);
}

void winText(char** board, char turn){
    drawBoard(board);
    printf("The winner is %c!",turn);
}

void intro()
{
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
            break;
        } else if(input == 'N'){
            exit(EXIT_SUCCESS);
            break;
        }else{ 
            printf("Invalid input, try again\npress [Y] to play or [N] to exit \n");
        }
    }
}

int gameMode(){
    int choice;
    printf("Chose how to play, type\n");
    printf("[1] to play Player vs Player\n");
    printf("[2] to play Player vs Bot(easy)\n");
    // printf("[3] to play Player vs Bot(hard)"); to do
    scanf("%d", &choice); 
    return choice;
}

char** createBoard()
{
    const int size = 3;
    char** matrix = malloc(size * sizeof(char*));

    if (matrix == NULL){return NULL;}

    for (int row = 0; row < size; row++)
    {
        matrix[row] = malloc(size * sizeof(int));
        if (matrix[row] == NULL){
            for (int i; i < row; i++){
                free(matrix[i]);
            }
        }

        for (int column = 0; column < size; column++)
        {
            matrix[row][column] = ' ';
        }
        
    }
    return matrix;
}

char** inputBoard(char** board, char turn)
{
    int row, col;
    drawBoard(board);
    
    printf("\nTurn of '%c' \n", turn);
    printf("Chose the position\n");
    printf("Fist the row: ");
    scanf("%d", &row);
    printf("Now the column: ");
    scanf("%d", &col);

    
    if (board[row][col] == 'O' || board[row][col] == 'X' ){
        printf("Invalid position\n");
        inputBoard(board, turn);

    } else { 
        board[row][col] = turn;
    }
            
    return board;
}

char** randomBot(char** board, char turn){
    int row,col;
    row = rand() % 3;
    col = rand() % 3;

    while(board[row][col] != ' '){
        row = rand() % 3;
        col = rand() % 3;
    }
    board[row][col] = turn;

    return board; 
}


int winCon(char** board, char turn){
    if     (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O' || board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') 
    { winText(board, swapTurn(turn)); return 1;}
    else if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O' || board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') 
    {winText(board, swapTurn(turn)); return 1;}
    else if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O' || board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') 
    {winText(board, swapTurn(turn)); return 1;}
    else if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O' || board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') 
    {winText(board, swapTurn(turn)); return 1;}
    else if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O' || board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') 
    {winText(board, swapTurn(turn)); return 1;}
    else if(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O' || board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') 
    {winText(board, swapTurn(turn)); return 1;}
    else if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O' || board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') 
    {winText(board, swapTurn(turn)); return 1;}
    else if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O' || board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') 
    {winText(board, swapTurn(turn)); return 1;}

    return 0;
}