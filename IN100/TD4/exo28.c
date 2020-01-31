#include "uvsqgraphics.h"

int main()
{
	init_graphics(800,800);

	// Debut du code
	POINT H, B, P;
	int n;
	
	H.y = 800; B.y = 0;
	H.x = WIDTH/2; B.x = H.x;
	draw_line(B, H, blanc);
	n=0;
	
	while (n < 5)
	{
		P = wait_clic();
		if (P.x < (WIDTH/2))
			draw_circle(P, 100, rouge);
		else
			draw_circle(P, 100, bleu);
		
		n += 1;
	}
	
	// Fin du code

	wait_escape();
	exit(0);
}
