
#ifndef SAVELOADC
#define SAVELOADC

#include "save_load.h"

int sauvegarder(damier d, joueur jr)
{
	int i, j;
	
	FILE* save = NULL;
	save = fopen("save.txt","w+");
	
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

int chargement(damier d, joueur *jr)
{
	int i, j;
	
	FILE* load = NULL;
	load = fopen("save.txt","r");
	
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

void ajouter(tab2 t,string t_noms, int nb_coup, char *nom)
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
			//t[i-1][0] = t[i][0];
			t[i-1][1] = t[i][1];
			strcpy(t_noms[i-1], t_noms[i]);
			//t_noms[i-1] = strdup(t_noms[i]);
			//t_noms[i-1] = t_noms[i];
			i++;
		}
		//t[i-1][0] = t[i][0];
		t[i-1][1] = nb_coup;
		//t_noms[i-1] = nom;
		//t_noms[i-1] = strdup(nom);
		strcpy(t_noms[i-1], nom);
		//t_noms[i-1] = nom;
	}
}

int meilleur_score(int nb_coup, MLV_Font *p) //regarde si le score est un meilleur score et l'insere si s'en est un
{
	int i = 0;
	tab2 t;
	string t_noms;
	char nom[50] = "Ismail";
	
	FILE* topscore = NULL;
	topscore = fopen("topscore.txt","r");
	
	if(topscore != NULL)
	{
		fscanf(topscore, "%d %d %s", &t[i][0], &t[i][1], t_noms[i]);
		printf("%d %d %s\n", t[i][0], t[i][1], t_noms[i]);
		if (t[i][1] > nb_coup)
		{
			//MLV_draw_text_with_font(800, 400, "Vôtre score est classé parmi les 10 mielleurs!", p, MLV_COLOR_WHITE);
			//MLV_draw_text_with_font(800, 450, "Est-ce-que vous voulez l'enregistrer?", p, MLV_COLOR_WHITE);
			//MLV_actualise_window();
			//MLV_wait_seconds(1);
			for(i=1;i<10;i++)
			{
				fscanf(topscore, "%d %d %s", &t[i][0], &t[i][1], t_noms[i]);
				printf("%d %d %s\n", t[i][0], t[i][1], t_noms[i]);
			}
			
			//for(i=0;i<10;i++)
			//	printf("%d %d %s\n", t[i][0], t[i][1], t_noms[i]);
			
			ajouter(t, t_noms, nb_coup, nom);
			//for(i=0;i<10;i++)
				//fprintf(topscore,"%d %d %s\n", t[i][0], t[i][1], t_noms[i]);
				
				
			fclose(topscore);
			
			topscore = fopen("topscore.txt","w+");

			for(i=0;i<10;i++)
				fprintf(topscore,"%d %d %s\n", t[i][0], t[i][1], t_noms[i]);
		}
	}
	
	fclose(topscore);
	return 0;
}

#endif
