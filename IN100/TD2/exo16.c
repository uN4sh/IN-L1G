#include "uvsqgraphics.h"

int main()
{
	init_graphics(600,600);

	// Debut du code
	POINT p1;
	POINT p2;
	POINT p3, p4, p5;

	p1.x = 300; p1.y = 600;
	p2.x = 300; p2.y = 0;
	draw_line(p1,p2,blanc);
	// Ligne qui partage l'écran en 2
	
	p3 = wait_clic();
	p4 = wait_clic();
	p5 = wait_clic();
	
	if ((p3.x < 300 && p4.x < 300 && p5.x < 300) || 
	(p3.x > 300 && p4.x > 300 && p5.x > 300))
	{
		draw_line(p3,p4,rouge);
		draw_line(p4,p5,rouge);
		draw_line(p5,p3,rouge);
	}
	// Fin du code
	
	wait_escape();
	exit(0);
}
