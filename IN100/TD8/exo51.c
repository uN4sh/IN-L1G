#include "uvsqgraphics.h"

POINT centre, centre_precedent;


void efface_affiche()
{
	draw_fill_circle(centre_precedent, 30, noir);
	draw_fill_circle(centre, 30, vert);
}

void plus_ou_moins(POINT p)
{
	// on attends un clic, si il est au dessus de y, centre + 2, si en dessous, centre - 2
	if (p.y > centre.y)
	{
		centre_precedent = centre; // .x et .y
		centre.y += 2;
	}
	else
	{
		centre_precedent = centre;
		centre.y -= 2;
	}
	
}

int main()
{
	init_graphics(400,400);
	POINT p;
	int i;

	centre_precedent.x = 0;
	centre_precedent.y = 0;
	
	centre.x = 200;
	centre.y = 200;
	
	
	for (i=0 ; i<200000 ; i++)
	{
		p = wait_clic();
		plus_ou_moins(p);
		efface_affiche();
	}


	wait_escape();
	exit(0);
}
