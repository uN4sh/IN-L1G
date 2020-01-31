#include "uvsqgraphics.h"

int main()
{
	init_graphics(600,600);

	// Debut du code
	POINT p;
	POINT p1;
	POINT p2;
	POINT p3;
	POINT p4;
	POINT p5;
	POINT p6;
	POINT p7;
	
	p = wait_clic();
	draw_circle(p, 100, blanc);
	
	p1.x = (p.x - 100) ; p1.y = p.y;
	p2.x = (p.x - 50) ; p2.y = (p.y + 86);
	p3.x = (p.x + 50) ; p3.y = (p.y + 86);
	p4.x = (p.x + 100); p4.y = p.y;
	p5.x = (p.x + 50); p5.y = (p.y - 86);
	p6.x = (p.x - 50); p6.y = (p.y - 86);
	
	draw_line(p1, p2, blanc);
	draw_line(p2, p3, blanc);
	draw_line(p3, p4, blanc);
	draw_line(p4, p5, blanc);
	draw_line(p5, p6, blanc);
	draw_line(p6, p1, blanc);
	

	// Fin du code
	

	wait_escape();
	exit(0);
}
