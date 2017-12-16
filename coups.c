

#ifndef COUPSC
#define COUPSC

#include "coups.h"

int dans(int *t, int x, int y, int n)
{
	int i = n;
	while (i < t[0]*2+n)
	{
		if (x == t[i+1] && y == t[i])
			return 1;
		i += 2;
	}
	
	return 0;
}

int boutons(int x, int y)
{
	if (x >= 920 && x <= 1121 && y >= 600 && y <= 650)
		return 1;
	else if (x >= 920 && x <= 1121 && y >= 700 && y <= 750)
		return 2;
	else
		return 3;
	return 0;
}

void jouer_tour(damier d, joueur *jr, MLV_Image *p1, MLV_Image *p2, MLV_Image *p3, MLV_Image *p4, MLV_Image *fond, MLV_Font *police, MLV_Image *retour, MLV_Image *sauver, int *bouton) // cette fonction attend le joueurs qu'il appuye sur un pion
{
	MLV_Image *pion;
	coup cp;
	int x, y;
	int joue1 = 0;
	int joue2 = 0;
	int joue3 = 0;
	int t[20];
	int v[20] = {0,0,0,0};
	int prises[20];
	int mouvements[20];
	
	while (joue1 == 0)
	{
		MLV_clear_window(MLV_COLOR_BLACK);
		actualiser(d, p1, p2, p3, p4 ,fond, police, retour, sauver);
		analyser_damier(d, t, *jr);
		affiche_pions(t);
		MLV_actualise_window();
		
		MLV_wait_mouse(&x, &y);
		
		*bouton = boutons(x, y);
		if(*bouton == 2 || *bouton == 1)
			return;
		
		x /= 100;
		y /= 100;
		
		if (dans(t, x, y, 1) == 1)
		{
			if (d[y][x] == 1)
				pion = p1;
			else if (d[y][x] == 2)
				pion = p2;
			else if (d[y][x] == 3)
				pion = p3;
			else if (d[y][x] == 4)
				pion = p4;
			
			cherche_poss(mouvements, prises, d, *jr, y, x);
			MLV_clear_window(MLV_COLOR_BLACK);
			actualiser(d, p1, p2, p3, p4 ,fond, police, retour, sauver);
			affiche_poss(mouvements, prises);
			MLV_actualise_window();
		
			while (joue2 == 0)
			{
				MLV_wait_mouse(&cp.x, &cp.y);
				
				*bouton = boutons(x, y);
				if(*bouton == 2 || *bouton == 1)
					return;
				
				cp.x /= 100;
				cp.y /= 100;
				
				if (dans(mouvements, cp.x, cp.y, 3) == 1)
				{
					deplacer(pion, y, x, cp.y, cp.x, d, p1, p2, p3, p4, fond, police, retour, sauver);
					joue2 = 1;
					joue1 = 1;
				}
				
				else if (dans(prises, cp.x, cp.y, 3) == 1 )
				{
					deplacer(pion, y, x, cp.y, cp.x, d, p1, p2, p3, p4, fond, police, retour, sauver);
					cherche_poss(mouvements, prises, d, *jr, cp.y, cp.x);
					
					while (prises[0] != 0)
					{
						joue3 = 0;
						affiche_poss(v, prises);
						MLV_actualise_window();
						while (joue3 == 0)
						{
							MLV_wait_mouse(&x, &y);
							
							*bouton = boutons(x, y);
							if(*bouton == 2 || *bouton == 1)
								return;
							
							x /= 100;
							y /= 100;
				
							if (dans(prises, x, y, 3) == 1 )
							{
								deplacer(pion, cp.y, cp.x, y, x, d, p1, p2, p3, p4, fond, police, retour, sauver);
								joue3 = 1;
							}
						}
						cherche_poss(mouvements, prises, d, *jr, y, x);
						cp.y = y;
						cp.x = x;
					}
					joue2 = 1;
					joue1 = 1;
				}
				else
					break;
			}
		}
	}
	
	if (*jr == J1)
	{
		d[8][3]++;
		*jr = J2;
	}
	else
	{
		d[8][4]++;
		*jr = J1;
	}
}

void jouer_cpu(damier d, joueur *jr, MLV_Image *p1, MLV_Image *p2, MLV_Image *p3, MLV_Image *p4, MLV_Image *fond, MLV_Font *police, MLV_Image *retour, MLV_Image *sauver, int *bouton)
{
	int x, y, n, m;
	int i;
	int t[50];
	int prises[50];
	int mouvements[50];
	MLV_Image *pion;
	
	t[0] = 0;
	
	analyser_damier(d, t, *jr);
	
	srand(time(NULL));
	
	if (t[0] == 1)
	{
		x = t[1];
		y = t[2];
	}
	else
	{
		i = rand() % (t[0] - 1) + 1;
		
		if (i == t[0])
			i--;
			
		x = t[i*2-1];
		y = t[i*2];
	}
	
	if (d[x][y] == 2)
		pion = p2;
	else
		pion = p4;
	
	cherche_poss(mouvements, prises, d, *jr, x, y);
	
	if (prises[0] == 0)
	{
		if (mouvements[0] == 1)
		{
			m = mouvements[3];
			n = mouvements[4];
		}
		else
		{
			i = rand() % (mouvements[0] - 1) + 1;
			
			if (i == mouvements[0])
				i--;
			
			m = mouvements[i*2+1];
			n = mouvements[i*2+2];
		}
			
		deplacer(pion, x, y, m, n, d, p1, p2, p3, p4, fond, police, retour, sauver);
	}
	
	else if (mouvements[0] == 0)
	{
		if (prises[0] == 1)
		{
			m = prises[3];
			n = prises[4];
		}
		else
		{
			i = rand() % (prises[0] - 1) + 1;
			
			if (i == prises[0])
				i--;
			
			m = prises[i*2+1];
			n = prises[i*2+2];
		}
		
		deplacer(pion, x, y, m, n, d, p1, p2, p3, p4, fond, police, retour, sauver);
	
		cherche_poss(mouvements, prises, d, *jr, m, n);
	
		while (prises[0] != 0)
		{
			if (prises[0] == 1)
			{
				x = prises[3];
				y = prises[4];
			}
			else
			{
				i = rand() % (prises[0] - 1) + 1;
			
				if (i == prises[0])
					i--;
			
				x = prises[i*2+1];
				y = prises[i*2+2];
			}
				
			deplacer(pion, m, n, x, y, d, p1, p2, p3, p4, fond, police, retour, sauver);
			m = x;
			n = y;
			cherche_poss(mouvements, prises, d, *jr, m, n);
		}
	}
	d[8][4]++;
}

#endif
