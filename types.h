

/* types.h : l'ensemble des types utilisés dans le jeu */


typedef int damier[8][8];

typedef struct
{
	int x;
	int y;
} coup;

typedef enum joueur joueur;
enum joueur {J1, J2, CPU};

typedef enum mode mode;
enum mode {1VS2, 1VSCPU};

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
