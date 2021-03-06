

#ifndef POSSIBILITESC
#define POSSIBILITESC

#include "possibilites.h"

// Gestion des mouvements poussibles d'un pion

void inserer(int *t, int m, int n, int l)
{
	t[0]++; // dames_libres[k][0] est le nombre des possiblités
	t[l] = m; // après chaque paire des cases designe les dimentions de chaque possibilité
	l++;
	t[l] = n;
}


/* ---- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ---- */
// .  . Touts les fonctions utilisés dans la fonction poss_j1 .  .
/* ---- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ---- */

// les fonctions suivantes traitent touts les mouvements possibles d'un pion

void cas1_1(int *mouvements, int *prises, damier d, int i, int j)
{
	int l = 3, k = 3;
	if (d[i-1][j-1] == 0)
	{
		inserer(mouvements, i-1, j-1, l);
		l += 2;
	}
	else if (d[i-1][j-1] == 2 || d[i-1][j-1] == 4)
	{
		if (j > 1 && i > 1)
			if (d[i-2][j-2] == 0)
			{
				inserer(prises, i-2, j-2, k);
				k += 2;
			}
	}
		
	if (d[i-1][j+1] == 0)
	{
		inserer(mouvements, i-1, j+1, l);
		l += 2;
	}
	else if (d[i-1][j+1] == 2 || d[i-1][j+1] == 4)
	{
		if (j < 6 && i > 1)
			if (d[i-2][j+2] == 0)
			{
				inserer(prises, i-2, j+2, k);
				k += 2;
			}
	}

	if (d[i+1][j-1] == 2 || d[i+1][j-1] == 4)
		if (i < 6 && j > 1)
			if (d[i+2][j-2] == 0)
			{
				inserer(prises, i+2, j-2, k);
				k += 2;
			}

	if (d[i+1][j+1] == 2 || d[i+1][j+1] == 4)
		if (j < 6 && i < 6)
			if (d[i+2][j+2] == 0)
			{
				inserer(prises, i+2, j+2, k);
				k += 2;
			}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void cas1_2(int *mouvements, int *prises, damier d, int i, int j)
{
	int l = 3, k = 3;
	if (d[i-1][j+1] == 0)
	{
		inserer(mouvements, i-1, j+1, l);
		l += 2;
	}
	else if (d[i-1][j+1] == 2 || d[i-1][j+1] == 4)
	{
		if (j < 6 && i > 1)
			if (d[i-2][j+2] == 0)
			{
				inserer(prises, i-2, j+2, k);
				k += 2;
			}
	}
			
	if (d[i+1][j+1] == 2 || d[i+1][j+1] == 4)
		if (j < 6 && i < 6)
			if (d[i+2][j+2] == 0)
			{
				inserer(prises, i+2, j+2, k);
				k += 2;
			}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void cas1_3(int *mouvements, int *prises, damier d, int i, int j)
{
	int l = 3, k = 3;
	if (d[i-1][j-1] == 0)
	{
		inserer(mouvements, i-1, j-1, l);
		l += 2;
	}
	else if (d[i-1][j-1] == 2 || d[i-1][j-1] == 4)
	{
		if (j > 1 && i > 1)
			if (d[i-2][j-2] == 0)
			{
				inserer(prises, i-2, j-2, k);
				k += 2;
			}
	}
			
	if (d[i+1][j-1] == 2 || d[i+1][j-1] == 4)
		if (i < 6 && j > 1)
			if (d[i+2][j-2] == 0)
			{
				inserer(prises, i+2, j-2, k);
				k += 2;
			}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void cas1_4(int *mouvements, int *prises, damier d, int i, int j)
{
	int l = 3, k = 3;
	if (d[i-1][j+1] == 0)
	{
		inserer(mouvements, i-1, j+1, l);
		l += 2;
	}
	else if (d[i-1][j+1] == 2 || d[i-1][j+1] == 4)
	{
		if (d[i-2][j+2] == 0)
		{
			inserer(prises, i-2, j+2, k);
			k += 2;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void cas3(int *mouvements, int *prises, damier d, int i, int j)
{
	int x = i, y = j;
	int l = 3, k = 3, arrete = 0, active = 0; // arrete : pour arreter le parcours de damier, active : pour activer le mode de pris
	
	while (x > 0 && y > 0 && arrete == 0)
	{
		if (d[x-1][y-1] == 0)
		{
			if (active == 0)
			{
				inserer(mouvements, x-1, y-1, l);
				l += 2;
			}
			else if (active == 1)
			{
				inserer(prises, x-1, y-1, k);
				k += 2;
			}
		}
		else if (d[x-1][y-1] == 1 || d[x-1][y-1] == 3)
		{
			arrete = 1;
			printf("Un pion ennemi");
		}
		else if (d[x-1][y-1] == 2 || d[x-1][y-1] == 4)
		{
			if (x > 1 && y > 1)
			{
				if (d[x-2][y-2] == 0)
				{
					inserer(prises, x-2, y-2, k);
					k += 2;
					active = 1;
					x--;
					y--;
				}
				else
				{
					arrete = 1;
					printf("Un pion ami");
				}
			}
		}
			
		x--;
		y--;
	}
	
	x = i;
	y = j;
	arrete = 0;
	active = 0;
	
	while (x > 0 && y < 7 && arrete == 0)
	{
		if (d[x-1][y+1] == 0)
		{
			if (active == 0)
			{
				inserer(mouvements, x-1, y+1, l);
				l += 2;
			}
			else if (active == 1)
			{
				inserer(prises, x-1, y+1, k);
				k += 2;
			}
		}
		else if (d[x-1][y+1] == 1 || d[x-1][y+1] == 3)
			arrete = 1;
		else if (d[x-1][y+1] == 2 || d[x-1][y+1] == 4)
		{
			if (x > 1 && y < 6)
			{
				if (d[x-2][y+2] == 0)
				{
					inserer(prises, x-2, y+2, k);
					k += 2;
					active = 1;
					x--;
					y++;
				}
				else
					arrete = 1;
			}
		}
		x--;
		y++;
	}
	
	x = i;
	y = j;
	arrete = 0;
	active = 0;
	
	while (x < 7 && y > 0 && arrete == 0)
	{
		if (d[x+1][y-1] == 0)
		{
			if (active == 0)
			{
				inserer(mouvements, x+1, y-1, l);
				l += 2;
			}
			else if (active == 1)
			{
				inserer(prises, x+1, y-1, k);
				k += 2;
			}
		}
		else if (d[x+1][y-1] == 1 || d[x+1][y-1] == 3)
			arrete = 1;
		else if (d[x+1][y-1] == 2 || d[x+1][y-1] == 4)
		{
			if (x < 6 && y > 1)
			{
				if (d[x+2][y-2] == 0)
				{
					inserer(prises, x+2, y-2, k);
					k += 2;
					active = 1;
					x++;
					y--;
				}
				else
					arrete = 1;
			}
		}
		x++;
		y--;
	}
	
	x = i;
	y = j;
	arrete = 0;
	active = 0;
	
	while (x < 7 && y < 7 && arrete == 0)
	{
		if (d[x+1][y+1] == 0)
		{
			if (active == 0)
			{
				inserer(mouvements, x+1, y+1, l);
				l += 2;
			}
			else if (active == 1)
			{
				inserer(prises, x+1, y+1, k);
				k += 2;
			}
		}
		else if (d[x+1][y+1] == 1 || d[x+1][y+1] == 3)
			arrete = 1;
		else if (d[x+1][y+1] == 2 || d[x+1][y+1] == 4)
		{
			if (x < 6 && y < 6)
			{
				if (d[x+2][y+2] == 0)
				{
					inserer(prises, x+2, y+2, k);
					k += 2;
					active = 1;
					x++;
					y++;
				}
				else
					arrete = 1;
			}
		}
		x++;
		y++;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int poss_j1(int *mouvements, int *prises, damier d, int i, int j)
{
	if (d[i][j] == 1)
	{
		if (j != 0 && j != 7 && i != 0) // 1er cas
		{
			cas1_1(mouvements, prises, d, i, j);
		}
		
		else if (j == 0 && i != 0 && i != 7) // 2eme cas
		{
			cas1_2(mouvements, prises, d, i, j);
		}
		
		else if (j == 7 && i != 0 && i != 7) // 3eme cas
		{
			cas1_3(mouvements, prises, d, i, j);
		}
		
		else if (j == 0 && i == 7) // 4eme cas
		{
			cas1_4(mouvements, prises, d, i, j);
		}
	}
	if (d[i][j] == 3)
	{
		cas3(mouvements, prises, d, i, j);
	}
	if (mouvements[0] != 0 || prises[0] != 0)
		return 1;
	else
		return 0;
}


/* ---- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ---- */
// .  . Touts les fonctions utilisés dans la fonction poss_j2 .  .
/* ---- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ---- */


void cas2_1(int *mouvements, int *prises, damier d, int i, int j)
{
	int l = 3, k = 3;
	if (d[i+1][j+1] == 0)
	{
		inserer(mouvements, i+1, j+1, l);
		l += 2;
	}
	else if (d[i+1][j+1] == 1 || d[i+1][j+1] == 3)
	{
		if (j < 6 && i < 6)
			if (d[i+2][j+2] == 0)
			{
				inserer(prises, i+2, j+2, k);
				k += 2;
			}
	}
		
	if (d[i+1][j-1] == 0)
	{
		inserer(mouvements, i+1, j-1, l);
		l += 2;
	}
	else if (d[i+1][j-1] == 1 || d[i+1][j-1] == 3)
	{
		if (j > 1 && i < 6)
			if (d[i+2][j-2] == 0)
			{
				inserer(prises, i+2, j-2, k);
				k += 2;
			}
	}

	if (d[i-1][j+1] == 1 || d[i-1][j+1] == 3)
		if (i > 1 && j < 6)
			if (d[i-2][j+2] == 0)
			{
				inserer(prises, i-2, j+2, k);
				k += 2;
			}

	if (d[i-1][j-1] == 1 || d[i-1][j-1] == 3)
		if (j > 1 && i > 1)
			if (d[i-2][j-2] == 0)
			{
				inserer(prises, i-2, j-2, k);
				k += 2;
			}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void cas2_2(int *mouvements, int *prises, damier d, int i, int j)
{
	int l = 3, k = 3;
	if (d[i-1][j+1] == 1 || d[i-1][j+1] == 3)
		if (i > 1 && j < 6)
			if (d[i-2][j+2] == 0)
			{
				inserer(prises, i-2, j+2, k);
				k += 2;
			}
			
	if (d[i+1][j+1] == 0)
	{
		inserer(mouvements, i+1, j+1, l);
		l += 2;
	}
	
	else if (d[i+1][j+1] == 1 || d[i+1][j+1] == 3)
	{
		if (j < 6 && i < 6)
			if (d[i+2][j+2] == 0)
			{
				inserer(prises, i+2, j+2, k);
				k += 2;
			}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void cas2_3(int *mouvements, int *prises, damier d, int i, int j)
{
	int l = 3, k = 3;
	if (d[i-1][j-1] == 1 || d[i-1][j-1] == 3)
		if (j > 1 && i > 1)
			if (d[i-2][j-2] == 0)
			{
				inserer(prises, i-2, j-2, k);
				k += 2;
			}
			
	if (d[i+1][j-1] == 0)
	{
		inserer(mouvements, i+1, j-1, l);
		l += 2;
	}
	else if (d[i+1][j-1] == 1 || d[i+1][j-1] == 3)
	{
		if (j > 1 && i < 6)
			if (d[i+2][j-2] == 0)
			{
				inserer(prises, i+2, j-2, k);
				k += 2;
			}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void cas2_4(int *mouvements, int *prises, damier d, int i, int j)
{
	int l = 3, k = 3;
	if (d[i+1][j-1] == 0)
	{
		inserer(mouvements, i+1, j-1, l);
		l += 2;
	}
	else if (d[i+1][j-1] == 1 || d[i+1][j-1] == 3)
	{
		if (d[i+2][j-2] == 0)
		{
			inserer(prises, i+2, j-2, k);
			k += 2;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void cas4(int *mouvements, int *prises, damier d, int i, int j)
{
	int x = i, y = j;
	int l = 3, k = 3, arrete = 0, active = 0; // arrete : pour arreter le parcours de damier, active : pour annoncer que tout les possibilités qui viennent après sont des prises
	
	while (x > 0 && y > 0 && arrete == 0)
	{
		if (d[x-1][y-1] == 0)
		{
			if (active == 0)
			{
				inserer(mouvements, x-1, y-1, l);
				l += 2;
			}
			else if (active == 1)
			{
				inserer(prises, x-1, y-1, k);
				k += 2;
			}
		}
		else if (d[x-1][y-1] == 2 || d[x-1][y-1] == 4)
		{
			arrete = 1;
		}
		else if (d[x-1][y-1] == 1 || d[x-1][y-1] == 3)
		{
			if (x > 1 && y > 1)
			{
				if (d[x-2][y-2] == 0)
				{
					inserer(prises, x-2, y-2, k);
					k += 2;
					active = 1;
					x--;
					y--;
				}
				else
				{
					arrete = 1;
				}
			}
		}
			
		x--;
		y--;
	}
	
	x = i;
	y = j;
	arrete = 0;
	active = 0;
	
	while (x > 0 && y < 7 && arrete == 0)
	{
		if (d[x-1][y+1] == 0)
		{
			if (active == 0)
			{
				inserer(mouvements, x-1, y+1, l);
				l += 2;
			}
			else if (active == 1)
			{
				inserer(prises, x-1, y+1, k);
				k += 2;
			}
		}
		else if (d[x-1][y+1] == 2 || d[x-1][y+1] == 4)
			arrete = 1;
		else if (d[x-1][y+1] == 1 || d[x-1][y+1] == 3)
		{
			if (x > 1 && y < 6)
			{
				if (d[x-2][y+2] == 0)
				{
					inserer(prises, x-2, y+2, k);
					k += 2;
					active = 1;
					x--;
					y++;
				}
				else
					arrete = 1;
			}
		}
		x--;
		y++;
	}
	
	x = i;
	y = j;
	arrete = 0;
	active = 0;
	
	while (x < 7 && y > 0 && arrete == 0)
	{
		if (d[x+1][y-1] == 0)
		{
			if (active == 0)
			{
				inserer(mouvements, x+1, y-1, l);
				l += 2;
			}
			else if (active == 1)
			{
				inserer(prises, x+1, y-1, k);
				k += 2;
			}
		}
		else if (d[x+1][y-1] == 2 || d[x+1][y-1] == 4)
			arrete = 1;
		else if (d[x+1][y-1] == 1 || d[x+1][y-1] == 3)
		{
			if (x < 6 && y > 1)
			{
				if (d[x+2][y-2] == 0)
				{
					inserer(prises, x+2, y-2, k);
					k += 2;
					active = 1;
					x++;
					y--;
				}
				else
					arrete = 1;
			}
		}
		x++;
		y--;
	}
	
	x = i;
	y = j;
	arrete = 0;
	active = 0;
	
	while (x < 7 && y < 7 && arrete == 0)
	{
		if (d[x+1][y+1] == 0)
		{
			if (active == 0)
			{
				inserer(mouvements, x+1, y+1, l);
				l += 2;
			}
			else if (active == 1)
			{
				inserer(prises, x+1, y+1, k);
				k += 2;
			}
		}
		else if (d[x+1][y+1] == 2 || d[x+1][y+1] == 4)
			arrete = 1;
		else if (d[x+1][y+1] == 1 || d[x+1][y+1] == 3)
		{
			if (x < 6 && y < 6)
			{
				if (d[x+2][y+2] == 0)
				{
					inserer(prises, x+2, y+2, k);
					k += 2;
					active = 1;
					x++;
					y++;
				}
				else
					arrete = 1;
			}
		}
		x++;
		y++;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int poss_j2(int *mouvements, int *prises, damier d, int i, int j)

{
	if (d[i][j] == 2)
	{
		if (j != 0 && j != 7 && i != 7) // 1er cas: le pion ne se trouve pas dans les boards du damier
		{
			cas2_1(mouvements, prises, d, i, j);
		}
		
		else if (j == 0 && i != 0 && i != 7) // 2eme cas: le pion se trouve toute à gauche du damier
		{
			cas2_2(mouvements, prises, d, i, j);
		}
		
		else if (j == 7 && i != 0 && i != 7) // 3eme cas: le pion se trouve toute à droite du damier
		{
			cas2_3(mouvements, prises, d, i, j);
		}
		
		else if (j == 7 && i == 0) // 4eme cas: le pion se trouve toute en haut a droite
		{
			cas2_4(mouvements, prises, d, i, j);
		}
	}
	if (d[i][j] == 4)
	{
		cas4(mouvements, prises, d, i, j);
	}
	if (mouvements[0] != 0 || prises[0] != 0)
		return 1;
	else
		return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int cherche_poss(int *mouvements, int *prises, damier d, joueur jr, int i, int j) // remplir la liste des mouvements et des prises possibles d'un pion
{
	int n = 0, m = 0;
	
	mouvements[0] = 0; // première case pour le nobre des possibilités et les 2 autres pour les coordonnédu pions
	mouvements[1] = i;
	mouvements[2] = j;
	
	prises[0] = 0;
	prises[1] = i;
	prises[2] = j;
	
	if(jr == J1)
	{
		n = poss_j1(mouvements, prises, d, i, j);
	}
	else
	{
		m = poss_j2(mouvements, prises, d, i, j);
	}
	
	if (prises[0] != 0) // si on a des prises poussibles on ignore les mouvements
		mouvements[0] = 0;
	
	return n+m;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void analyser_damier(damier d, int *t, joueur jr) // renvoie touts les pions qui peuvent bouger
{
	int i, j, x = 1, y = 1;
	int prises[50];
	int mouvements[50];
	int t_p[50];
	t_p[0] = 0;
	
	t[0] = 0;
	
	for (i=0;i<8;i++) // pour chaque case on cherche si il y a un pion qui peut bouger
	{
		for (j=0;j<8;j++)
		{
			if (cherche_poss(mouvements, prises, d, jr, i, j) != 0)
			{
				if (prises[0] != 0) // si il n'a pas de prises possibles on l'ajoute direct dans la table qu'on va renvoyer
				{
					t_p[y] = i;
					y++;
					t_p[y] = j;
					y++;
					t_p[0]++;
				}
				
				else // si il esiste des prises possible on le stock dans un autre tableau
				{
					t[x] = i;
					x++;
					t[x] = j;
					x++;
					t[0]++;
				}
			}
		}
	}
	
	if (t_p[0] != 0) // si on des pion qui peuvent manger, on les prend et on ignore les autre
		for(i=0;i<t_p[0]*2+1;i++)
			t[i] = t_p[i];
}


#endif
