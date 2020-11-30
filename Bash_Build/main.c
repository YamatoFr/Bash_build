/* En accord avec le groupe, les noms de variables seront en anglais */

#include <stdbool.h>
// #include <conio.h>
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./Header/prepas.h"
#include "batiments.c"
#include "joueur.c"
#include "plateau.c"

int main(int argc, const char **argv) {
    // system("cls");
    system("clear");
    bool playing = true;
    int day = 0, choice;

    Board *p_board = createBoard();
    printf("\n");
    Player *p_player = createPlayer();
    List *buildingList = insertList();

    create2dBoard(&p_board);

    while (playing == true) {

        p_player->money += p_player->earnings;

        //  system("cls");
        system("clear");
        printf("[Day %d | %d € | +%d € per day ]\n", day, p_player->money, p_player->earnings);
        // printf("/ Prets /");
        printf("\n");

        resetboard(p_board, buildingList);
        printBoard(p_board);

        printf("Building [%d] :", buildingList->nbBuilds);

        Building *pbuilding = buildingList->head;

        // while (pbuilding != NULL) {
        //     if (pbuilding->id == 0) {
        //         printf("Bank");
        //     }
        //     if (pbuilding->id == 1) {
        //         printf("House");
        //     }
        //     pbuilding = pbuilding->next;
        // }

        printf("\n");
        printf("%s What to do? : \n", p_player->name);
        printf("============================\n");
        printf("Make choice : \n");
        printf("[1] Build building\n");
        printf("[2] Loan monney\n");
        printf("[3] Next day\n");
        printf("[0] \033[31;1mExit\33[0m\n");
        printf("============================\n");
        printf("Your choince : \n");
        scanf("%d", &choice);

        if (choice == 0) {
            playing = false;
            exit(EXIT_SUCCESS);
        }

        if (choice == 1) {
            newBuilding(p_board, p_player, buildingList, day);
        }

        if (choice == 2) {
            p_player->money = p_player->money * 5;
        }

        if (choice == 3) {
            day++;
        }
    }

    return 0;
}