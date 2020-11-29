#include "./Header/prepas.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Player *createPlayer() {
    Player *p = (Player *)mallocP(sizeof(Player));
    printf("Entrez votre nom: ");
    fgets(p->name, 20, stdin);
    p->money = 100;
    p->salary = 0;
}