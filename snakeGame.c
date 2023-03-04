#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#define BOARD_SIZE 20
#define INITIAL_SNAKE_LENGTH 3

char board[BOARD_SIZE][BOARD_SIZE];
int snake[BOARD_SIZE * BOARD_SIZE][2] = {{BOARD_SIZE/2,BOARD_SIZE/2}, {BOARD_SIZE/2,BOARD_SIZE/2 - 1}, {BOARD_SIZE/2,BOARD_SIZE/2 - 2}};
int snakeLength = INITIAL_SNAKE_LENGTH;

void initializeBoard() {
    // initialize edges with #
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[0][i] = '#';
        board[BOARD_SIZE-1][i] = '#';
        board[i][0] = '#';
        board[i][BOARD_SIZE-1] = '#';
    }

    // initialize remaining cells with .
    for (int i = 1; i < BOARD_SIZE-1; i++) {
        for (int j = 1; j < BOARD_SIZE-1; j++) {
            board[i][j] = '.';
        }
    }

    // initialize snake cells with *
    for (int i = 0; i < INITIAL_SNAKE_LENGTH; i++) {
        int row = snake[i][0];
        int col = snake[i][1];
        board[row][col] = '*';
    }
}

void printBoard() {
    printf("\n");
    system("clear");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void moveSnake(char direction) {

    // update tail positions
    for (int i = snakeLength-1; i > 0; i--) {
        snake[i][0] = snake[i-1][0];
        snake[i][1] = snake[i-1][1];
    }

    // update head position
    switch (direction) {
        case 'd':
            snake[0][1] = snake[0][1] + 1 ;
            break;
        case 's':
            break;
        case 'a':
            break;
        case 'w':
            break;
    }

    // update board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '*') {
                board[i][j] = '.';
            }
        }
    }
    
    for (int i = 0; i < snakeLength; i++) {
        int row = snake[i][0];
        int col = snake[i][1];
        board[row][col] = '*';
    }
}

int main() {
    initializeBoard();
    printBoard();
    char direction = 'd';
    bool isGameOver = false;

    while (!isGameOver){
        sleep(1);
        moveSnake(direction);
        printf("\n");
        printBoard();
    }

    return 0;
}