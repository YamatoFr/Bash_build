#include "./Header/struct.h"
#include "plateau.c"

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void insertEnd(List *li, Building *bu)
// Fonction similaire à une fonction d'insertion en fin de liste
{
    if (li->nbBuilds == 0) {
        li->head = bu;
    } else {
        Building *head = li->head;
        while (head->next != NULL) {
            head = head->next;
        }
        head->next = bu;
    }

    li->nbBuilds++;
}

Building *newBuilding(Board *b, Player *p, List *li) {
    Building *bu = (Building *)mallocP(sizeof(Building));
    bu->next = NULL;
    bu->cost = 0;
    bu->x = 0;
    bu->y = 0;

    insertEnd(li, bu);
    int selecting = 0, choice = 0;

    while (!kbhit()) /* kbhit = keyboard hit */
    {
        char key = getch();
        if (key = "") {
            /* code */
        }
    }
}