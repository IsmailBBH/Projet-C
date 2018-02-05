

#ifndef AFFICHAGEC
#define AFFICHAGEC

#include "affichage.h"

/* affichage.c : fonction qui gèrent l'affichage */

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
							{1,0,1,0,1,0,1,0},
							{0,12,12,0,0,0,0,0}}; // d[8][1]: nombre des pions du premier joueur
																		// d[8][2]: nombre des pions du premier joueur
							
	for (i=0;i<9;i++)
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
	while (i < t[0]*2+1)
	{
		MLV_draw_rectangle(t[i+1]*100, t[i]*100, 100, 100, MLV_COLOR_BLUE);
		i += 2;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

void affiche_poss(int *m, int *p) // l'affichage des mouvements et les prises possibles d'un pion
{
	int i = 3;
	while (i < m[0]*2+3)
	{
		MLV_draw_rectangle(m[i+1]*100, m[i]*100, 100, 100, MLV_COLOR_GREEN); // vert pour les mouvements
		i += 2;
	}
	i = 3;
	while (i < p[0]*2+3)
	{
		MLV_draw_rectangle(p[i+1]*100, p[i]*100, 100, 100, MLV_COLOR_RED); // rouge pour les prises
		i += 2;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

void menu(int *m) // l'affichage de menu
{
	int x, y;
	
	MLV_Image *fond_menu;
	MLV_Image *jouer1;
	MLV_Image *jouer2;
	MLV_Image *jouer3;
	MLV_Image *jouer4;
	MLV_Image *charger1;
	MLV_Image *charger2;
	MLV_Image *score1;
	MLV_Image *score2;
	MLV_Image *quitter1;
	MLV_Image *quitter2;
	
	MLV_Mouse_button bouton;
	MLV_Button_state etat;
	
	fond_menu = MLV_load_image("Menu/SCREEN.png");
	jouer1 = MLV_load_image("Menu/2_j.png");
	jouer2 = MLV_load_image("Menu/2_joueurs.png");
	
	jouer3 = MLV_load_image("Menu/JCPU.png");
	jouer4 = MLV_load_image("Menu/J_vs_CPU.png");
	charger1 = MLV_load_image("Menu/C.png");
	charger2 = MLV_load_image("Menu/Charger.png");
	score1 = MLV_load_image("Menu/S.png");
	score2 = MLV_load_image("Menu/Score.png");
	quitter1 = MLV_load_image("Menu/Q.png");
	quitter2 = MLV_load_image("Menu/Quitter.png");
	*m = -1;
	
	while(*m == -1) // tant que le joueur n'a pas appuyé sur un choix
	{
		
		MLV_draw_image(fond_menu, 0, 0);
		MLV_draw_image(jouer1, 350, 220);
		MLV_draw_image(jouer3, 730, 220);
		MLV_draw_image(charger1, 485, 450);
		MLV_draw_image(score1, 485, 550);
		MLV_draw_image(quitter1, 485, 650);
		MLV_draw_image(quitter1, 485, 650);
		MLV_actualise_window();
		MLV_get_mouse_position(&x, &y);
		
		while (x >= 350 && x <= 530 && y >= 220 && y <= 411) // 2 Joueurs
		{
			etat = MLV_RELEASED;
			MLV_get_mouse_position(&x, &y);
			MLV_clear_window(MLV_COLOR_BLACK);
			MLV_draw_image(fond_menu, 0, 0);
			MLV_draw_image(jouer2, 350, 220);
			MLV_draw_image(jouer3, 730, 220);
			MLV_draw_image(charger1, 485, 450);
			MLV_draw_image(score1, 485, 550);
			MLV_draw_image(quitter1, 485, 650);
			MLV_actualise_window();
			MLV_get_event(NULL, NULL, NULL, NULL, NULL, NULL, NULL, &bouton, &etat);
			while (bouton == MLV_BUTTON_LEFT && etat != MLV_RELEASED)
			{
				MLV_clear_window(MLV_COLOR_BLACK);
				MLV_draw_image(fond_menu, 0, 0);
				MLV_draw_image(jouer2, 355, 225);
				MLV_draw_image(jouer3, 730, 220);
				MLV_draw_image(charger1, 485, 450);
				MLV_draw_image(score1, 485, 550);
				MLV_draw_image(quitter1, 485, 650);
				MLV_actualise_window();
				MLV_get_event(NULL, NULL, NULL, NULL, NULL, NULL, NULL, &bouton, &etat);
				*m = 1;
				MLV_wait_milliseconds(70);
				return;
			}
		}
		
		while (x >= 730 && x <= 921 && y >= 220 && y <= 411) // J vs CPU
		{
			etat = MLV_RELEASED;
			MLV_get_mouse_position(&x, &y);
			MLV_clear_window(MLV_COLOR_BLACK);
			MLV_draw_image(fond_menu, 0, 0);
			MLV_draw_image(jouer1, 350, 220);
			MLV_draw_image(jouer4, 730, 220);
			MLV_draw_image(charger1, 485, 450);
			MLV_draw_image(score1, 485, 550);
			MLV_draw_image(quitter1, 485, 650);
			MLV_actualise_window();
			MLV_get_event(NULL, NULL, NULL, NULL, NULL, NULL, NULL, &bouton, &etat);
			while (bouton == MLV_BUTTON_LEFT && etat != MLV_RELEASED)
			{
				MLV_clear_window(MLV_COLOR_BLACK);
				MLV_draw_image(fond_menu, 0, 0);
				MLV_draw_image(jouer1, 350, 220);
				MLV_draw_image(jouer4, 735, 225);
				MLV_draw_image(charger1, 485, 450);
				MLV_draw_image(score1, 485, 550);
				MLV_draw_image(quitter1, 485, 650);
				MLV_actualise_window();
				MLV_get_event(NULL, NULL, NULL, NULL, NULL, NULL, NULL, &bouton, &etat);
				*m = 2;
				MLV_wait_milliseconds(70);
				return;
			}
		}
		
		while (x >= 485 && x <= 754 && y >= 450 && y <= 514) // Charger partie
		{
			etat = MLV_RELEASED;
			MLV_get_mouse_position(&x, &y);
			MLV_clear_window(MLV_COLOR_BLACK);
			MLV_draw_image(fond_menu, 0, 0);
			MLV_draw_image(jouer1, 350, 220);
			MLV_draw_image(jouer3, 730, 220);
			MLV_draw_image(charger2, 485, 450);
			MLV_draw_image(score1, 485, 550);
			MLV_draw_image(quitter1, 485, 650);
			MLV_actualise_window();
			MLV_get_event(NULL, NULL, NULL, NULL, NULL, NULL, NULL, &bouton, &etat);
			while (bouton == MLV_BUTTON_LEFT && etat != MLV_RELEASED)
			{
				MLV_clear_window(MLV_COLOR_BLACK);
				MLV_draw_image(fond_menu, 0, 0);
				MLV_draw_image(jouer1, 350, 220);
				MLV_draw_image(jouer3, 730, 220);
				MLV_draw_image(charger2, 490, 455);
				MLV_draw_image(score1, 485, 550);
				MLV_draw_image(quitter1, 485, 650);
				MLV_actualise_window();
				MLV_get_event(NULL, NULL, NULL, NULL, NULL, NULL, NULL, &bouton, &etat);
				*m = 3;
				MLV_wait_milliseconds(70);
				return;
			}
		}
		
		while (x >= 485 && x <= 754 && y >= 550 && y <= 614) // Meilleur score
		{
			etat = MLV_RELEASED;
			MLV_get_mouse_position(&x, &y);
			MLV_clear_window(MLV_COLOR_BLACK);
			MLV_draw_image(fond_menu, 0, 0);
			MLV_draw_image(jouer1, 350, 220);
			MLV_draw_image(jouer3, 730, 220);
			MLV_draw_image(charger1, 485, 450);
			MLV_draw_image(score2, 485, 550);
			MLV_draw_image(quitter1, 485, 650);
			MLV_actualise_window();
			MLV_get_event(NULL, NULL, NULL, NULL, NULL, NULL, NULL, &bouton, &etat);
			while (bouton == MLV_BUTTON_LEFT && etat != MLV_RELEASED)
			{
				MLV_clear_window(MLV_COLOR_BLACK);
				MLV_draw_image(fond_menu, 0, 0);
				MLV_draw_image(jouer1, 350, 220);
				MLV_draw_image(jouer3, 730, 220);
				MLV_draw_image(charger1, 485, 450);
				MLV_draw_image(score2, 490, 555);
				MLV_draw_image(quitter1, 485, 650);
				MLV_actualise_window();
				MLV_get_event(NULL, NULL, NULL, NULL, NULL, NULL, NULL, &bouton, &etat);
				*m = 4;
				MLV_wait_milliseconds(70);
				return;
			}
		}
		
		while (x >= 485 && x <= 754 && y >= 650 && y <= 714) // Quitter
		{
			etat = MLV_RELEASED;
			MLV_get_mouse_position(&x, &y);
			MLV_clear_window(MLV_COLOR_BLACK);
			MLV_draw_image(fond_menu, 0, 0);
			MLV_draw_image(jouer1, 350, 220);
			MLV_draw_image(jouer3, 730, 220);
			MLV_draw_image(charger1, 485, 450);
			MLV_draw_image(score1, 485, 550);
			MLV_draw_image(quitter2, 485, 650);
			MLV_actualise_window();
			MLV_get_event(NULL, NULL, NULL, NULL, NULL, NULL, NULL, &bouton, &etat);
			while (bouton == MLV_BUTTON_LEFT && etat != MLV_RELEASED)
			{
				MLV_clear_window(MLV_COLOR_BLACK);
				MLV_draw_image(fond_menu, 0, 0);
				MLV_draw_image(jouer1, 350, 220);
				MLV_draw_image(jouer3, 730, 220);
				MLV_draw_image(charger1, 485, 450);
				MLV_draw_image(score1, 485, 550);
				MLV_draw_image(quitter2, 490, 655);
				MLV_actualise_window();
				MLV_wait_milliseconds(70);
				MLV_free_window();
				exit(0);
			}
		}
		
		bouton = MLV_BUTTON_RIGHT;
		etat = MLV_RELEASED;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

void menu_sauve(int *m, int *s) // l'affichage de menu
{
	int x, y;
	
	MLV_Image *fond_menu;
	MLV_Image *jouer1;
	MLV_Image *jouer2;
	MLV_Image *jouer3;
	MLV_Image *jouer4;
	MLV_Image *retour;
	
	MLV_Mouse_button bouton;
	MLV_Button_state etat;
	
	fond_menu = MLV_load_image("Menu/SCREEN.png");
	jouer1 = MLV_load_image("Menu/2_j.png");
	jouer2 = MLV_load_image("Menu/2_joueurs.png");
	
	jouer3 = MLV_load_image("Menu/JCPU.png");
	jouer4 = MLV_load_image("Menu/J_vs_CPU.png");
	retour = MLV_load_image("Menu/retour.png");
	
	*m = -1;
	*s = -1;
	
	while(*m == -1 && *s == -1) // tant que le joueur n'a pas appuyé sur un choix
	{
		MLV_draw_image(fond_menu, 0, 0);
		MLV_draw_image(jouer1, 350, 220);
		MLV_draw_image(jouer3, 730, 220);
		MLV_draw_image(retour, 30, 30);
		MLV_actualise_window();
		MLV_get_mouse_position(&x, &y);
		
		while (x >= 350 && x <= 530 && y >= 220 && y <= 411) // 2 Joueurs
		{
			etat = MLV_RELEASED;
			MLV_get_mouse_position(&x, &y);
			MLV_clear_window(MLV_COLOR_BLACK);
			MLV_draw_image(fond_menu, 0, 0);
			MLV_draw_image(jouer2, 350, 220);
			MLV_draw_image(jouer3, 730, 220);
			MLV_draw_image(retour, 30, 30);
			MLV_actualise_window();
			MLV_get_event(NULL, NULL, NULL, NULL, NULL, NULL, NULL, &bouton, &etat);
			while (bouton == MLV_BUTTON_LEFT && etat != MLV_RELEASED)
			{
				MLV_clear_window(MLV_COLOR_BLACK);
				MLV_draw_image(fond_menu, 0, 0);
				MLV_draw_image(jouer2, 355, 225);
				MLV_draw_image(jouer3, 730, 220);
				MLV_draw_image(retour, 30, 30);
				MLV_actualise_window();
				MLV_get_event(NULL, NULL, NULL, NULL, NULL, NULL, NULL, &bouton, &etat);
				*s = 1;
				MLV_wait_milliseconds(70);
				return;
			}
		}
		
		while (x >= 730 && x <= 921 && y >= 220 && y <= 411) // J vs CPU
		{
			etat = MLV_RELEASED;
			MLV_get_mouse_position(&x, &y);
			MLV_clear_window(MLV_COLOR_BLACK);
			MLV_draw_image(fond_menu, 0, 0);
			MLV_draw_image(jouer1, 350, 220);
			MLV_draw_image(jouer4, 730, 220);
			MLV_draw_image(retour, 30, 30);
			MLV_actualise_window();
			MLV_get_event(NULL, NULL, NULL, NULL, NULL, NULL, NULL, &bouton, &etat);
			while (bouton == MLV_BUTTON_LEFT && etat != MLV_RELEASED)
			{
				MLV_clear_window(MLV_COLOR_BLACK);
				MLV_draw_image(fond_menu, 0, 0);
				MLV_draw_image(jouer1, 350, 220);
				MLV_draw_image(jouer4, 735, 225);
				MLV_draw_image(retour, 30, 30);
				MLV_actualise_window();
				MLV_get_event(NULL, NULL, NULL, NULL, NULL, NULL, NULL, &bouton, &etat);
				*s = 2;
				MLV_wait_milliseconds(70);
				return;
			}
		}
		
		MLV_get_event(NULL, NULL, NULL, NULL, NULL, &x, &y, &bouton, &etat); // retour
		if (x >= 30 && x <= 94 && y >= 30 && y <= 94 && bouton == MLV_BUTTON_LEFT && etat == MLV_PRESSED)
			*m = 0;
		
		bouton = MLV_BUTTON_RIGHT;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

void actualiser(damier d, MLV_Image *p1, MLV_Image *p2, MLV_Image *p3, MLV_Image *p4, MLV_Image *fond, MLV_Font *police, MLV_Image *retour, MLV_Image *sauver) // actualiser l'ecran
{
	MLV_draw_image(fond, 0, 0);
	affiche_damier(p1, p2, p3, p4, d);
	MLV_draw_text_with_font(910, 193, "%d", police, MLV_COLOR_WHITE, d[8][3]);
	MLV_draw_text_with_font(1095, 193, "%d", police, MLV_COLOR_WHITE, d[8][4]);
	MLV_draw_text_with_font(910, 303, "%d", police, MLV_COLOR_WHITE, d[8][1]);
	MLV_draw_text_with_font(1095, 303, "%d", police, MLV_COLOR_WHITE, d[8][2]);
	MLV_draw_image(sauver, 920, 600);
	MLV_draw_image(retour, 920, 700);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

void deplacer(MLV_Image *image, int x, int y, int m, int n, 
						  damier d, MLV_Image *p1, MLV_Image *p2, MLV_Image *p3, MLV_Image *p4, MLV_Image *fond, MLV_Font *police, MLV_Image *retour, MLV_Image *sauver) // x - y: la position du pion ---- m - n: la position ou on va se deplacer
{
	int i, j, p;
	
	p = d[x][y]; // on garde le genre du pion
	d[x][y] = 0; // on l'efface de sa case de départ
	
	if (x>m && y>n) // si la destination se trouve en haut à gauche
	{
		j = x*100;
		for(i=y*100;i>=n*100;i--)
		{
			if (i % 100 == 0) // si le pion arrive à une case
			{
				if (d[j/100][i/100] != p && d[j/100][i/100] != 0) // si il y a un pion ennemi dans sa route il va le manger
				{
					d[j/100][i/100] = 0;
					if (p == 1 || p == 3) // on modifie le nombre des pions restatnts
						d[8][2]--;
					else if (p == 2 || p == 4)
						d[8][1]--;
				}
			}
			MLV_clear_window(MLV_COLOR_BLACK);
			actualiser(d, p1, p2, p3, p4, fond, police, retour, sauver);
			MLV_draw_image(image, i, j);
			j--;
			MLV_actualise_window();
			MLV_wait_milliseconds(1);
		}
	}
	
	else if (x<m && y>n) // si la destination se trouve en haut à droite
	{
		j = x*100;
		for(i=y*100;i>=n*100;i--)
		{
			if (i % 100 == 0) // si il y a un pion ennemi dans sa route il va le manger
			{
				if (d[j/100][i/100] != p && d[j/100][i/100] != 0)
				{
					d[j/100][i/100] = 0;
					if (p == 1 || p == 3)
						d[8][2]--;
					else
						d[8][1]--;
				}
			}
			MLV_clear_window(MLV_COLOR_BLACK);
			actualiser(d, p1, p2, p3, p4, fond, police, retour, sauver);
			MLV_draw_image(image, i, j);
			j++;
			MLV_actualise_window();
			MLV_wait_milliseconds(1);
		}
	}
	
	else if(x>m && y<n) // si la destination se trouve en bas à gauche
	{
		j = x*100;
		for(i=y*100;i<=n*100;i++)
		{
			if (i % 100 == 0) // si il y a un pion ennemi dans sa route il va le manger
			{
				if (d[j/100][i/100] != p && d[j/100][i/100] != 0)
				{
					d[j/100][i/100] = 0;
					if (p == 1 || p == 3)
						d[8][2]--;
					else
						d[8][1]--;
				}
			}
			MLV_clear_window(MLV_COLOR_BLACK);
			actualiser(d, p1, p2, p3, p4, fond, police, retour, sauver);
			MLV_draw_image(image, i, j);
			j--;
			MLV_actualise_window();
			MLV_wait_milliseconds(1);
		}
	}
	
	else if(x<m && y<n) // si la destination se trouve en bas à droite
	{
		j = x*100;
		for(i=y*100;i<=n*100;i++)
		{
			if (i % 100 == 0) // si il y a un pion ennemi dans sa route il va le manger
			{
				if (d[j/100][i/100] != p && d[j/100][i/100] != 0)
				{
					d[j/100][i/100] = 0;
					if (p == 1 || p == 3)
						d[8][2]--;
					else
						d[8][1]--;
				}
			}
			actualiser(d, p1, p2, p3, p4, fond, police, retour, sauver);
			MLV_draw_image(image, i, j);
			j++;
			MLV_actualise_window();
			MLV_wait_milliseconds(1);
		}
	}
	
	if (p == 1 && m == 0) // si il est arrivé au bout du damier on transforme le pion en reinne
		d[m][n] = 3;
	else if (p == 2 && m == 7)
		d[m][n] = 4;
	else
		d[m][n] = p;
}

void affichage_score(MLV_Image *fond, MLV_Font *police) // l"affichage du score
{
	int y = 600;
	int rang, score;
	char nom[50];
	
	FILE* topscore = NULL;
	topscore = fopen("Fichiers/topscore.txt","r");
	
	
	MLV_clear_window(MLV_COLOR_BLACK);
	MLV_draw_image(fond, 0, 0);
	
	while (fscanf(topscore, "%d %d %s", &rang, &score, nom) != EOF)
	{
		MLV_draw_text_with_font(500, y, "%d - %d - %s", police, MLV_COLOR_WHITE, rang, score, nom);
		y -= 50;
	}
	
	MLV_actualise_window();
	
	fclose(topscore);
}



























#endif
