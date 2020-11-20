#include <stdio.h>
#include <stdlib.h>
#include "structs.c"

void *mallocP(size_t size)
{
	void *p = NULL;
	p = malloc(size);

	if (p == NULL)
	{
		printf("Erreur mémoire\n");
		exit(0);
	}

	return p;
}

void emptyBuffer()
{
	int a = 0;

	while (a != "\n" && a != EOF)
	{
		a = getchar();
	}
}

List *insertList()
{
	List *List = mallocP(sizeof(List));

	List->head = NULL;
	List->nbBuilds = 0;

	return List;
}

Board *createBoard()
{
	Board *b = (Board *)mallocP(sizeof(Board));

	b->width = 10;
	b->height = 10;

	return b;
}

void create2dBoard(Board **b)
{
	int **board = (int **)mallocP((*b)->width * sizeof(int *));

	for (int i = 0; i < (*b)->width; i++)
	{
		board[i] = (int *)mallocP((*b)->height * sizeof(int));
	}
	(*b)->map = board;
}

void initBoard(Board **b)
{
	for (int i = 0; i < (*b)->width; i++)
	{
		for (int j = 0; j < (*b)->height; j++)
		{
			((*b)->map)[i][j] = 0;
		}
	}
}

void printBoard(Board *b)
{
	printf("\n");

	for (int i = 0; i < b->width; i++)
	{
		for (int j = 0; j < b->height; j++)
		{
			// Formatage
			int pb = (b->map)[i][j];
			if (pb) // <=> pb == True
			{
				printf("%3d", pb); // meilleur visuel , ne pas changer
			}
			else
			{
				printf(".  "); // Représente les cases vides
			}
		}
		printf("\n"); // Saut de ligne
	}
	printf("\n") // Saut de ligne après le tableau
}