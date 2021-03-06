

#ifndef COUPSH
#define COUPSH

#include <time.h>
#include "types.h"
#include "affichage.h"
#include "possibilites.h"

void jouer_tour(damier d, joueur *jr, MLV_Image *p1, MLV_Image *p2, MLV_Image *p3, MLV_Image *p4, MLV_Image *fond, MLV_Font *police, MLV_Image *retour, MLV_Image *sauver, int *bouton);

void jouer_cpu(damier d, joueur *jr, MLV_Image *p1, MLV_Image *p2, MLV_Image *p3, MLV_Image *p4, MLV_Image *fond, MLV_Font *police, MLV_Image *retour, MLV_Image *sauver);

#endif
