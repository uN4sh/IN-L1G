#include "uvsqgraphics.h"

int main()
{
init_graphics(600,400);

// Debut du code
POINT p1;
POINT p2;

p1 = wait_clic();
draw_circle(p1, 100, blanc);
// 1 cercle
	p2 = wait_clic();
	draw_circle(p2, 100, blanc);
	draw_circle(p1, 100, noir);
	
	p1 = wait_clic();
	draw_circle(p1, 100, blanc);
	draw_circle(p2, 100, noir);
	
	p2 = wait_clic();
	draw_circle(p2, 100, blanc);
	draw_circle(p1, 100, noir);
	
	p1 = wait_clic();
	draw_circle(p1, 100, blanc);
	draw_circle(p2, 100, noir);
	
	p2 = wait_clic();
	draw_circle(p2, 100, blanc);
	draw_circle(p1, 100, noir);
	
	p1 = wait_clic();
	draw_circle(p1, 100, blanc);
	draw_circle(p2, 100, noir);
	
	p2 = wait_clic();
	draw_circle(p2, 100, blanc);
	draw_circle(p1, 100, noir);
	
	p1 = wait_clic();
	draw_circle(p1, 100, blanc);
	draw_circle(p2, 100, noir);
	
	p2 = wait_clic();
	draw_circle(p2, 100, blanc);
	draw_circle(p1, 100, noir);


//Fin du 10 fois


// Fin du code

wait_escape();
exit(0);
}
