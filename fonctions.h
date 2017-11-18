#include "types.h"

/* Partie théorique */

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

/* Partie graphique */

void affiche_damier(MLV_Image *pion1, MLV_Image *pion2, MLV_Image *pion3, MLV_Image *pion4, damier d) // l'afficher le damier
{
	int i, j;
	for (i=0;i<8;i++)
	{
		for (j=0;j<8;j++)
		{
			if (d[i][j] == 1)
				MLV_draw_image(pion1, j*100+18, i*100+18);
			else if (d[i][j] == 2)
				MLV_draw_image(pion2, j*100+18, i*100+18);
			else if (d[i][j] == 3)
				MLV_draw_image(pion3, j*100+18, i*100+18);
			else if (d[i][j] == 4)
				MLV_draw_image(pion4, j*100+18, i*100+18);
		}
	}
}