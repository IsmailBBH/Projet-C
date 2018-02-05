#ifndef TYPES
#define TYPES

#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#define N 12

/* types.h : l'ensemble des types utilisés dans le jeu */


typedef int tab2[10][2]; // tableau de 2 dimensions 

typedef char string[10][50]; // tableau des chaines de caractères

typedef int damier[9][8];

typedef struct
{
	int x;
	int y;
} coup;

typedef enum joueur joueur;
enum joueur {J1, J2};


#endif
