
#ifndef AFFICHAGEH
#define AFFICHAGEH

void init_damier(damier d);

void affiche_damier(MLV_Image *pion1, MLV_Image *pion2, MLV_Image *pion3, MLV_Image *pion4, damier d);

void affiche_pions(int t[]);

void affiche_poss(int *m, int *p);

void menu(int *m);

void actualiser(damier d, MLV_Image *p1, MLV_Image *p2, MLV_Image *p3, MLV_Image *p4, MLV_Image *fond, MLV_Font *police, MLV_Image *retour, MLV_Image *sauver);

void deplacer(MLV_Image *image, int x, int y, int m, int n, 
						  damier d, MLV_Image *p1, MLV_Image *p2, MLV_Image *p3, MLV_Image *p4, MLV_Image *fond, MLV_Font *police, MLV_Image *retour, MLV_Image *sauver);
						  
void affichage_score(MLV_Image *fond, MLV_Font *police);

#endif
