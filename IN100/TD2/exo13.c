#include "uvsqgraphics.h"

int main()
{
	init_graphics(600,600);

	// Debut du code
	POINT p1;
	POINT p2;
	POINT p3;

	p1.x = p2.x = WIDTH/2; 
	p1.y = 600; p2.y = 0;
	draw_line(p1,p2,blanc);
	// Ligne qui partage l'écran en 2
	
	p3 = wait_clic();
	
	if (p3.x < 300)
	{
		draw_circle(p3,50,bleu);
	}
	else
	{
		draw_circle(p3,50,rouge);
	}
	// Fin du code
	
	wait_escape();
	exit(0);
}
