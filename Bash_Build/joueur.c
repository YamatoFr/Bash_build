#include "./Header/prepas.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cleanBuffer() {
    int c = 0;
    while (c != '\n' && c != EOF)
        c = getchar();
}

Player *createPlayer() {
    Player *p = mallocP(sizeof(Player));
    printf("Entrez votre nom: \n");
    cleanBuffer();
    fgets(p->name, 20, stdin);
    p->money = 300;
    p->earnings = 0;

    return p;
}