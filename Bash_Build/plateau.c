
#include "./Header/prepas.h"

#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *mallocP(size_t size) {
    void *p = NULL;
    p = malloc(size);

    if (p == NULL) {
        perror("|!| Erreur alloocation \n");
        exit(EXIT_FAILURE);
    }

    return p;
}

List *insertList() {
    List *p_liste = mallocP(sizeof(List));

    p_liste->head = NULL;
    p_liste->nbBuilds = 0;

    return p_liste;
}

void create2dBoard(Board **b) {
    int **p_board = mallocP((*b)->width * sizeof(*p_board));

    for (int i = 0; i < (*b)->width; i++) {
        p_board[i] = mallocP((*b)->height * sizeof(p_board));
    }
    (*b)->map = p_board;
}

Board *createBoard() {
    Board *b = (Board *)mallocP(sizeof(Board));

    int not_done = 0, choice;

    while (not_done == 0) {
        printf("Choose the size of your tray : \n");
        printf("============================\n");
        printf("Make choice : \n");
        printf("[1] Tray 10 by 10\n");
        printf("[2] Tray 20 by 20\n");
        printf("[3] Make your own tray\n");
        printf("============================\n");
        printf("Your choince : \n");
        scanf("%d", &choice);

        if (choice == 1) {
            b->width = 10;
            b->height = 10;
            not_done = 1;
        }

        if (choice == 2) {
            b->width = 20;
            b->height = 20;
            not_done = 1;
        }

        if (choice == 3) {
            b->width = 10;
            b->height = 10;
            printf("Enter a width and height greater than 10\n");
            while (b->height <= 10 || b->width <= 10) {
                printf("\n");
                printf("============================\n");
                printf("Enter width : \n");
                scanf("%d", &b->width);
                printf("\n");
                printf("Enter height : \n");
                scanf("%d", &b->height);
                printf("============================\n");
                printf("\n");

                if (b->height <= 10 || b->width <= 10) {
                    perror("|!| Error : please enter a height and width greater or equal than 10.\n");
                }
            }
            not_done = 1;
        }
    }

    return b;
}

void resetboard(Board *b, List *p_liste) {
    for (int i = 0; i < b->width; i++) {
        for (int j = 0; j < b->height; j++) {
            (b->map)[i][j] = 0;
        }
    }
    Building *p_building = p_liste->head;

    while (p_building != NULL) {
        drawBuilding(b, p_building, p_building->current ? 2 : 1);
        p_building = p_building->next;
    }
}

void printBoard(Board *b) {
    printf("\n");

    for (int i = 0; i < b->width; i++) {
        for (int j = 0; j < b->height; j++) {
            int state = (b->map)[i][j];

            if (state == 0) {
                printf(" \033[32;1m.\033[0m");
            }

            if (state == 1) {
                printf(" \033[34;1m#\033[0m");
            }

            if (state == 2) {
                printf(" #");
            }
        }

        printf("\n");
    }

    printf("\n");
}