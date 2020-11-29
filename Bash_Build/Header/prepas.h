
#ifndef prepas_h
#define prepas_h

#include <stdio.h>
#include <stdlib.h>

typedef struct Board Board;
struct Board
{
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
    int cost;
    char name[10];
    Building *next;
};

typedef struct Player Player;
struct Player {
    char name[20];
    int money;
    int salary;
};

typedef struct LinkedList List;
struct LinkedList {
    Building *head;
    int nbBuilds;
};

void *mallocP(size_t size);

int kbhit(void);

void emptyBuffer();

// ==================== Plateau 

List *insertList();

Board *createBoard();

void create2dBoard(Board **b);

void resetboard(Board *b, List *l);

void printBoard(Board *b);

// ==================== Plateau 

// ==================== Bat
void insertEnd(List *li, Building *bu);

Building *newBuilding(Board *b, Player *p, List *li);
// ==================== Bat



#endif /* prepas_h */