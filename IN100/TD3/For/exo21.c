#include "uvsqgraphics.h"

int main()
{
	int taille = 800;
	init_graphics(taille,taille);

	// Debut du code
	
	POINT H, B;
	POINT G, D;
	int i, delta;
	
	delta = lire_entier_clavier();
	
	H.x = 0; B.x = 0;
	H.y = 800; B.y = 0;
	G.x = 0; D.x = 800;
	G.y = 0; D.y = 0;
	
	/*
	for (i=0; i<800 ; i = i + delta)
	{
			H.x = H.x + delta;
			B.x = B.x + delta;
			draw_line(H, B, blanc);
			G.y = G.y + delta;
			D.y = D.y + delta;
			draw_line(G, D, blanc);
	}
	*/
	
	for (i=0; i<=taille/delta ; i = i + 1)
	{
			H.x = H.x + ((taille/delta)*i);
			B.x = B.x + ((taille/delta)*i);
			draw_line(H, B, blanc);
			G.y = G.y + ((taille/delta)*i);
			D.y = D.y + ((taille/delta)*i);
			draw_line(G, D, blanc);
	}
	
	// Fin du code
	
	wait_escape();
	exit(0);
}
