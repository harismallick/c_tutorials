#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// typedef char Board[3][3];
// void board_print(Board* grid);

// declaring globals to keep the example simple and not pass pointers across functions.
char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void board_print();
void board_reset();
void move_player();
void move_computer();
void winner_print(char);
int check_free_spaces();
char winner_check();

int main() {
    // Board grid = {{'X','X','X'},{'X','X','X'},{'X','X','X'}};
    // Board *pGrid = &grid;
    // board_print(pGrid);
    char winner = ' '; // Empty space means there is currently no winner and game will continue
    char response; // track user's response to playing the game again.
    char bufferClear;

    do {
        response = ' ';
        winner = ' ';

        board_reset();
        while(winner == ' ' && check_free_spaces() > 0) {
            board_print();
            move_player();
            winner = winner_check();
            if(winner != ' ' || check_free_spaces() == 0) {
                break;
            }
            move_computer();
            winner = winner_check();
            if(winner != ' ' || check_free_spaces() == 0) {
                break;
            }
        }
        board_print();
        winner_print(winner);
        printf("\nWould you like to play again? (Y/N)");
        scanf("%c", &bufferClear);
        scanf("%c", &response);
        response = toupper(response);
    } while(response == 'Y');
    printf("\nThanks for playing! Till next time...\n");

    return 0;
}

// void board_print(Board* grid) {
//     int rows = sizeof(*grid)/sizeof(*grid[0]);
//     int cols = sizeof(*grid[0])/sizeof(*grid[0][0]);

//     printf("Rows = %d\n", rows);
//     printf("Columns = %d\n", cols);

//     for(int i = 0; i < rows; i++) {
//         for(int j = 0; j < cols; j++) {
//             if(j == cols-1) {
//                 printf(" %c ", *(*(*grid + i) + j));
//             }
//             else {
//                 printf(" %c |", *(*(*grid + i) + j));
//             }
//         }
//         printf("\n");
//         if(i != rows-1) {
//             for(int k = 0; k < cols; k++) {
//                 if(k == cols-1) {
//                     printf("---");
//                 }
//                 else {
//                     printf("---|");
//                 }
//             }
//             printf("\n");
//         }
//     }

// }
void board_print() {
    printf(" %c | %c | %c", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---");
    printf("\n %c | %c | %c", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---");
    printf("\n %c | %c | %c", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}
void board_reset() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}
void move_player() {
    int x;
    int y;

    do {
        printf("\nEnter row #(1-3):");
        scanf("%d", &x);
        // scanf("%c", &bufferClear);
        x--;

        printf("\nEnter column #(1-3):");
        scanf("%d", &y);
        // scanf("%c", &bufferClear);
        y--;

        if(board[x][y] != ' ') {
            printf("\nInvalid move!");
        }
        else {
            board[x][y] = PLAYER;
            break;
        }
    } while(board[x][y] != ' ');

}
void move_computer() {
    // computer move will be randomly generated:
    srand(time(0));
    int x;
    int y;
    if(check_free_spaces() > 0) {
        do {
            x = rand() % 3;
            y = rand() % 3;
        } while(board[x][y] != ' ');
        board[x][y] = COMPUTER;
    }
    else {
        winner_print(' ');
    }

}
void winner_print(char winner) {
    if(winner == PLAYER) {
        printf("\nYou win!");
    }
    else if(winner == COMPUTER) {
        printf("\nYou lose.");
    }
    else {
        printf("\nIt's a draw...");
    }
}
int check_free_spaces() {
    int freeSpaces = 9;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != ' ') {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}
char winner_check() {
    // 8 different ways on winning on a tictactoe grid
    if(board[0][2] == board[1][2] && board[0][2] == board[2][2]) {
        return board[0][2];
    }
    else if(board[0][0] == board[0][1] && board[0][0] == board[0][2]) {
        return board[0][0];
    }
    else if(board[0][0] == board[1][0] && board[0][0] == board[2][0]) {
        return board[0][0];
    }
    else if(board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];
    }
    else if(board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];
    }
    else if(board[2][2] == board[2][1] && board[2][2] == board[2][0]) {
        return board[2][2];
    }
    else if(board[0][1] == board[1][1] && board[0][1] == board[2][1]) {
        return board[0][1];
    }
    else if(board[1][0] == board[1][1] && board[1][0] == board[1][2]) {
        return board[1][0];
    }
    return ' ';
}