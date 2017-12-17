

#ifndef COUPSC
#define COUPSC

#include "coups.h"

int dans(int *t, int x, int y, int n) // elle teste si les dimentions du pions existent dans le tableau t. n : nombre de décalage du tableau
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

int boutons(int x, int y) // teste si le joueur appuye sur un bouton
{
	if (x >= 920 && x <= 1121 && y >= 600 && y <= 650)
		return 1;
	else if (x >= 920 && x <= 1121 && y >= 700 && y <= 750)
		return 2;
	else
		return 3;
	return 0;
}

void jouer_tour(damier d, joueur *jr, MLV_Image *p1, MLV_Image *p2, MLV_Image *p3, MLV_Image *p4, MLV_Image *fond, MLV_Font *police, MLV_Image *retour, MLV_Image *sauver, int *bouton) // jouer le tour d'un joueur
{
	MLV_Image *pion;
	coup cp;
	int x, y;
	int joue1 = 0;
	int joue2 = 0;
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
		
		if (dans(t, x, y, 1) == 1) // si (x - y) est dans t
		{
			if (d[y][x] == 1) // on choisi l'image du pion
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
		
			while (joue1 == 0) // tant que le joueurs n'a fait aucun mouvement
			{
				MLV_wait_mouse(&cp.x, &cp.y);
				
				*bouton = boutons(x, y);
				if(*bouton == 2 || *bouton == 1) // si le jours appuye sur une touche on sort de la fonction
					return;
				
				cp.x /= 100;
				cp.y /= 100;
				
				if (dans(mouvements, cp.x, cp.y, 3) == 1) // si (x - y) est dans mouvements
				{
					deplacer(pion, y, x, cp.y, cp.x, d, p1, p2, p3, p4, fond, police, retour, sauver);
						
					joue1 = 1;
				}
				
				else if (dans(prises, cp.x, cp.y, 3) == 1 ) // si (x - y) est dans prises
				{
					deplacer(pion, y, x, cp.y, cp.x, d, p1, p2, p3, p4, fond, police, retour, sauver);
					
					if (d[cp.y][cp.x] == 3) // si le pion de converti en reinne, on change l'image du pion
						pion = p3;
					else if (d[cp.y][cp.x] == 4)
						pion = p4;
						
					actualiser(d, p1, p2, p3, p4 ,fond, police, retour, sauver);
					
					cherche_poss(mouvements, prises, d, *jr, cp.y, cp.x);
					
					while (prises[0] != 0) // tant qu'il y a des prises possibles on continue
					{
						joue2 = 0;
						affiche_poss(v, prises);
						MLV_actualise_window();
						while (joue2 == 0) // tant que le joueurs n'a pas continuer son coup
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
								
								if (d[y][x] == 3)
									pion = p3;
								else if (d[y][x] == 4)
									pion = p4;
									
								joue2 = 1;
							}
						}
						cherche_poss(mouvements, prises, d, *jr, y, x); // on cherche si il y a encore des prises
						cp.y = y;
						cp.x = x;
					}
					joue1 = 1;
				}
				else
					break;
			}
		}
	}
	
	if (*jr == J1) // on change le joueuer et on incrémente le nombre des coups joués
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

void jouer_cpu(damier d, joueur *jr, MLV_Image *p1, MLV_Image *p2, MLV_Image *p3, MLV_Image *p4, MLV_Image *fond, MLV_Font *police, MLV_Image *retour, MLV_Image *sauver) // jouer le tour de l'ordinateur
{
	int x, y, n, m;
	int i;
	int t[50];
	int prises[50];
	int mouvements[50];
	MLV_Image *pion;
	
	t[0] = 0;
	
	analyser_damier(d, t, *jr); // on analyse les le damier
	
	srand(time(NULL));
	
	if (t[0] == 1) // si il y a qu'une possibilité
	{
		x = t[1];
		y = t[2];
	}
	else // sinon on prend une possibilité aléatroire entre 1 et t[0] (nombre des possibilités)
	{
		i = rand() % (t[0] - 1) + 1;
		
		if (i == t[0])
			i--;
			
		x = t[i*2-1];
		y = t[i*2];
	}
	
	if (d[x][y] == 2) // on choisi l'image du pion
		pion = p2;
	else
		pion = p4;
	
	cherche_poss(mouvements, prises, d, *jr, x, y); // on cherche les coups possibles du pion
	
	if (prises[0] == 0) // si on a pas des prises on prend un mouvement
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
	
	else if (mouvements[0] == 0) // si on a pas des mouvement on prend une prise
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
		
		if (d[x][y] == 4)
			pion = p4;
	
		cherche_poss(mouvements, prises, d, *jr, m, n);
	
		while (prises[0] != 0) // tant qu'il y a des prises on continue
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
			
			if (d[m][n] == 4)
				pion = p4;
				
			m = x;
			n = y;
			cherche_poss(mouvements, prises, d, *jr, m, n);
		}
	}
	d[8][4]++; // on incrémente le nombre des coups joués
}

#endif
