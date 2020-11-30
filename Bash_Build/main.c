/* En accord avec le groupe, les noms de variables seront en anglais */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

        system("clear");
        printf("[Day %d | %d € | +%d € per day ]\n", day, p_player->money, p_player->earnings);
        printf("\n");
        resetboard(p_board, buildingList);
        printBoard(p_board);

        printf("\n");
        printf("\033[1;35;1m%s\033[0m What to do? : \n", p_player->name);
        // printf("\033[1;35;1m%s\033[0m What to do? : \n", p_player->name);
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
            newBuilding(p_board, p_player, day, buildingList);
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