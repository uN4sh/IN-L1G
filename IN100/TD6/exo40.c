#include "uvsqgraphics.h"

int main()
{
	init_graphics(600,400);

	// Debut du code
	
	POINT bg, hd;
	int min, max, imin, imax;
	int T[20];
	int i;
	
	imin = 0; imax = 0;
	min = 100; max = 0;
	
	bg.y = 50;
	for (i=0 ; i<20 ; i=i+1) 
	{
		T[i] = alea_int(100); 
		bg.x = 100 + (20*i);
		hd.x = 100 + 20*i + 19;
		hd.y = 50 + 3*T[i];
		
		draw_fill_rectangle(bg, hd, blue);
		
		if (T[i] < min) //min est à 100 au début
		{ // si la valeur aléa est plus ptite que 100, ca devient le new min
			min = T[i];
			imin = i; //du coup on save le i minimum
		}
		if (T[i] > max)
		{ //pareil pour max
			max = T[i];
			imax = i;
		}
	}
	//et on rajoute des rectangles avec les imin et min 
	bg.x = 100 + (20* imin);
	hd.x = 100 + 20*imin +19;
	hd.y = 50 + 3*min;
	draw_fill_rectangle(bg, hd, blanc);
	
	bg.x = 100 + (20* imax);
	hd.x = 100 + 20*imax +19;
	hd.y = 50 + 3*max;
	draw_fill_rectangle(bg, hd, blanc); 
	// Fin du code

	wait_escape();
	exit(0);
}
