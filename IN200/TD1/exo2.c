#include "uvsqgraphics.h"

//indianred, dodgerblue, mediumspringgreen

void triangle1(POINT p1, POINT p2, POINT p3, COULEUR c)
{
	draw_line(p1,p2,c);
	draw_line(p2,p3,c);
	draw_line(p3,p1,c);
}

void triangle2(COULEUR c)
{
	POINT p1, p2, p3;
	p1 = wait_clic();
	p2 = wait_clic();
	p3 = wait_clic();
	triangle1(p1,p2,p3,c);
}

int main()
{
	init_graphics(600,600);

	// Debut du code
	COULEUR c;
	c = mediumspringgreen;
	
	triangle2(c);
	
	// Fin du code

	wait_escape();
	exit(0);
}
