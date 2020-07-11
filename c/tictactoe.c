#include <stdlib.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>


void clearScreen() {
    printf("\x1b[2J");
    printf("\x1b[H");
}


int getWindowCols() {
    struct winsize ws;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);

    return ws.ws_col;
}


void printHeader() {

    int cols = getWindowCols();

    for (int i = 0; i < cols; i++) {
        printf("=");
    }
    printf("\n");
    for (int i = 0; i < (cols/2 - 7); i++) {
        printf("=");
    }
    printf(" TIC TAC TOE ");
    for (int i = 0; i < (cols/2 - 6); i++) {
        printf("=");
    }
    if (cols % 2 != 0) {
        printf("=");
    }
    printf("\n");
    for (int i = 0; i < cols; i++) {
        printf("=");
    }
    printf("\n");
    printf("\n");

}


void printBoard(char* b) {

    printf("  =-----=-----=-----=\n");
    printf("  |     |     |     |\n");
    printf("  |  %c  |  %c  |  %c  |\n", b[0], b[1], b[2]);
    printf("  |     |     |     |\n");

    printf("  =-----=-----=-----=\n");
    printf("  |     |     |     |\n");
    printf("  |  %c  |  %c  |  %c  |\n", b[3], b[4], b[5]);
    printf("  |     |     |     |\n");

    printf("  =-----=-----=-----=\n");
    printf("  |     |     |     |\n");
    printf("  |  %c  |  %c  |  %c  |\n", b[6], b[7], b[8]);
    printf("  |     |     |     |\n");
    printf("  =-----=-----=-----=\n");

    printf("\n");

}


void clearInputBuffer() {
    char input;
    while((input = getchar()) != '\n' && input != EOF) {}
}


int getMove(char* board) {

    while(1) {

        printf("\nChoose a square: ");
        char input = getchar();

        if (input == '\n') {
            printf("Please enter a choice!\n");
            continue;
        }

        if (input == EOF) {
            printf("\n\nError: unexpected EOF!\n");
            exit(1);
        }

        clearInputBuffer();

        int choice = input - '0';

        if (choice < 1 || choice > 9) {
            printf("Please enter a number between 1 and 9.\n");
            continue;
        }

        if (board[choice - 1] != input) {
            printf("That position is taken!\n");
            continue;
        }

        return choice;
    }
}


void checkForWinner(char* board) {
    char winner = 0;

    // rows
    if ((board[0] == board[1]) && (board[1] == board[2])) {
        winner = board[0];
    }
    if ((board[3] == board[4]) && (board[4] == board[5])) {
        winner = board[3];
    }
    if ((board[6] == board[7]) && (board[7] == board[8])) {
        winner = board[6];
    }

    // columns
    if ((board[0] == board[3]) && (board[3] == board[6])) {
        winner = board[0];
    }
    if ((board[1] == board[4]) && (board[4] == board[7])) {
        winner = board[1];
    }
    if ((board[2] == board[5]) && (board[5] == board[8])) {
        winner = board[2];
    }

    // diagonals
    if ((board[0] == board[4]) && (board[4] == board[8])) {
        winner = board[0];
    }
    if ((board[2] == board[4]) && (board[4] == board[6])) {
        winner = board[2];
    }

    if (winner) {
        clearScreen();
        printHeader();
        printBoard(board);

        printf("%s wins!!\n\n", winner == 'o' ? "Noughts" : "Crosses");

        exit(0);
    }

}


int main() {

    char board[] = "123456789";
    bool playerFlag = true;

    int turn = 1;
    while(turn <= 9) {
        clearScreen();
        printHeader();

        printBoard(board);
        printf("%s, it's your turn!\n", playerFlag ? "Crosses" : "Noughts");
        int move = getMove(board);
        board[move - 1] = playerFlag ? 'x' : 'o';

        checkForWinner(board);

        playerFlag = !playerFlag;
        turn++;
    }

    clearScreen();
    printHeader();

    printBoard(board);
    printf("It's a draw!!\n\n");

    return 0;
}
