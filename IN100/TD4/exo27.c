#include "uvsqgraphics.h"

int main()
{
	init_graphics(800,800);

	// Debut du code
	POINT H, B;
	int n;
	COULEUR coul;
	
	H.y = 800; B.y = 0;
	H.x = 100;
	n = 1;
	
	while (H.x <= 800)
	{
		B.x = H.x;
		if (n%2 == 1)
			coul = rouge;
		else
			coul = bleu;
		
		draw_line(B, H, coul);
		H.x = H.x + 100;
		n = n + 1;
	} 
	
	/*
	while (H.x <= 800)
	{
		B.x = H.x;
		if (n%2 == 1)
			draw_line(B, H, rouge);
		else
			draw_line(B, H, bleu);
		
		H.x = H.x + 100;
		n = n + 1;
	} */
	
	// Fin du code

	wait_escape();
	exit(0);
}
