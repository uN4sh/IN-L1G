	7#include "uvsqgraphics.h"

int a_qui_de_jouer;


void quadrillage()
{
	POINT b, d, h, g;
	b.y = 0; b.x =0; h.y = 300; h.x = 0;
	g.x = 0; g.y = 0; d.x = 300; d.y = 0;
	
	while (b.x <= 300)
	{
		draw_line(b,h,blanc);
		draw_line(g,d,blanc);
		b.x += 100;
		h.x += 100;
		g.y += 100;
		d.y += 100;
	} 
}

void dessine_croix(POINT centre)
{
	POINT bg, hd, bd, hg;
	bg.x = centre.x - 50; bg.y = centre.y - 50;
	hd.x = centre.x + 50; hd.y = centre.y + 50;
	
	bd.x = centre.x + 50; bd.y = centre.y - 50;
	hg.x = centre.x - 50; hg.y = centre.y + 50;
	
	draw_line(bg, hd, blanc);
	draw_line(bd, hg, blanc);
}

void dessine_action(POINT p)
{
	// Calcule le centre d'une case ou y'a p
	int i=0;
	POINT c;
	
	while (i<3)
	{
		if ((p.y > 100*i) && (p.y < 100 + 100*i))
		{
			c.y = 50 + 100*i;
			if (p.x > 200)
				c.x = 250; 
			else if (p.x > 100)
				c.x = 150; 
			else
				c.x = 50; 
			// 3 abscisses 
		}
		i++;
	}
	
	// Et dessine une croix de centre p si = 0, et un rond si = 1
	if (a_qui_de_jouer == 0)
		dessine_croix(c);
	else
		draw_circle(c, 50, blanc);
}

int main()
{
	init_graphics(300,300);

	POINT p;
	int i;
	
	quadrillage();
	a_qui_de_jouer = 0;
	
	
	
	for(i=0; i<9; i++)
	{
		p = wait_clic();
		dessine_action(p);
		
		a_qui_de_jouer = 1 - a_qui_de_jouer;
	}
	// Fin du code

	wait_escape();
	exit(0);
}
