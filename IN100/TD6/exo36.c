#include "uvsqgraphics.h"

int main()
{
	init_graphics(600,400);

	// Debut du code

	int i;
	POINT TP[10];

	i = 0;
	
	while (i < 10)
	{	
		TP[i] = wait_clic();
		draw_circle(TP[i], 30, rouge);
		i++;
	}
	
	i = 0;
	wait_clic();
	while (i < 10)
	{
		
		draw_circle(TP[i], 30, bleu);
		i++;
	}

	// Fin du code

	wait_escape();
	exit(0);
}
