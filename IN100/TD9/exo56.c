#include "uvsqgraphics.h"

void echiquier()
{
	POINT BG, HD;
	COULEUR coul;
	int i, j, n;
	
	BG.x = 0; BG.y = 0;
	HD.x = 100; HD.y = 100;
	
	i = 0; j = 0; n = 0;
	while (j < 8)
	{
		while (i < 8)
		{
			if (n % 2 == 0)
				coul = blanc;
			else
				coul = jaune;
			
			draw_fill_rectangle(BG, HD, coul);
			
			n++;
			i++;
			BG.x += 100; HD.x += 100;
		}
		
		if (j % 2 == 0)
			n = 1;
		else
			n = 0;
			
		i = 0;
		j++;
		BG.x = 0; HD.x = 100;
		BG.y += 100; HD.y += 100;
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
