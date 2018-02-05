
#include "possibilites.h"
#include "affichage.h"
#include "save_load.h"
#include "coups.h"

int main()
{
	int x, y;
	int m = 0, s = 0;
	int bouton = -1;
	int mouv = 0;
	int egalite = 0;
	int chargement = 0;
	
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
	MLV_Image *oui;
	MLV_Image *non;
	
	MLV_Font *police;
	MLV_Font *p;
	MLV_Font *font;
	
	MLV_create_window("Game Of Draughts", "GOD", 1200, 800);
	
	fond = MLV_load_image("Images/fond.jpg");
	p1 = MLV_load_image("Images/1.png");
	p2 = MLV_load_image("Images/2.png");
	p3 = MLV_load_image("Images/3.png");
	p4 = MLV_load_image("Images/4.png");
	retour = MLV_load_image("Images/retour2.png");
	sauver = MLV_load_image("Images/sauver2.png");
	fond_score = MLV_load_image("Images/fond_score.jpg");
	oui = MLV_load_image("Images/oui.png");
	non = MLV_load_image("Images/non.png");
	
	police = MLV_load_font("Fichiers/police.ttf", 40);
	p = MLV_load_font("Fichiers/BebasNeue.otf", 40);
	font = MLV_load_font("Fichiers/Comfortaa-Bold.ttf", 15);
	
	while(1)
	{
		if (m == 0)
			menu(&m);
		
		if (m == 1) // --------------------------------------------------------------------- Mode 2 joueurs
		{
			egalite = 0;
			
			mouv = 0; 
			
			if (chargement == 0) // si on est pas en mode chargement on initialise le jeu
			{
				init_damier(d);
				jr = J1;
			}
			
			while (d[8][1] != 0 && d[8][2] != 0 && egalite == 0) // tant que il reste aucun pion et le jeu n'est pas en élité
			{
				jouer_tour(d, &jr, p1, p2, p3, p4, fond, police, retour, sauver, &bouton);
				
				if (bouton == 2) // si le joueur a appuyer su le bouton retour
					break;
					
				else if (bouton == 1) // si le joueur a appuyer su le bouton sauvegarder
				{
					sauvegarder_2jr(d, jr);
					MLV_draw_text_with_font(880, 400, "La partie a été bien sauvegardée !", font, MLV_COLOR_WHITE);
					MLV_actualise_window();
					MLV_wait_seconds(1);
					actualiser(d, p1, p2, p3, p4, fond, police, retour, sauver);
					MLV_actualise_window();
				}
				
				if (d[8][1] == 1 && d[8][2] == 1) // si il rest qu'un seul pion
				{
					if (mouv == 3) // si les deux joueurs on fait 3 mouvements on propose de sortir en egalité
					{
						MLV_clear_window(MLV_COLOR_BLACK);
						actualiser(d, p1, p2, p3, p4, fond, police, retour, sauver);
						MLV_draw_text_with_font(850, 400, "Voulez-vous finir le match par une égalité?", font, MLV_COLOR_WHITE);
						MLV_draw_image(oui, 920, 450);
						MLV_draw_image(non, 1020, 450);
						MLV_actualise_window();
						
						while (1)
						{
							MLV_wait_mouse(&x, &y);
				
							if (x >= 1020 && x <= 1084 && y >= 450 && y <= 514)
							{
								break;
							}
						
							else if (x >= 920 && x <= 984 && y >= 450 && y <= 514)
							{
								MLV_clear_window(MLV_COLOR_BLACK);
								actualiser(d, p1, p2, p3, p4, fond, police, retour, sauver);
								MLV_draw_text_with_font(930, 400, "Le match est nul", font, MLV_COLOR_WHITE);
								MLV_actualise_window();
								MLV_wait_seconds(1);
								
								MLV_clear_window(MLV_COLOR_BLACK);
								actualiser(d, p1, p2, p3, p4, fond, police, retour, sauver);
								MLV_draw_text_with_font(930, 400, "Voulez-vous rejouer?", font, MLV_COLOR_WHITE);
								MLV_draw_image(oui, 920, 450);
								MLV_draw_image(non, 1020, 450);
								MLV_actualise_window();
					
								while (1)
								{
									MLV_wait_mouse(&x, &y);
				
									if (x >= 1020 && x <= 1084 && y >= 450 && y <= 514) // si le joueur ne veut pa rejouer
									{
										m = 0;
										break;
									}
						
									else if (x >= 920 && x <= 984 && y >= 450 && y <= 514) // si le joueur veut rejouer
									{
										m = 1;
										break;
									}
								}
								
								egalite = 1;
								bouton = 2;
								break;
							}
						}
						mouv++;
					}
					
					else if (mouv < 3) // si ils ont pas joué 3 fois on incrémente mouv
						mouv++;
				}
			}
			
			if (bouton != 2) // si l'utilisateur n'a pas appuyer sur retour
			{
				if (d[8][1] == 0) // si le joueur 1 est le perdant
				{
					actualiser(d, p1, p2, p3, p4, fond, police, retour, sauver);
					MLV_draw_text_with_font(930, 360, "Le joueur 2 a gagné!", font, MLV_COLOR_WHITE);
					MLV_actualise_window();
					MLV_wait_seconds(1);
					meilleur_score(d[8][4], font, oui, non, &m, d, p1, p2, p3, p4, fond, police, retour, sauver);
				}
				
				else // si le joueur 2 est le perdant
				{
					actualiser(d, p1, p2, p3, p4, fond, police, retour, sauver);
					MLV_draw_text_with_font(930, 360, "Le joueur 1 a gagné!", font, MLV_COLOR_WHITE);
					MLV_actualise_window();
					MLV_wait_seconds(1);
					meilleur_score(d[8][3], font, oui, non, &m, d, p1, p2, p3, p4, fond, police, retour, sauver);
				}
			
				if (m != 4) // si le joueur n'a pas voulu voir le meilleur score dans meilleur_score
				{
					MLV_clear_window(MLV_COLOR_BLACK);
					actualiser(d, p1, p2, p3, p4, fond, police, retour, sauver);
					MLV_draw_text_with_font(930, 400, "Voulez-vous rejouer?", font, MLV_COLOR_WHITE);
					MLV_draw_image(oui, 920, 450);
					MLV_draw_image(non, 1020, 450);
					MLV_actualise_window();
					
					while (1)
					{
						MLV_wait_mouse(&x, &y);
				
						if (x >= 1020 && x <= 1084 && y >= 450 && y <= 514)
						{
							m = 0;
							break;
						}
						
						else if (x >= 920 && x <= 984 && y >= 450 && y <= 514)
						{
							m = 1;
							break;
						}
					}
				}
			}
			
			else // si le joueur a qppuyé sur retour
				if (egalite == 0) // si ce n'est pas une égalité
					m = 0; // on revient au menu
			chargement = 0; // si on était en mode chargement on le désactive
		}
		
		else if (m == 2) // --------------------------------------------------------------------- Mode Joueur vs CPU : comme mode 2 Joueurs sauf qu'ici on fait un coup de joueur et un autre de la machine
		{
			egalite = 0;
			
			mouv = 0; 
			
			if (chargement == 0) // si on est pas en mode chargement on initialise le jeu
			{
				init_damier(d);
				jr = J1;
			}
			
			while (d[8][1] != 0 && d[8][2] != 0 && egalite == 0) // tant que il reste aucun pion et le jeu n'est pas en élité
			{
				bouton = 0;
				
				jr = J1;
				
				jouer_tour(d, &jr, p1, p2, p3, p4, fond, police, retour, sauver, &bouton);
				
				if (bouton == 2) // si le joueur a appuyer su le bouton retour
					break;
					
				else if (bouton == 1) // si le joueur a appuyer su le bouton sauvegarder
				{
					sauvegarder_cpu(d, jr);
					MLV_draw_text_with_font(880, 400, "La partie a été bien sauvegardée !", font, MLV_COLOR_WHITE);
					MLV_actualise_window();
					MLV_wait_seconds(1);
					actualiser(d, p1, p2, p3, p4, fond, police, retour, sauver);
					MLV_actualise_window();
					while (bouton != 3 && bouton != 2)
						jouer_tour(d, &jr, p1, p2, p3, p4, fond, police, retour, sauver, &bouton);
				}
				
				if ((bouton == 0 || bouton == 3) && d[8][2] != 0)
					jouer_cpu(d, &jr, p1, p2, p3, p4, fond, police, retour, sauver);
				
				if (d[8][1] == 1 && d[8][2] == 1) // si il rest qu'un seul pion
				{
					if (mouv == 3) // si les deux joueurs on fait 3 mouvements on propose de sortir en egalité
					{
						MLV_clear_window(MLV_COLOR_BLACK);
						actualiser(d, p1, p2, p3, p4, fond, police, retour, sauver);
						MLV_draw_text_with_font(850, 400, "Voulez-vous finir le match par une égalité?", font, MLV_COLOR_WHITE);
						MLV_draw_image(oui, 920, 450);
						MLV_draw_image(non, 1020, 450);
						MLV_actualise_window();
						
						while (1)
						{
							MLV_wait_mouse(&x, &y);
				
							if (x >= 1020 && x <= 1084 && y >= 450 && y <= 514)
							{
								break;
							}
						
							else if (x >= 920 && x <= 984 && y >= 450 && y <= 514)
							{
								MLV_clear_window(MLV_COLOR_BLACK);
								actualiser(d, p1, p2, p3, p4, fond, police, retour, sauver);
								MLV_draw_text_with_font(930, 400, "Le match est nul", font, MLV_COLOR_WHITE);
								MLV_actualise_window();
								MLV_wait_seconds(1);
								
								MLV_clear_window(MLV_COLOR_BLACK);
								actualiser(d, p1, p2, p3, p4, fond, police, retour, sauver);
								MLV_draw_text_with_font(930, 400, "Voulez-vous rejouer?", font, MLV_COLOR_WHITE);
								MLV_draw_image(oui, 920, 450);
								MLV_draw_image(non, 1020, 450);
								MLV_actualise_window();
					
								while (1)
								{
									MLV_wait_mouse(&x, &y);
				
									if (x >= 1020 && x <= 1084 && y >= 450 && y <= 514) // si le joueur ne veut pa rejouer
									{
										m = 0;
										break;
									}
						
									else if (x >= 920 && x <= 984 && y >= 450 && y <= 514) // si le joueur veut rejouer
									{
										m = 2;
										break;
									}
								}
								
								egalite = 1;
								bouton = 2;
								break;
							}
						}
						mouv++;
					}
					
					else if (mouv < 3) // si ils ont pas joué 3 fois on incrémente mouv
						mouv++;
				}
			}
			
			if (bouton != 2)
			{
				if (d[8][1] == 0)
				{
					actualiser(d, p1, p2, p3, p4, fond, police, retour, sauver);
					MLV_draw_text_with_font(930, 360, "L'ordinateur a gagné!", font, MLV_COLOR_WHITE);
					MLV_actualise_window();
					MLV_wait_seconds(1);
				}
				
				else
				{
					actualiser(d, p1, p2, p3, p4, fond, police, retour, sauver);
					MLV_draw_text_with_font(930, 360, "Vous avez gagné!", font, MLV_COLOR_WHITE);
					MLV_actualise_window();
					MLV_wait_seconds(1);
					meilleur_score(d[8][3], font, oui, non, &m, d, p1, p2, p3, p4, fond, police, retour, sauver);
				}
			
				if (m != 4)
				{
					MLV_clear_window(MLV_COLOR_BLACK);
					actualiser(d, p1, p2, p3, p4, fond, police, retour, sauver);
					MLV_draw_text_with_font(930, 400, "Voulez-vous rejouer?", font, MLV_COLOR_WHITE);
					MLV_draw_image(oui, 920, 450);
					MLV_draw_image(non, 1020, 450);
					MLV_actualise_window();
					
					while (1)
					{
						MLV_wait_mouse(&x, &y);
				
						if (x >= 1020 && x <= 1084 && y >= 450 && y <= 514)
						{
							m = 0;
							break;
						}
						
						else if (x >= 920 && x <= 984 && y >= 450 && y <= 514)
						{
							m = 2;
							break;
						}
					}
				}
			}
			
			else
				if (egalite == 0)
					m = 0;
			chargement = 0;
		}
		
		else if (m == 3) // --------------------------------------------------------------------- Chargement Partie
		{
			menu_sauve(&m, &s);
			
			if (s == 1)
			{
				chargement_2jr(d, &jr);
				m = 1;
			}
			
			else if (s == 2)
			{
				chargement_cpu(d, &jr);
				m = 2;
			}
			
			chargement = 1;
		}
		
		if (m == 4) // --------------------------------------------------------------------- Meilleur Score
		{
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
