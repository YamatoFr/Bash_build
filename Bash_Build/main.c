/* En accord avec le groupe, les noms de variables seront en anglais */

#include <stdbool.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./Header/struct.h"
#include "batiments.c"
#include "plateau.c"
#include "joueur.c"

int main()
{
    system("cls");
    bool playing = true;
    int day = 0;

    Board *b = createBoard();
    printf("\n");
    Player *p = createPlayer();
    List *buildingList = insertList();

    create2dBoard(&b);

    while (playing == true)
    {
        day++;
        p->money += p->salary;

        system("cls");
        printf("| Jour %d | %de | +%d€ par jour |\n", day, p->money, p->salary);

        resetboard(b, buildingList);
        printBoard(b);
    }
}