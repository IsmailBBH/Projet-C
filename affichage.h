#include "types.h"

#ifndef AFFICHAGE
#define AFFICHAGE

/* affichage.h : fonction qui gèrent l'affichage */

///////////////////////////////////////////////////////////////////////////////////////////////////////

void init_damier(damier d) // initialiser le damier
{
	int i, j;
	damier t = {{0,2,0,2,0,2,0,2},
							{2,0,2,0,2,0,2,0},
							{0,2,0,2,0,2,0,2},
							{0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0},
							{1,0,1,0,1,0,1,0},
							{0,1,0,1,0,1,0,1},
							{1,0,1,0,1,0,1,0}};
							
	for (i=0;i<8;i++)
		for (j=0;j<8;j++)
			d[i][j] = t[i][j];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

void affiche_damier(MLV_Image *pion1, MLV_Image *pion2, MLV_Image *pion3, MLV_Image *pion4, damier d) // l'affichage du damier
{
	int i, j;
	for (i=0;i<8;i++)
	{
		for (j=0;j<8;j++)
		{
			if (d[i][j] == 1)
				MLV_draw_image(pion1, j*100, i*100);
			else if (d[i][j] == 2)
				MLV_draw_image(pion2, j*100, i*100);
			else if (d[i][j] == 3)
				MLV_draw_image(pion3, j*100, i*100);
			else if (d[i][j] == 4)
				MLV_draw_image(pion4, j*100, i*100);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

void affiche_pions(int t[]) // l'affichage des pions qui peuvent bouger
{
	int i = 1;
	while (i <= t[0]*2+1)
	{
		MLV_draw_rectangle(t[i+1]*100, t[i]*100, 100, 100, MLV_COLOR_BLUE);
		i += 2;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

void affiche_poss(int *m, int *p) // l'affichage des mouvements et les prises possibles d'un pion
{
	int i = 3;
	while (i <= m[0]*2+3)
	{
		MLV_draw_rectangle(m[i+1]*100, m[i]*100, 100, 100, MLV_COLOR_GREEN); // vert pour les mouvements
		i += 2;
	}
	i = 3;
	while (i <= p[0]*2+3)
	{
		MLV_draw_rectangle(p[i+1]*100, p[i]*100, 100, 100, MLV_COLOR_RED); // rouge pour les prises
		i += 2;
	}
}

#endif
