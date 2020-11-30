
#ifndef prepas_h
#define prepas_h

#include <stdio.h>
#include <stdlib.h>


typedef struct Board Board;
struct Board {
    int width;
    int height;
    int **map;
};

typedef struct Building Building;
struct Building {
    int x;
    int y;
    int width;
    int height;
    int id;
    int lvl;
    int cost;
    int current;
    int currentDay;
    int building_income;
    int pandingB;
    char name[10];
    Building *next;
};

typedef struct Player Player;
struct Player {
    char name[20];
    int money;
    int earnings;
};

typedef struct LinkedList List;
struct LinkedList {
    Building *head;
    int nbBuilds;
};

// ===================================================================================

void *mallocP(size_t size);

void cleanBuffer();

// ==================== Plateau

List *insertList();

Board *createBoard();

// void sizeChoice();

void create2dBoard(Board **b);

void resetboard(Board *b, List *p_liste);

// ==================== Plateau

// ==================== Bat

void drawBuilding(Board *b, Building *bu, int state);

void insertEnd(List *li, Building *p_building);

Building *newBuilding(Board *b, Player *p_player, List *p_liste, int day);

void printBuilding(Building *p_building);

// ==================== Bat

// ==================== Joeur
Player *createPlayer();
// ==================== Joeur

#endif /* prepas_h */