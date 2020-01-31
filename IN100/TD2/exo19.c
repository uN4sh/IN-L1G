#include "uvsqgraphics.h"

int main()
{
	init_graphics(600,600);

	// Debut du code
	POINT p1;
	POINT p2;
	POINT p3;

	p1.x = 200; p1.y = 600;
	p2.x = 200; p2.y = 0;
	draw_line(p1,p2,blanc);
	p1.x = 400; p1.y = 600;
	p2.x = 400; p2.y = 0;
	draw_line(p1,p2,blanc);
	// Ligne qui partage l'écran en 2
	
	p3 = wait_clic();
	
	/*if (p3.x < 200) 
	{
		draw_circle(p3, 50, bleu);
	}
	if ((p3.x > 200) && (p3.x < 400))
	{
		draw_circle(p3, 50, blanc);
	}
	if (p3.x > 400)
	{
		draw_circle(p3, 50, rouge);
	} */
	
	if (p3.x < 200) 
	{
		draw_circle(p3, 50, vert);
	}
	else if (p3.x < 400)
	{
		draw_circle(p3, 50, rouge);
	}
	else
	{
		draw_circle(p3, 50, blanc);
	}
	
	// Fin du code
	
	wait_escape();
	exit(0);
}
