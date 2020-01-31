#include "uvsqgraphics.h"

void separation_verticale()
{
	POINT b, h;
	b.x = WIDTH/2; b.y = 0;
	h.x = WIDTH/2; h.y = HEIGHT;
	draw_line(b,h,blanc);
}

int main()
{
	init_graphics(600,600);

	// Debut du code
	
	separation_verticale();
	
	int i = 0;
	POINT p;
	int n = 0;
	
	while(i<20)
	{
		p = wait_clic();
		if (p.x < WIDTH/2)
		{
			draw_circle(p, 100, rouge);
			n++;
		}
		if ((p.x > WIDTH/2) && (n>1))
			draw_circle(p, 100, bleu);
	}
	
	// Fin du code

	wait_escape();
	exit(0);
}
