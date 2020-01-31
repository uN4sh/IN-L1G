#include "uvsqgraphics.h"

void dessine_cercle_couleur(int rayon)
{
	POINT c1, c2;
	// c1 centre du cercle, c2 clic utilisateur
	
	c1 = wait_clic();
	draw_fill_circle(c1, rayon, blanc);
	// cercle plein rouge 
	
	int dist;
	COULEUR coul[3];
	coul[0] = vert; coul[1] = rouge; coul[2] = blanc;
	
	int i = 0;
	
	// attente d'un clic et calcul de la distance entre le clic et le centre
	c2 = wait_clic();
	dist = (sqrt(pow((c1.x - c2.x),2) + pow((c1.y - c2.y),2)));
		while (dist < rayon)
		{
			// tant que la distance est inferieure au rayon = clic dans le cercle
			
			draw_fill_circle(c1, rayon, coul[i%3]);
			i++;
			c2 = wait_clic();
			dist = (sqrt(pow((c1.x - c2.x),2) + pow((c1.y - c2.y),2)));
		}
}

int main()
{
	init_graphics(600,600);

	// Debut du code
	int rayon;
	
	rayon = lire_entier_clavier();
	dessine_cercle_couleur(rayon);
	// Fin du code

	wait_escape();
	exit(0);
}
