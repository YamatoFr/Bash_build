#include <stdio.h>
#include <stdlib.h>
#include "structs.c"

void insertEnd(List *List, Board *b, Player *p, Building *bu)
// Fonction similaire à une fonction d'insertion en fin de liste
{
	if (List->nbBuilds == 0)
	{
		List->head = bu;
	}
	else
	{
		Building *build = List->head;
		while (build->next != NULL)
		{
			build = build->next;
		}
		build->next = build;
	}
}

Building *newBuilding(Board *b, Player *p, List *List)
{
}