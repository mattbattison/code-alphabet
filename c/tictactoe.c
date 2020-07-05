#include<stdio.h>

void clearScreen() {
    printf("\x1b[2J");
    printf("\x1b[H");
}

int main() {
    clearScreen();
    printf("===========\n");
    printf("TIC TAC TOE\n");
    printf("===========\n");
    return 0;
}
