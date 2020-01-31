#include "uvsqgraphics.h"

int main()
{
	init_graphics(400,400);

	// Debut du code
	POINT HG, HD, BG, BD;
	POINT HG2, HD2, BG2, BD2;
	int n;
	
	HG.x = 50; HG.y = 50;
	HD.x = HG.x; HD.y = 100;
	BG.x = 100; BG.y = 50;
	BD.x = BG.x; BD.y = 100;
	
	draw_line(HG, BD, blanc);
	draw_line(HD, BG, blanc);
	
	HG2.x = 40; HG2.y = 350;
	HD2.x = 90; HD2.y = HG2.y;
	BG2.x = 40; BG2.y = 300;
	BD2.x = 90; BD2.y = BG2.y;
	
	draw_line(HG2, BD2, blanc);
	draw_line(HD2, BG2, blanc);
	
	n = 0;
	while (n < 5)
	{
		HG.x += 55; HG.y += 55;
		HD.x += 55; HD.y += 55;
		BG.x += 55; BG.y += 55;
		BD.x += 55; BD.y += 55;
		
		draw_line(HG, BD, blanc);
		draw_line(HD, BG, blanc);
		
		HG2.x += 55; HG2.y -= 55;
		HD2.x += 55; HD2.y -= 55;
		BG2.x += 55; BG2.y -= 55;
		BD2.x += 55; BD2.y -= 55;
		
		draw_line(HG2, BD2, blanc);
		draw_line(HD2, BG2, blanc);
		
		n += 1;
	}
	
	// Fin du code

	wait_escape();
	exit(0);
}
