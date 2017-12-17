

#ifndef SAVELOADH
#define SAVELOADH

#include <stdio.h>
#include <string.h>
#include "types.h"
#include "affichage.h"

int sauvegarder_2jr(damier d, joueur jr);

int sauvegarder_cpu(damier d, joueur jr);

int chargement_2jr(damier d, joueur *jr);

int chargement_cpu(damier d, joueur *jr);

int meilleur_score(int nb_coup, MLV_Font *p, MLV_Image *oui, MLV_Image *non, int *m,
											 damier d, MLV_Image *p1, MLV_Image *p2, MLV_Image *p3, MLV_Image *p4, MLV_Image *fond, MLV_Font *police, MLV_Image *retour, MLV_Image *sauver);

#endif
