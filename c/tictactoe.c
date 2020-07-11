#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

void clearScreen() {
    printf("\x1b[2J");
    printf("\x1b[H");
}


void getWindowSize(int *rows, int *cols) {
    struct winsize ws;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);

    *cols = ws.ws_col;
    *rows = ws.ws_row;
}


void printHeader(int cols) {

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

}


int main() {
    clearScreen();

    int rows;
    int cols;
    getWindowSize(&rows, &cols);

    printHeader(cols);

    return 0;
}
