#include "uvsqgraphics.h"

int main()
{
	

	// Debut du code
	
	int taille;
	int n;
	POINT C;
	int R;
	taille = 200;
	init_graphics(taille,taille);
	
	C.x = 100; C.y = 100;
	R = 10;
	draw_circle(C, R, jaune);
	
	n=0;
	
	while (R < 100)
	{
		R = R + 10;
		if (n%2==0)
			draw_circle(C, R, blanc);
		else
			draw_circle(C, R, jaune);

		n++;
	}
	
	// Fin du code
	
	wait_escape();
	exit(0);
}
