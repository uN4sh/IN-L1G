#include "uvsqgraphics.h"

int main()
{
	init_graphics(600,400);

	// Debut du code

	int i, dist, f;
	POINT TP[10], P;

	i = 0;
	
	//Cercles rouges
	while (i < 10)
	{	
		TP[i] = wait_clic();
		draw_circle(TP[i], 30, rouge);
		i++;
	}
	
	
	f = 0; //Compteur

	while (f < 10)
	{
		P = wait_clic();
		i = 0;
		
		while (i < 10)
		{
			dist = (sqrt(pow((P.x - TP[i].x),2) + pow((P.y - TP[i].y),2)));
			
			if (dist < 30)
			{
				draw_circle(TP[i], 30, noir);
				f++;
			}
			i++;
		}
		
	}
	// Fin du code

	wait_escape();
	exit(0);
}
