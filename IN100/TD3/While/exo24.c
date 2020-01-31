#include "uvsqgraphics.h"

int main()
{
	

	// Debut du code
	
	int taille;
	POINT C;
	int R;
	taille = 200;
	init_graphics(taille,taille);
	
	C.x = 100; C.y = 100;
	R = 10;
	draw_circle(C, R, jaune);
	
	while (R < 100)
	{
		R = R + 10;
		draw_circle(C, R, blanc);
	}
	
	// Fin du code
	
	wait_escape();
	exit(0);
}
