#include "uvsqgraphics.h"

int main()
{
	init_graphics(500,500);

	// Debut du code
	POINT BG, HD;
	COULEUR coul;
	int i, j, n;
	
	BG.x = 0; BG.y = 0;
	HD.x = 50; HD.y = 50;
	
	i = 0; j = 0; n = 0;
	while (j < 10)
	{
		while (i < 10)
		{
			if (n % 2 == 0)
			{
				coul = blanc;
				draw_fill_rectangle(BG, HD, coul);
			}
			else
			{
				coul = jaune;
				draw_fill_rectangle(BG, HD, coul);
			}
			n++;
			i++;
			BG.x += 50; HD.x += 50;
		}
		
		if (j % 2 == 0)
			n = 1;
		else
			n = 0;
			
		i = 0;
		j++;
		BG.x = 0; HD.x = 50;
		BG.y += 50; HD.y += 50;
	}
	
	// Fin du code

	wait_escape();
	exit(0);
}
