#include "uvsqgraphics.h"

void separation_verticale()
{
	int i = 0;
	POINT b, h;
	b.y = 0; h.y = HEIGHT;
	b.x = WIDTH/3; h.x = WIDTH/3; 
	
	while (i<3)
	{
		draw_line(b,h,blanc);
		b.x += WIDTH/3; h.x += WIDTH/3; 
		i++;
	}
}

int main()
{
	init_graphics(600,600);

	// Debut du code
	
	separation_verticale();
	int n = 0, m = 0, t = 0;
	POINT p;
// 3 cadrans, dans chaque cadran : 
// premier clic colorie, deuxieme efface
	POINT bg, hd;
	bg.y = 0, hd.y = WIDTH;
	
	p = wait_clic();
	
	while(n>=0)
	{
		if (p.x > 400)
		{
			bg.x = 400; hd.x = 600;
			if (n % 2 == 0)
				draw_fill_rectangle(bg,hd,rouge);
			else
				draw_fill_rectangle(bg,hd,noir);
			n++;
		}
		else if (p.x > 200)
			{
				bg.x = 200; hd.x = 400;
				if (m % 2 == 0)
					draw_fill_rectangle(bg,hd,blanc);
				else
					draw_fill_rectangle(bg,hd,noir);
				m++;
			}
			else
			{
				bg.x = 0; hd.x = 200;
				if (t % 2 == 0)
					draw_fill_rectangle(bg,hd,bleu);
				else
					draw_fill_rectangle(bg,hd,noir);
				t++;
			}
		p = wait_clic();
	}
	
	// Fin du code

	wait_escape();
	exit(0);
}
