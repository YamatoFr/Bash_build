#include "./Header/prepas.h"
// #include <conio.h>
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ==============
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
// ==============

void *mallocP(size_t size) {
    void *p = NULL;
    p = malloc(size);

    if (p == NULL) {
        perror("|!| Erreur alloocation \n");
        exit(EXIT_FAILURE);
    }

    return p;
}

int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

void emptyBuffer() {
    int c = 0;
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

List *insertList() {
    List *List = mallocP(sizeof(List));

    List->head = NULL;
    List->nbBuilds = 0;

    return List;
}

Board *createBoard() {
    Board *b = (Board *)mallocP(sizeof(Board));

    b->width = 10;
    b->height = 10;

    return b;
}

void create2dBoard(Board **b) {
    int **board = (int **)mallocP((*b)->width * sizeof(int *));

    for (int i = 0; i < (*b)->width; i++) {
        board[i] = (int *)mallocP((*b)->height * sizeof(int));
    }
    (*b)->map = board;
}

void resetboard(Board *b, List *l) {
    for (int i = 0; i < b->width; i++) {
        for (int j = 0; j < b->height; j++) {
            (b->map)[i][j] = 0;
        }
    }

    Building *bu = l->head;
    while (b != NULL) {
        showbat(b, bu);
        bu = bu->next;
    }
}

void printBoard(Board *b) {
    printf("\n");

    for (int i = 0; i < b->width; i++) {
        for (int j = 0; j < b->height; j++) {
            int state = (b->map)[i][j];

            if (state == 1) {
                /* case vide */
            }
            if (state == 2) {
                /* on place un batiment */
            }
            if (state == 3) {
                /* le batiment est placé */
            }
        }

        printf("\n");
    }

    printf("\n");
}