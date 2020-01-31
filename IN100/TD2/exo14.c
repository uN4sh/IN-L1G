#include "uvsqgraphics.h"

int main()
{
	init_graphics(600,600);

	// Debut du code
	POINT p1;
	POINT p2;
	POINT p3;
	POINT p4;

	p1.x = p2.x = WIDTH/2; 
	p1.y = 600; p2.y = 0;
	draw_line(p1,p2,blanc);
	// Width = largeur, plus pratique que mettre des abscisses 
	// Et Height = Hauteur d'ailleurs
	// Ligne qui partage l'écran en 2
	
	p3 = wait_clic();
	
	if (p3.x > 300)
	{
		p4.x = (WIDTH/2) - (p3.x - 300); p4.y = p3.y;
		draw_circle(p4,50,bleu);
		// DONC milieu MOINS distance MID/P3
	}
	else
	{
		p4.x = (WIDTH/2) + (300 - p3.x); p4.y = p3.y;
		draw_circle(p4,50,rouge);
		// et la PLUS distance MID/P3
	}
	// Fin du code
	
	wait_escape();
	exit(0);
}
