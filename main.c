
#include "possibilites.h"
#include "affichage.h"

int main()
{
	int t[20], m;
	//int prises[20];
	//int mouvements[20];
	damier d;
	joueur jr = J1;
	init_damier(d);
	
	MLV_Image *fond;
	MLV_Image *pion1;
	MLV_Image *pion2;
	MLV_Image *pion3;
	MLV_Image *pion4;
	
	MLV_create_window("Game Of Draughts", "GOD", 1200, 800);
	
	fond = MLV_load_image("Images/DAMIER.png");
	pion1 = MLV_load_image("Images/1.png");
	pion2 = MLV_load_image("Images/2.png");
	pion3 = MLV_load_image("Images/3.png");
	pion4 = MLV_load_image("Images/4.png");
	
	analyser_damier(d, t, jr);
	
	while(1)
	{
		menu(&m);
		if (m == 1)
		{
				MLV_clear_window(MLV_COLOR_BLACK);
				MLV_draw_image(fond, 0, 0);
				affiche_damier(pion1, pion2, pion3, pion4, d);
				affiche_pions(t);
				deplacer(pion1, 5, 2, 6, 3, d, pion1, pion2, pion3, pion4, fond);
				MLV_actualise_window();
		}
	}
	
	MLV_free_window();
	exit(0);
}
