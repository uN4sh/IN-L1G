#include "uvsqgraphics.h"

int main()
{
	init_graphics(600,600);

	// Debut du code
	POINT p;
	p = wait_clic();
	
	if (p.x % 2 == 0) // Abs PAIRE
	{
		if (p.y % 2 == 0) //Or Paire / Impaire
			draw_circle(p, 50, rouge);
		else
			draw_circle(p, 50, bleu);
	}
	
	else // Abs IMPAIRE
	{
		if (p.y % 2 == 1) //Or Impaire / Paire
			draw_circle(p, 50, vert);
		else
			draw_circle(p, 50, jaune);
	}
	
	// Fin du code
	
	wait_escape();
	exit(0);
}
