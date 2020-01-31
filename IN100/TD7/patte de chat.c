#include "uvsqgraphics.h"

void dessine_mickey(POINT centre, COULEUR c)
{
	POINT c1, c2, c3, c4;
	int rayon;
	int r2;
		// c1 et c2 centres des oreilles et r2 rayon des oreilles
		
	rayon = 100;
	
	r2 = rayon / 3;
	
	
	c1.x = centre.x - rayon;
	c1.y = centre.y + rayon;
	
	c2.x = centre.x + rayon;
	c2.y = centre.y + rayon;
	
	c3.x = centre.x - 35;
	c3.y = centre.y + rayon + 40;
	
	c4.x = centre.x + 35;
	c4.y = centre.y + rayon + 40;
	
	draw_circle(c1, r2, c);
	draw_circle(c2, r2, c);
	draw_circle(c3, r2, c);
	draw_circle(c4, r2, c);
	draw_circle(centre, rayon, c);
	// Grand cercle
}

int main()
{
	init_graphics(600,600);

	// Debut du code
	POINT centre;
	COULEUR c;
	
	centre = wait_clic();
	c = blanc;
	dessine_mickey(centre, c);
	
	// Fin du code

	wait_escape();
	exit(0);
}
