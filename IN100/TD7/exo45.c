#include "uvsqgraphics.h"

void dessine_line_H(COULEUR c)
{
	POINT g, d;
	g.x = 0;
	d.x = 600;
	
	while (g.y <= 600)
	{
		draw_line(g, d, c);
		g.y += 100;
		d.y += 100;
	}
}

void dessine_line_V(COULEUR c)
{
	POINT b, h;
	b.y = 0;
	h.y = 600;
	
	while (b.x <= 600)
	{
		draw_line(b, h, c);
		b.x += 100;
		h.x += 100;
	}
}

void dessine_quadrillage(COULEUR c)
{
	POINT g, d, b, h;
	g.x = 0;
	d.x = 600;
	b.y = 0;
	h.y = 600;
	
	while ((g.y <= 600) && (b.x <= 600))
	{
		draw_line(g, d, c);
		g.y += 100;
		d.y += 100;
		
		draw_line(b, h, c);
		b.x += 100;
		h.x += 100;
	}
}

int main()
{
	init_graphics(600,600);

	// Debut du code
	COULEUR coul;
	
	coul = blanc;
	
	dessine_quadrillage(coul);
	
	// Fin du code

	wait_escape();
	exit(0);
}
