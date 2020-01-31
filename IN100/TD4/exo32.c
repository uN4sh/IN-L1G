#include "uvsqgraphics.h"

int main()
{
	init_graphics(512,512);

	// Debut du code
	POINT B, H;
	int i;
	int r, g, b;
	COULEUR couleur_RGB(int r, int g, int b);
	
	r = 0;
	g = 0;
	b = 0;
	
	B.x = 0; B.y = 0;
	H.x = 2; H.y = 512;
	
	i = 0;
	
	while (i < 256)
	{
		r = i;
		g = i;
		b = i;
		
		draw_fill_rectangle(B, H, couleur_RGB(r,g,b));
		
		B.x += 2;
		H.x += 2;
		
		i += 1;
	}
	
	// Fin du code

	wait_escape();
	exit(0);
}
