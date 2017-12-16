

#ifndef SAVELOADH
#define SAVELOADH

#include <stdio.h>
#include <string.h>
#include "types.h"

int sauvegarder(damier d, joueur jr);

int chargement(damier d, joueur *jr);

int meilleur_score(int nb_coup, char *nom);

#endif
