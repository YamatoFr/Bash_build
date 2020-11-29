
#ifndef structs_h
#define structs_h

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int width;
    int height;
    int **map;
} Board;

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

#endif /* structs_h */