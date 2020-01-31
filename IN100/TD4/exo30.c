#include "uvsqgraphics.h"

int main()
{
	init_graphics(400,400);

	// Debut du code
	POINT HG, HD, BG, BD;
	int n;
	
	HG.x = 50; HG.y = 50;
	HD.x = HG.x; HD.y = 100;
	BG.x = 100; BG.y = 50;
	BD.x = BG.x; BD.y = 100;
	
	draw_line(HG, BD, blanc);
	draw_line(HD, BG, blanc);
	
	n = 0;
	while (n < 5)
	{
		HG.x += 55; HG.y += 55;
		HD.x += 55; HD.y += 55;
		BG.x += 55; BG.y += 55;
		BD.x += 55; BD.y += 55;
		
		draw_line(HG, BD, blanc);
		draw_line(HD, BG, blanc);
		
		n += 1;
	}
	
	// Fin du code

	wait_escape();
	exit(0);
}
