#include "./Header/struct.h"
#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
=======
#include <conio.h>
#include "structs.c"
>>>>>>> a044e23d7fa1a2bb6892459962f1da5350f46796

void *mallocP(size_t size) {
    void *p = NULL;
    p = malloc(size);

    if (p == NULL) {
        perror("|!| Erreur alloocation \n");
        exit(EXIT_FAILURE);
    }

    return p;
}

void emptyBuffer() {
    int a = 0;

    while (a != "\n" && a != EOF) {
        a = getchar();
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

<<<<<<< HEAD
void resetboard(Board **b, List *l) {
    for (int i = 0; i < b->width; i++) {
        for (int j = 0; j < b->height; j++) {
=======
void resetboard(Board **b, List *l)
{
    for (int i = 0; i < b->width; i++)
    {
        for (int j = 0; j < b->height; j++)
        {
>>>>>>> a044e23d7fa1a2bb6892459962f1da5350f46796
            (b->map)[i][j] = 0;
        }
    }

    Building *bu = l->head;
<<<<<<< HEAD
    while (b != NULL) {
=======
    while (b != NULL)
    {
>>>>>>> a044e23d7fa1a2bb6892459962f1da5350f46796
        showbat(b, bu);
        bu = bu->next;
    }
}

<<<<<<< HEAD
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
=======
void printBoard(Board *b)
{
    printf("\n");

    for (int i = 0; i < b->width; i++)
    {
        for (int j = 0; j < b->height; j++)
        {
            int state = (b->map)[i][j];

            if (state == 1)
            {
                /* case vide */
            }
            if (state == 2)
            {
                /* on place un batiment */
            }
            if (state == 3)
            {
>>>>>>> a044e23d7fa1a2bb6892459962f1da5350f46796
                /* le batiment est placé */
            }
        }

        printf("\n");
    }

    printf("\n");
}