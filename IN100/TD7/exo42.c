#include "uvsqgraphics.h"

void dessine_croix(POINT centre, int largeur, COULEUR c)
{
	POINT bg, hd;
	POINT bd, hg;
	
	bg.x = centre.x - largeur/2;
	bg.y = centre.y - largeur/2;
	hd.x = centre.x + largeur/2;
	hd.y = centre.y + largeur/2;
	// Points bg et hd positionnés en fonction du centre
	
	bd.x = centre.x - largeur/2;
	bd.y = centre.y + largeur/2;
	hg.x = centre.x + largeur/2;
	hg.y = centre.y - largeur/2;
	// Points bg et hg positionnés en fonction du centre
	
	draw_rectangle(bg, hd, c);
	draw_line(bg, hd, c);
	draw_line(bd, hg, c);
	// Tracé du rectangle et des 2 lignes pour la croix
}

int main()
{
	init_graphics(600,600);

	// Debut du code
	
	int l;
	POINT centre;
	COULEUR c;
	
	c = blanc;
	centre = wait_clic();
	l = lire_entier_clavier();
	
	dessine_croix(centre, l, c);
	
	// Fin du code

	wait_escape();
	exit(0);
}
