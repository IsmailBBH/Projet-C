#include "affichage.h"

// Gestion des mouvements poussibles d'un pion

void inserer(int dames_libres[20], int m, int n, int l)
{
	dames_libres[0]++; // dames_libres[k][0] est le nombre des possiblités
	dames_libres[l] = m; // après chaque paire des cases designe les dimentions de chaque possibilité
	l++;
	dames_libres[l] = n;
}

// Touts les fonctions utilisés dans la fonction poss_j1

void cas1_1(int dames_libres[20], damier d, int i, int j)
{
	int l = 1;
	if (d[i-1][j-1] == 0)
	{
		inserer(dames_libres, i-1, j-1, l);
		l += 2;
	}
	else if (d[i-1][j-1] == 2 || d[i-1][j-1] == 4)
	{
		if (j > 1 && i > 1)
			if (d[i-2][j-2] == 0)
			{
				inserer(dames_libres, i-2, j-2, l);
				l += 2;
			}
	}
		
	if (d[i-1][j+1] == 0)
	{
		inserer(dames_libres, i-1, j+1, l);
		l += 2;
	}
	else if (d[i-1][j+1] == 2 || d[i-1][j+1] == 4)
	{
		if (j < 6 && i > 1)
			if (d[i-2][j+2] == 0)
			{
				inserer(dames_libres, i-2, j+2, l);
				l += 2;
			}
	}

	if (d[i+1][j-1] == 2 || d[i+1][j-1] == 4)
		if (i > 1 && j < 6)
			if (d[i+2][j-2] == 0)
			{
				inserer(dames_libres, i+2, j-2, l);
				l += 2;
			}

	if (d[i+1][j+1] == 2 || d[i+1][j+1] == 4)
		if (j < 6 && i < 6)
			if (d[i+2][j+2] == 0)
			{
				inserer(dames_libres, i+2, j+2, l);
				l += 2;
			}
}

void cas1_2(int dames_libres[20], damier d, int i, int j)
{
	int l = 1;
	if (d[i-1][j+1] == 0)
	{
		inserer(dames_libres, i-1, j+1, l);
		l += 2;
	}
	else if (d[i-1][j+1] == 2 || d[i-1][j+1] == 4)
	{
		if (j < 6 && i > 1)
			if (d[i-2][j+2] == 0)
			{
				inserer(dames_libres, i-2, j+2, l);
				l += 2;
			}
	}
			
	if (d[i+1][j+1] == 2 || d[i+1][j+1] == 4)
		if (j < 6 && i < 6)
			if (d[i+2][j+2] == 0)
			{
				inserer(dames_libres, i+2, j+2, l);
				l += 2;
			}
}

void cas1_3(int dames_libres[20], damier d, int i, int j)
{
	int l = 1;
	if (d[i-1][j-1] == 0)
	{
		inserer(dames_libres, i-1, j-1, l);
		l += 2;
	}
	else if (d[i-1][j-1] == 2 || d[i-1][j-1] == 4)
	{
		if (j > 1 && i > 1)
			if (d[i-2][j-2] == 0)
			{
				inserer(dames_libres, i-2, j-2, l);
				l += 2;
			}
	}
			
	if (d[i+1][j-1] == 2 || d[i+1][j-1] == 4)
		if (i > 1 && j < 6)
			if (d[i+2][j-2] == 0)
			{
				inserer(dames_libres, i+2, j-2, l);
				l += 2;
			}
}

void cas1_4(int dames_libres[20], damier d, int i, int j)
{
	int l = 1;
	if (d[i-1][j+1] == 0)
	{
		inserer(dames_libres, i-1, j+1, l);
		l += 2;
	}
	else if (d[i-1][j+1] == 2 || d[i-1][j+1] == 4)
	{
		if (d[i-2][j+2] == 0)
		{
			inserer(dames_libres, i-2, j+2, l);
			l += 2;
		}
	}
}

