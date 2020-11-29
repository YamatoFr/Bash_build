/* En accord avec le groupe, les noms de variables seront en anglais */

#include <stdbool.h>
// #include <conio.h>
// #include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./Header/prepas.h"
#include "batiments.c"
#include "joueur.c"
#include "plateau.c"

int main()
{
    // system("cls");
    system("clear");
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

        // system("cls");
        system("clear");
        printf("| Jour %d | %d e | +%d e par jour |\n", day, p->money, p->salary);

        resetboard(b, buildingList);
        printBoard(b);
    }
}