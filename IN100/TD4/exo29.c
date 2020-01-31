#include "uvsqgraphics.h"

int main()
{
	init_graphics(800,800);

	// Debut du code
	POINT H, B, P;
	
	
	B.x = 0; B.y = 0;
	H.x = 10; H.y = 10;
	draw_fill_rectangle(B, H, blanc);
	
	P = wait_clic();
	
	if ((P.x > 10)&&(P.y > 10))
	{
		while ((P.x > 10)&&(P.y > 10))
		{
			draw_circle(P, 100, rouge);
			P = wait_clic();
		}
	}
	else
		exit(0);
	
	// Fin du code
}
