#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#define N 12

/* types.h : l'ensemble des types utilisés dans le jeu */


typedef int damier[8][8];

typedef struct
{
	int x;
	int y;
} coup;

typedef enum joueur joueur;
enum joueur {J1, J2};

typedef enum mode mode;
enum mode {JvsJ, JvsCPU};

typedef struct
{
	damier dam;
	joueur jr;
	mode md;
} configuration;

typedef struct
{
	int n_coups;
	int duree;
} score;

typedef struct
{
	int minute;
	int heure;
	int jour;
	int mois;
	int annee;
} date;

typedef struct
{
	damier dam;
	score sco;
	date dt;
	configuration cg;
} sauvegarde;
