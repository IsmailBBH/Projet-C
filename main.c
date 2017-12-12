
#include "possibilites.h"
#include "affichage.h"
#include "coups.h"

int main()
{
	int m;
	//int prises[20];
	//int mouvements[20];
	damier d;
	joueur jr;
	
	MLV_Image *fond;
	MLV_Image *p1;
	MLV_Image *p2;
	MLV_Image *p3;
	MLV_Image *p4;
	
	MLV_create_window("Game Of Draughts", "GOD", 1200, 800);
	
	fond = MLV_load_image("Images/fond.jpg");
	p1 = MLV_load_image("Images/1.png");
	p2 = MLV_load_image("Images/2.png");
	p3 = MLV_load_image("Images/3.png");
	p4 = MLV_load_image("Images/4.png");
	
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
				MLV_clear_window(MLV_COLOR_BLACK);
				MLV_actualise_window();
				MLV_draw_image(fond, 0, 0);
				affiche_damier(p1, p2, p3, p4, d);
				/*affiche_pions(t);
				deplacer(pion1, 5, 2, 3, 0, d, pion1, pion2, pion3, pion4, fond);*/
				jouer_tour(d, &jr, p1, p2, p3, p4, fond);
				MLV_actualise_window();
			}
		}
	}
	
	MLV_free_window();
	exit(0);
}
