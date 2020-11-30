#include "./Header/prepas.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void insertEnd(List *li, Building *p_building) {
    if (li->nbBuilds == 0) {
        li->head = p_building;
    } else {
        Building *head = li->head;
        while (head->next != NULL) {
            head = head->next;
        }
        head->next = p_building;
    }

    li->nbBuilds++;
}

Building *newBuilding(Board *b, Player *p_player, int day, List *p_liste) {
    Building *p_building = (Building *)mallocP(sizeof(Building));
    p_building->next = NULL;
    p_building->cost = 0;
    p_building->x = 1;
    p_building->y = 1;
    bool not_done = true;
    int choice;
    insertEnd(p_liste, p_building);

    while (not_done == true) {
        system("clear");
        // system("cls");  

        printf("\033[1;35;1m%s\033[0m you have [%d€] in your wallet  \n", p_player->name, p_player->money);

        printf("\n \n");
        printf("Choose type of building : \n");
        printf("============================\n");
        printf("Make choice : \n");
        printf("[1] Buy Bank |1000€|\n");
        printf("[2] Buy House |300€|\n");
        printf("[0] \033[36;1mCancel\033[0m\n");
        printf("============================\n");
        printf("Your choince : \n");
        scanf("%d", &choice);

        if (choice == 0) {
            return NULL;
        }

        if (choice == 1) {
            p_building->id = 1;
            p_building->cost = 1000;
            p_building->width = 4;
            p_building->height = 4;
            p_building->building_income = 100;
            not_done = false;
        }

        if (choice == 2) {
            p_building->id = 2;
            p_building->cost = 300;
            p_building->width = 2;
            p_building->height = 2;
            p_building->building_income = 0;
            not_done = false;
        }
    }
    not_done = true;
    while (not_done == true) {
        system("clear");

        resetboard(b, p_liste);
        printBoard(b);

        printf("Set position\n");
        printf("============================\n");
        printf("[1] move up\n");
        printf("[2] move down\n");
        printf("[3] move left\n");
        printf("[4] move right\n");
        printf("[0] \033[36;1mConfirm\033[0m\n");
        printf("============================\n");
        printf("Your choince : \n");
        scanf("%d", &choice);

        if (choice == 1 && p_building->y >= 0) {
            (p_building->y) = p_building->y - 1;
        }

        if (choice == 2 && p_building->y >= 0) {
            (p_building->y) = p_building->y + 1;
        }

        // if (p_building->y < (p_building->height - b->height)) {
        //     (p_building->y) = p_building->y + 1;
        // }

        // =====================================================

        if (choice == 3 && p_building->x >= 0) {
            (p_building->x) = p_building->x - 1;
        }

        if (choice == 4 && p_building->x >= 0) {
            (p_building->x) = p_building->x + 2;
        }

        // if (p_building->x < (p_building->width - b->width)) {
        //     (p_building->x) = p_building->x + 1;
        // }

        // =====================================================

        if (choice == 0) {
            not_done = false;
        }
    }
    p_player->earnings = p_player->earnings + p_building->building_income;
    p_player->money = p_player->money - p_building->cost;

    return p_building;
}

void drawBuilding(Board *b, Building *bu, int state) {
    for (int k = bu->x; k < bu->x + bu->width; k++) {
        for (int l = bu->y; l < bu->y + bu->height; l++)
            (b->map)[l][k] = state;
    }
}