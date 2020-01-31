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
	POINT p, c;
	//c centre precedent
	c.x = 0;
	
	while(i<20)
	{
// si clic gauche, cercle rouge
// si droite ET precedent droite aussi, cercle bleu
// si droite ET precedent gauche, rien
		p = wait_clic();
		if (p.x < WIDTH/2)
		{
			draw_circle(p, 100, rouge);
		}
		else
		{
			if (c.x > WIDTH/2)
				draw_circle(p, 100, bleu);
		}
		c = p;
	}
	
	// Fin du code

	wait_escape();
	exit(0);
}
