#include <stdio.h>
int check();
void board();
char tile[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int main(){
    int player = 1, choice, flag;
    char symbol;
    printf("Tic Tac Toe\n\n");
    printf("Player 1 will play as 'X'\nPlayer 2 will play as 'O'\n\n\n");
    printf("The rules are simple.\nBe the first player to get three of your symbols in a row.\nIt can be horizontally, vertically or even diagonally.\n");
    printf("Each player will enter a number when prompted to choose the postion of your symbol on the grid.\n");
    printf("Player 1 goes first.\n\n");

    do{
        board();
        player = (player % 2 != 0) ? 1 : 2;
        printf("Player %d, enter a number:  ", player);
        scanf("%d", &choice);
        symbol = (player == 1) ? 'X' : 'O';
        if (choice == 1 && tile[1] == '1')
            tile[1] = symbol;
        else if (choice == 2 && tile[2] == '2')
            tile[2] = symbol;
        else if (choice == 3 && tile[3] == '3')
            tile[3] = symbol;
        else if (choice == 4 && tile[4] == '4')
            tile[4] = symbol;
        else if (choice == 5 && tile[5] == '5')
            tile[5] = symbol;
        else if (choice == 6 && tile[6] == '6')
            tile[6] = symbol;
        else if (choice == 7 && tile[7] == '7')
            tile[7] = symbol;
        else if (choice == 8 && tile[8] == '8')
            tile[8] = symbol;
        else if (choice == 9 && tile[9] == '9')
            tile[9] = symbol;
        else{
            printf("Invalid move");
            player--;}
        flag = check();
        player++;
    }while (flag ==  - 1);
    board();
    if (flag == 1)
        printf("Player %d has won the game!", player-1);
    else
        printf("The game has resulted in a draw");
    return 0;


int check()
{
    if (tile[1] == tile[2] && tile[2] == tile[3])
        return 1;
    else if (tile[4] == tile[5] && tile[5] == tile[6])
        return 1;
    else if (tile[7] == tile[8] && tile[8] == tile[9])
        return 1;
    else if (tile[1] == tile[4] && tile[4] == tile[7])
        return 1;
    else if (tile[2] == tile[5] && tile[5] == tile[8])
        return 1;
    else if (tile[3] == tile[6] && tile[6] == tile[9])
        return 1;
    else if (tile[1] == tile[5] && tile[5] == tile[9])
        return 1;
    else if (tile[3] == tile[5] && tile[5] == tile[7])
        return 1;
    else if (tile[1] != '1' && tile[2] != '2' && tile[3] != '3' && tile[4] != '4' && tile[5] != '5' && tile[6] != '6' && tile[7] != '7' && tile[8] != '8' && tile[9] != '9')
        return 0;
    else
        return  - 1;
}

void board()
{
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", tile[1], tile[2], tile[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", tile[4], tile[5], tile[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", tile[7], tile[8], tile[9]);
    printf("     |     |     \n\n");
}
