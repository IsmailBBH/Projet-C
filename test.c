
#include "possibilites.h"
#include "affichage.h"

int main()
{
	int i, j;
	int dames_libres[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int prises[20];
	int mouvements[20];
	int n_poss;
	damier d;
	joueur jr = J1;
	init_damier(d);
	
	MLV_Image *pion1;
	MLV_Image *pion2;
	MLV_Image *pion3;
	MLV_Image *pion4;
	
	MLV_create_window("Test", "Test", 800, 800);
	pion1 = MLV_load_image("un.png");
	pion2 = MLV_load_image("deux.png");
	pion3 = MLV_load_image("trois.png");
	pion4 = MLV_load_image("quatre.png");
	
	//inserer(dames_libres, 5, 2, l);
	
	n_poss = cherche_poss(mouvements, prises, d, jr, 4, 5);
	printf("%d\n",n_poss);
	/*for (i=0;i<dames_libres[0]*2+1;i++)
	{
		printf("%d - ", dames_libres[i]);
		j++;
	}*/
	printf("%d - %d : %d\nMouvements :\n", mouvements[1], mouvements[2], mouvements[0]);
	
	for (i=3;i<mouvements[0]*2+3;i++)
	{
		printf("%d - ", mouvements[i]);
	}
	printf("\n");
	
	printf("\n");
	
	printf("%d - %d : %d\nPrises :\n", prises[1], prises[2], prises[0]);
	
	for (i=3;i<prises[0]*2+3;i++)
	{
		printf("%d - ", prises[i]);
	}
	printf("\n");
	
	while(1)
	{
		affiche_damier(pion1, pion2, pion3, pion4, d);
		affiche_poss(mouvements, MLV_COLOR_GREEN);
		affiche_poss(prises, MLV_COLOR_RED);
		MLV_actualise_window();
	}
	
	MLV_free_window();
	return 0;
	
	 for (i=0;i<8;i++)
	{
		for (j=0;j<8;j++)
			printf("%d", d[i][j]);
		printf("\n");
	}
}
