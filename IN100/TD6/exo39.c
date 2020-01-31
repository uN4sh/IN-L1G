#include "uvsqgraphics.h"

int main()
{
	init_graphics(600,400);

	// Debut du code
	
	POINT bg, hd;
	int T[20];
	int i;
	
	bg.y = 50;
	for (i=0 ; i<20 ; i=i+1) 
	{ 
		T[i] = alea_int(100); 
		bg.x = 100 + (20*i);
		
		hd.x = 100 + 20*i +19;
		hd.y = 50 + 3*T[i];
		
		draw_fill_rectangle(bg, hd, blue);
	}
	// Fin du code

	wait_escape();
	exit(0);
}
