#include "uvsqgraphics.h"

int main()
{
	init_graphics(512,512);

	// Debut du code
	POINT G, D;
	int i;
	int r, g, b;
	COULEUR couleur_RGB(int r, int g, int b);
	
	r = 0;
	g = 0;
	b = 0;
	
	G.x = 0; G.y = 0;
	D.x = 512; D.y = 2;
	
	i = 0;
	
	while (i < 256)
	{
		r = i;
		g = i;
		b = i;
		
		draw_fill_rectangle(G, D, couleur_RGB(r,g,b));
		
		G.y += 2;
		D.y += i*2;
		
		i += 1;
	}
	
	// Fin du code

	wait_escape();
	exit(0);
}
