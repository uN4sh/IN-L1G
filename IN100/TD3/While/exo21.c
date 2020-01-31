#include "uvsqgraphics.h"

int main()
{
	init_graphics(800,1000);

	// Debut du code
	POINT H, B;
	POINT G, D;
	int delta;
	delta = lire_entier_clavier();
	
	H.x = 0; B.x = 0;
	H.y = HEIGHT; B.y = 0;
	G.x = 0; D.x = 800;
	G.y = 0; D.y = 0;
	
	while ((H.x < 800) || (G.y < HEIGHT))
	{
			H.x = H.x + delta;
			B.x = B.x + delta;
			draw_line(H, B, blanc);
			G.y = G.y + delta;
			D.y = D.y + delta;
			draw_line(G, D, blanc);
	}
	
	// Fin du code
	
	wait_escape();
	exit(0);
}
