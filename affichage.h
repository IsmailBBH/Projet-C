
#ifndef AFFICHAGEH
#define AFFICHAGEH

void init_damier(damier d);

void affiche_damier(MLV_Image *pion1, MLV_Image *pion2, MLV_Image *pion3, MLV_Image *pion4, damier d);

void affiche_pions(int t[]);

void affiche_poss(int *m, int *p);

void menu(int *m);

#endif