void cas3(int dames_libres[20], damier d, int i, int j)
{
	int x = i, y = j;
	int l = 1, n = 0; // n nombre des pions ennemis
	while (x > 0 && y > 0 && n < 2)
	{
		if (d[x-1][y-1] == 0)
		{
			inserer(dames_libres, x-1, y-1, l);
			l += 2;
		}
		else if (d[x-1][y-1] == 1 || d[x-1][y-1] == 3)
			n = 2;
		else
			n++;
		x--;
		y--;
	}
	
	x = i;
	y = j;
	n = 0;
	
	while (x > 0 && y < 7 && n < 2)
	{
		if (d[x-1][y+1] == 0)
		{
			inserer(dames_libres, x-1, y+1, l);
			l += 2;
		}
		else if (d[x-1][y+1] == 1 || d[x-1][y+1] == 3)
			n = 2;
		else
			n++;
		x--;
		y++;
	}
	
	x = i;
	y = j;
	n = 0;
	
	while (x < 7 && y > 0 && n < 2)
	{
		if (d[x+1][y-1] == 0)
		{
			inserer(dames_libres, x+1, y-1, l);
			l += 2;
		}
		else if (d[x+1][y-1] == 1 || d[x+1][y-1] == 3)
			n = 2;
		else
			n++;
		x++;
		y--;
	}
	
	x = i;
	y = j;
	n = 0;
	
	while (x < 7 && y < 7 && n < 2)
	{
		if (d[x+1][y+1] == 0)
		{
			inserer(dames_libres, x+1, y+1, l);
			l += 2;
		}
		else if (d[x+1][y+1] == 1 || d[x+1][y+1] == 3)
			n = 2;
		else
			n++;
		x++;
		y++;
	}
}

int poss_j1(int dames_libres[20], damier d, int i, int j)
{
	if (d[i][j] == 1)
	{
		if (j != 0 && j != 7&& i != 0 && i != 7) // 1er cas
		{
			cas1_1(dames_libres, d, i, j);
		}
		
		else if (j == 0 && i != 0 && i != 7) // 2eme cas
		{
			cas1_2(dames_libres, d, i, j);
		}
		
		else if (j == 7 && i != 0 && i != 7) // 3eme cas
		{
			cas1_3(dames_libres, d, i, j);
		}
		
		else if (j == 0 && i == 7) // 4eme cas
		{
			cas1_4(dames_libres, d, i, j);
		}
	}
	if (d[i][j] == 3)
	{
		cas3(dames_libres, d, i, j);
	}
	if (dames_libres[0] != 0)
		return 1;
	else
		return 0;
}

// Touts les fonctions utilisés dans la fonction poss_j2

void cas2_1(int dames_libres[20], damier d, int i, int j)
{
	int l = 1;
	if (d[i+1][j+1] == 0)
	{
		inserer(dames_libres, i+1, j+1, l);
		l += 2;
	}
	else if (d[i+1][j+1] == 1 || d[i+1][j+1] == 3)
	{
		if (j < 6 && i < 6)
			if (d[i+2][j+2] == 0)
			{
				inserer(dames_libres, i+2, j+2, l);
				l += 2;
			}
	}
		
	if (d[i+1][j-1] == 0)
	{
		inserer(dames_libres, i+1, j-1, l);
		l += 2;
	}
	else if (d[i+1][j-1] == 1 || d[i+1][j-1] == 3)
	{
		if (j < 6 && i > 1)
			if (d[i+2][j-2] == 0)
			{
				inserer(dames_libres, i+2, j-2, l);
				l += 2;
			}
	}

	if (d[i-1][j+1] == 1 || d[i-1][j+1] == 3)
		if (i > 1 && j < 6)
			if (d[i-2][j+2] == 0)
			{
				inserer(dames_libres, i-2, j+2, l);
				l += 2;
			}

	if (d[i-1][j-1] == 1 || d[i-1][j-1] == 3)
		if (j > 1 && i > 1)
			if (d[i-2][j-2] == 0)
			{
				inserer(dames_libres, i-2, j-2, l);
				l += 2;
			}
}

void cas2_2(int dames_libres[20], damier d, int i, int j)
{
	int l = 1;
	if (d[i-1][j+1] == 1 || d[i-1][j+1] == 3)
		if (i > 1 && j < 6)
			if (d[i-2][j+2] == 0)
			{
				inserer(dames_libres, i-2, j+2, l);
				l += 2;
			}
			
	if (d[i+1][j+1] == 0)
	{
		inserer(dames_libres, i+1, j+1, l);
		l += 2;
	}
	else if (d[i+1][j+1] == 1 || d[i+1][j+1] == 3)
	{
		if (j < 6 && i < 6)
			if (d[i+2][j+2] == 0)
			{
				inserer(dames_libres, i+2, j+2, l);
				l += 2;
			}
	}
}

