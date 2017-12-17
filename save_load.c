
#ifndef SAVELOADC
#define SAVELOADC

#include "save_load.h"

int sauvegarder_2jr(damier d, joueur jr)
{
	int i, j;
	
	FILE* save = NULL;
	save = fopen("Fichiers/save.txt","w+");
	
	if(save != NULL)
	{
		fprintf(save,"%d ", jr);
		for (i=0;i<9;i++)
			for (j=0;j<8;j++)
				fprintf(save,"%d ", d[i][j]);
	}
	
	else
	{
		fclose(save);
		return -1;
	}
	
	fclose(save);
	return 0;
}

int sauvegarder_cpu(damier d, joueur jr)
{
	int i, j;
	
	FILE* save = NULL;
	save = fopen("Fichiers/save_cpu.txt","w+");
	
	if(save != NULL)
	{
		fprintf(save,"%d ", jr);
		for (i=0;i<9;i++)
			for (j=0;j<8;j++)
				fprintf(save,"%d ", d[i][j]);
	}
	
	else
	{
		fclose(save);
		return -1;
	}
	
	fclose(save);
	return 0;
}

int chargement_2jr(damier d, joueur *jr)
{
	int i, j;
	
	FILE* load = NULL;
	load = fopen("Fichiers/save.txt","r");
	
	if(load != NULL)
	{
		fscanf(load, "%d", &i);
		
		if (i == 0)
			*jr = J1;
		else
			*jr = J2;
			
		for (i=0;i<9;i++)
			for (j=0;j<8;j++)
				fscanf(load, "%d", &d[i][j]);
	}
	
	else
	{
		fclose(load);
		return -1;
	}
	fclose(load);
	return 0;
}

int chargement_cpu(damier d, joueur *jr)
{
	int i, j;
	
	FILE* load = NULL;
	load = fopen("Fichiers/save_cpu.txt","r");
	
	if(load != NULL)
	{
		fscanf(load, "%d", &i);
		
		if (i == 0)
			*jr = J1;
		else
			*jr = J2;
			
		for (i=0;i<9;i++)
			for (j=0;j<8;j++)
				fscanf(load, "%d", &d[i][j]);
	}
	
	else
	{
		fclose(load);
		return -1;
	}
	fclose(load);
	return 0;
}

void ajouter(tab2 t,string t_noms, int nb_coup, char *nom, int *rang)
{
	int trouve = 0;
	int i;
	
	for(i=0;i<10;i++)
	{
		if (t[i][1] == nb_coup && strcmp(t_noms[i], nom) == 0)
			trouve = 1;
	}
	
	i = 1;
	if (trouve == 0)
	{
		while ((nb_coup < t[i][1] || t[i][1] == 0) && i < 10)
		{
			t[i-1][1] = t[i][1];
			strcpy(t_noms[i-1], t_noms[i]);
			i++;
		}
		
		t[i-1][1] = nb_coup;
		strcpy(t_noms[i-1], nom);
		
		*rang = i-1;
	}
}

int meilleur_score(int nb_coup, MLV_Font *p, MLV_Image *oui, MLV_Image *non, int *m,
											 damier d, MLV_Image *p1, MLV_Image *p2, MLV_Image *p3, MLV_Image *p4, MLV_Image *fond, MLV_Font *police, MLV_Image *retour, MLV_Image *sauver) //regarde si le score est un meilleur score et l'insere si s'en est un
{
	int rang = 0;
	int x = 0, y = 0;
	int i = 0;
	tab2 t;
	string t_noms;
	char *nom;
	
	FILE* topscore = NULL;
	topscore = fopen("Fichiers/topscore.txt","r");
	
	if(topscore != NULL)
	{
		fscanf(topscore, "%d %d %s", &t[i][0], &t[i][1], t_noms[i]);
		printf("%d %d %s\n", t[i][0], t[i][1], t_noms[i]);
		if (t[i][1] > nb_coup)
		{
			MLV_draw_text_with_font(840, 400, "Vôtre score est classé parmi les 10 mielleurs !", p, MLV_COLOR_WHITE);
			MLV_draw_text_with_font(860, 420, "Est-ce-que vous voulez l'enregistrer?", p, MLV_COLOR_WHITE);
			MLV_draw_image(oui, 920, 450);
			MLV_draw_image(non, 1020, 450);
			MLV_actualise_window();
			
			while (1)
			{
				MLV_wait_mouse(&x, &y);
				
				if (x >= 1020 && x <= 1084 && y >= 450 && y <= 514)
				{
					fclose(topscore);
					return 0;
				}
				
				else if (x >= 920 && x <= 984 && y >= 450 && y <= 514)
				{
					MLV_clear_window(MLV_COLOR_BLACK);
					actualiser(d, p1, p2, p3, p4, fond, police, retour, sauver);
					MLV_wait_input_box_with_font(840, 400, 320, 50, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_BLACK, " Entrez votre nom: ", &nom, p);
				
					for(i=1;i<10;i++)
					{
						fscanf(topscore, "%d %d %s", &t[i][0], &t[i][1], t_noms[i]);
						printf("%d %d %s\n", t[i][0], t[i][1], t_noms[i]);
					}
			
					//for(i=0;i<10;i++)
					//	printf("%d %d %s\n", t[i][0], t[i][1], t_noms[i]);
			
					ajouter(t, t_noms, nb_coup, nom, &rang);
					//for(i=0;i<10;i++)
						//fprintf(topscore,"%d %d %s\n", t[i][0], t[i][1], t_noms[i]);
				
				
					fclose(topscore);
			
					topscore = fopen("Fichiers/topscore.txt","w+");

					for(i=0;i<10;i++)
						fprintf(topscore,"%d %d %s\n", t[i][0], t[i][1], t_noms[i]);
					
					if (rang == 0)
						MLV_draw_text_with_font(840, 400, "Votre score est déja réalisé !", p, MLV_COLOR_WHITE);
					else if (rang == 1)
						MLV_draw_text_with_font(840, 400, "Vous êtes classé le 1er dans le podium !", p, MLV_COLOR_WHITE);
					else
						MLV_draw_text_with_font(840, 400, "Vous êtes classé le %dème dans le podium !", p, MLV_COLOR_WHITE, rang);
				
					MLV_draw_text_with_font(840, 420, "Vous voulez voir les mielleurs scores?", p, MLV_COLOR_WHITE);
					MLV_draw_image(oui, 920, 450);
					MLV_draw_image(non, 1020, 450);
					MLV_actualise_window();
					
					while (1)
					{
						MLV_wait_mouse(&x, &y);
						
						if (x >= 1020 && x <= 1084 && y >= 450 && y <= 514)
						{
							fclose(topscore);
							return 0;
						}
						
						else if (x >= 920 && x <= 984 && y >= 450 && y <= 514)
						{
							*m = 4;
							fclose(topscore);
							return 0;
						}
					}
				}
			}
		}
	}
	
	fclose(topscore);
	return 1;
}

#endif
