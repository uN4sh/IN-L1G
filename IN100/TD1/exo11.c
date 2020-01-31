#include "uvsqgraphics.h"

int main()
{
	init_graphics(600,600);

	// Debut du code
	POINT p1;
	POINT p2;
	POINT p3;
	
	p1.x = lire_entier_clavier(); p1.y = 100;
	p2.x = lire_entier_clavier(); p2.y = 100;
	
	draw_fill_circle(p1, 5, blanc);
	draw_fill_circle(p2, 5, blanc);
	draw_line(p1, p2, blanc);
	
	p3.x = (p2.x + p1.x)/2;
	p3.y = 400;
	
	draw_fill_circle(p3, 5, blanc);
	draw_line(p1, p3, rouge);
	draw_line(p2, p3, rouge);

	

	// Fin du code

	wait_escape();
	exit(0);
}
