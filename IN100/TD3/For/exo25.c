#include "uvsqgraphics.h"

int main()
{
	
	init_graphics(800,800);
	// Debut du code
	
	POINT p1, p2;
	int n;
	
	p1.x = 100; p1.y = 100;
	p2.x = 700; p2.y = 700;
	draw_rectangle(p1, p2, blanc); 

	n = 1;
	
	while (n<=10)
	{
		wait_clic();
		
		if (n % 2 == 1)
			draw_fill_rectangle(p1, p2, blanc);
		else 
		{
			p1.x = 101; p1.y = 101;
			p2.x = 699; p2.y = 699;
			draw_fill_rectangle(p1, p2, noir);
		}
			
		n = n + 1;
		
	}
	
	// Fin du code
	
	wait_escape();
	exit(0);
}
