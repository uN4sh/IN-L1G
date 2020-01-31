#include "uvsqgraphics.h"

int main()
{
	init_graphics(512,512);

	// Debut du code
	POINT BG, HD;
	int i, j;
	int r, g, b;
	COULEUR couleur_RGB(int r, int g, int b);
	
	r = 0;
	g = 0;
	b = 0;
	
	BG.x = 0; BG.y = 0;
	HD.x = 2; HD.y = 2;
	
	i = 0; j = 0;
	
	while (j < 256)
	{
		while (i < 256)
		{
			r = i;
			g = 0;
			b = j;
			draw_fill_rectangle(BG, HD, couleur_RGB(r,g,b));
			
			BG.x += 2*i; HD.x += 2;
			
			i++;
		}
		i = 0;
		BG.x = 0; HD.x = 2;
		BG.y += 2; HD.y += 2;
		j++;
	}
	
	// Fin du code

	wait_escape();
	exit(0);
}
