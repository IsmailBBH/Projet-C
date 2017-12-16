
#include "possibilites.h"
#include "affichage.h"
#include "save_load.h"
#include "coups.h"

int main()
{
	int x, y;
	int m;
	int bouton = -1;
	
	damier d;
	joueur jr;
	
	MLV_Image *fond;
	MLV_Image *p1;
	MLV_Image *p2;
	MLV_Image *p3;
	MLV_Image *p4;
	MLV_Image *retour;
	MLV_Image *sauver;
	MLV_Image *fond_score;
	
	MLV_Font *police;
	MLV_Font *p;
	
	MLV_create_window("Game Of Draughts", "GOD", 1200, 800);
	
	fond = MLV_load_image("Images/fond.jpg");
	p1 = MLV_load_image("Images/1.png");
	p2 = MLV_load_image("Images/2.png");
	p3 = MLV_load_image("Images/3.png");
	p4 = MLV_load_image("Images/4.png");
	retour = MLV_load_image("Images/retour2.png");
	sauver = MLV_load_image("Images/sauver2.png");
	fond_score = MLV_load_image("Images/fond_score.jpg");
	
	police = MLV_load_font("Images/police.ttf", 40);
	p = MLV_load_font("Images/BebasNeue.otf", 40);
	
	//analyser_damier(d, t, jr);
	
	while(1)
	{
		menu(&m);
		if (m == 1)
		{
			init_damier(d);
			jr = J1;
			while (d[8][1] != 0 && d[8][2] != 0)
			{
				jouer_tour(d, &jr, p1, p2, p3, p4, fond, police, retour, sauver, &bouton);
				if (bouton == 2)
					break;
				else if (bouton == 1)
				{
					sauvegarder(d, jr);
				}
				if (d[8][1] != 1 && d[8][2] != 1)
				{
					egalitee();
				}
			}
			m = 0;
		}
		
		else if (m == 2)
		{
			init_damier(d);
			jr = J1;
			while (d[8][1] != 0 && d[8][2] != 0)
			{
				jr = J1;
				bouton = -1;
				while (bouton != 3)
				{
					jouer_tour(d, &jr, p1, p2, p3, p4, fond, police, retour, sauver, &bouton);
					if (bouton == 2)
						break;
					else if (bouton == 1)
					{
						sauvegarder(d, jr);
					}
					if (d[8][2] == 0)
						break;
				}
				if (bouton == 2)
						break;
				jouer_cpu(d, &jr, p1, p2, p3, p4, fond, police, retour, sauver, &bouton);
			}
			m = 0;
		}
		
		else if (m == 3)
		{
			chargement(d, &jr);
			while (d[8][1] != 0 && d[8][2] != 0)
			{
				jouer_tour(d, &jr, p1, p2, p3, p4, fond, police, retour, sauver, &bouton);
				if (bouton == 2)
					break;
				else if (bouton == 1)
				{
					sauvegarder(d, jr);
				}
			}
			m = 0;
		}
		
		else if (m == 4)
		{
			meilleur_score(2, "Ismail");
			while (1)
			{
				affichage_score(fond_score, p);
				MLV_wait_mouse(&x, &y);
				if (x >= 20 && x <= 90 && y >= 20 && y <= 90)
					break;
			}
			m = 0;
		}
	}

	MLV_free_window();
	exit(0);
}
