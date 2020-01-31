#include "uvsqgraphics.h"

void echiquier()
{
	POINT BG, HD;
	COULEUR coul;
	int i = 0;
	
	BG.x = 0; BG.y = 0;
	HD.x = 100; HD.y = 100;
	
	for (i = 0; i < 64; i++)
	{
		if (((i%8) + (i/8)) % 2 == 1) 	coul = white;
		else 							coul = black;
		
		draw_fill_rectangle(BG,HD,coul);
		
		BG.x += 100;
		HD.x += 100;
		
		if (i%8 == 7)
		{
			BG.x = 0; BG.y += 100;
			HD.x = 100; HD.y += 100;
		}		
	}
}
	

int main()
{
	init_graphics(800,800);

	// Debut du code
	
	echiquier();
	
	// Fin du code

	wait_escape();
	exit(0);
}
