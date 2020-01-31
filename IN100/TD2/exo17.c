#include "uvsqgraphics.h"

int main()
{
	init_graphics(600,600);

	// Debut du code
	POINT p1;
	POINT p2;
	POINT p3;

	p1.x = 300; p1.y = 600;
	p2.x = 300; p2.y = 0;
	draw_line(p1,p2,blanc);
	p1.x = 0; p1.y = 300;
	p2.x = 600; p2.y = 300;
	draw_line(p1,p2,blanc);
	// Ligne qui partage l'écran en 2
	// Vaut mieux appeler les points avec des trucs plus simples, genre H et B pour Haut et Bas 
	
	p3 = wait_clic();
	
	if ((p3.x > 300 && p3.y > 300) || (p3.x < 300 && p3.y < 300))
	{
		draw_circle(p3, 50, bleu);
	}
	else
	{
		draw_circle(p3, 50, rouge);
	}
	// Fin du code
	
	wait_escape();
	exit(0);
}
