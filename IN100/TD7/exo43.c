#include "uvsqgraphics.h"

void dessine_mickey(POINT centre, int rayon, COULEUR c)
{
	POINT c1, c2;
	int r2;
		// c1 et c2 centres des oreilles et r2 rayon des oreilles
	r2 = rayon / 2;
	
	c1.x = centre.x - rayon;
	c1.y = centre.y + rayon;
	
	c2.x = centre.x + rayon;
	c2.y = centre.y + rayon;
	
	draw_fill_circle(c1, r2, c);
	draw_fill_circle(c2, r2, c);
	draw_circle(centre, rayon, c);
	// Grand cercle
}

int main()
{
	init_graphics(600,600);

	// Debut du code
	POINT centre;
	int r;
	COULEUR c;
	
	centre = wait_clic();
	r = lire_entier_clavier();
	c = blanc;
	dessine_mickey(centre, r, c);
	
	// Fin du code

	wait_escape();
	exit(0);
}
