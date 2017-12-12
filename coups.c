

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

void jouer_tour(damier d, joueur *jr, MLV_Image *p1, MLV_Image *p2, MLV_Image *p3, MLV_Image *p4, MLV_Image *fond) // cette fonction attend le joueurs qu'il appuye sur un pion
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
		actualiser(d, p1, p2, p3, p4 ,fond);	
		analyser_damier(d, t, *jr);
		affiche_pions(t);
		MLV_actualise_window();
		
		MLV_wait_mouse(&x, &y);
		
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
			actualiser(d, p1, p2, p3, p4 ,fond);
			affiche_poss(mouvements, prises);
			MLV_actualise_window();
		
			while (joue2 == 0)
			{
				MLV_wait_mouse(&cp.x, &cp.y);
				
				cp.x /= 100;
				cp.y /= 100;
				
				if (dans(mouvements, cp.x, cp.y, 3) == 1)
				{
					deplacer(pion, y, x, cp.y, cp.x, d, p1, p2, p3, p4, fond);
					joue2 = 1;
					joue1 = 1;
				}
				
				else if (dans(prises, cp.x, cp.y, 3) == 1 )
				{
					deplacer(pion, y, x, cp.y, cp.x, d, p1, p2, p3, p4, fond);
					cherche_poss(mouvements, prises, d, *jr, cp.y, cp.x);
					
					while (prises[0] != 0)
					{
						joue3 = 0;
						affiche_poss(v, prises);
						MLV_actualise_window();
						while (joue3 == 0)
						{
							MLV_wait_mouse(&x, &y);
				
							x /= 100;
							y /= 100;
				
							if (dans(prises, x, y, 3) == 1 )
							{
								deplacer(pion, cp.y, cp.x, y, x, d, p1, p2, p3, p4, fond);
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

#endif