void cas2_3(int dames_libres[20], damier d, int i, int j)
{
	int l = 1;
	if (d[i-1][j-1] == 1 || d[i-1][j-1] == 3)
		if (j > 1 && i > 1)
			if (d[i-2][j-2] == 0)
			{
				inserer(dames_libres, i-2, j-2, l);
				l += 2;
			}
			
	if (d[i+1][j-1] == 0)
	{
		inserer(dames_libres, i+1, j-1, l);
		l += 2;
	}
	else if (d[i+1][j-1] == 1 || d[i+1][j-1] == 3)
	{
		if (j < 6 && i > 1)
			if (d[i+2][j-2] == 0)
			{
				inserer(dames_libres, i+2, j-2, l);
				l += 2;
			}
	}
}

void cas2_4(int dames_libres[20], damier d, int i, int j)
{
	int l = 1;
	if (d[i+1][j-1] == 0)
	{
		inserer(dames_libres, i+1, j-1, l);
		l += 2;
	}
	else if (d[i+1][j-1] == 1 || d[i+1][j-1] == 3)
	{
		if (d[i+2][j-2] == 0)
		{
			inserer(dames_libres, i+2, j-2, l);
			l += 2;
		}
	}
}

void cas4(int dames_libres[20], damier d, int i, int j)
{
	int x = i, y = j;
	int l = 1, n = 0; // n nombre des pions ennemis
	while (x > 0 && y > 0 && n < 2)
	{
		if (d[x-1][y-1] == 0)
		{
			inserer(dames_libres, x-1, y-1, l);
			l += 2;
		}
		else if (d[x-1][y-1] == 2 || d[x-1][y-1] == 4)
			n = 2;
		else
			n++;
		x--;
		y--;
	}
	
	x = i;
	y = j;
	n = 0;
	
	while (x > 0 && y < 7 && n < 2)
	{
		if (d[x-1][y+1] == 0)
		{
			inserer(dames_libres, x-1, y+1, l);
			l += 2;
		}
		else if (d[x-1][y+1] == 2 || d[x-1][y+1] == 4)
			n = 2;
		else
			n++;
		x--;
		y++;
	}
	
	x = i;
	y = j;
	n = 0;
	
	while (x < 7 && y > 0 && n < 2)
	{
		if (d[x+1][y-1] == 0)
		{
			inserer(dames_libres, x+1, y-1, l);
			l += 2;
		}
		else if (d[x+1][y-1] == 2 || d[x+1][y-1] == 4)
			n = 2;
		else
			n++;
		x++;
		y--;
	}
	
	x = i;
	y = j;
	n = 0;
	
	while (x < 7 && y < 7 && n < 2)
	{
		if (d[x+1][y+1] == 0)
		{
			inserer(dames_libres, x+1, y+1, l);
			l += 2;
		}
		else if (d[x+1][y+1] == 2 || d[x+1][y+1] == 4)
			n = 2;
		else
			n++;
		x++;
		y++;
	}
}

int poss_j2(int dames_libres[20], damier d, int i, int j)

{
	if (d[i][j] == 2)
	{
		if (j != 0 && j != 7&& i != 0 && i != 7) // 1er cas
		{
			cas2_1(dames_libres, d, i, j);
		}
		
		else if (j == 0 && i != 0 && i != 7) // 2eme cas
		{
			cas2_2(dames_libres, d, i, j);
		}
		
		else if (j == 7 && i != 0 && i != 7) // 3eme cas
		{
			cas2_3(dames_libres, d, i, j);
		}
		
		else if (j == 7 && i == 0) // 4eme cas
		{
			cas2_4(dames_libres, d, i, j);
		}
	}
	if (d[i][j] == 4)
	{
		cas4(dames_libres, d, i, j);
	}
	if (dames_libres[0] != 0)
		return 1;
	else
		return 0;
}

int cherche_poss(int dames_libres[20], damier d, joueur jr, int i, int j) // remplir la liste de toutes les mouvements possibles d'un pion
{
	int n;
	
	if(jr == J1)
	{
		n = poss_j1(dames_libres, d, i, j);
	}
	else
	{
		n = poss_j2(dames_libres, d, i, j);
	}
	
	return n;
}
