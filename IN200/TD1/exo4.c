#include "uvsqgraphics.h"

//indianred, dodgerblue, mediumspringgreen

void efface_affiche(POINT ancien, POINT nouveau)
{
	draw_fill_circle(ancien, 25, noir);
	draw_fill_circle(nouveau, 25, indianred);
}

POINT deplace_balle(POINT p, int dx, int dy)
{
	p.x += dx;
	p.y += dy;
	
	return p;
}

void affiche_balle(POINT p)
{
	draw_fill_circle(p, 25, mediumspringgreen);
}

void efface_balle(POINT p)
{
	draw_fill_circle(p, 25, noir);
}

POINT init_balle(int x, int y) {
	POINT p;
	p.x = x; p.y = y;
	return p;
}

int main()
{
	init_graphics(800,800);
	//affiche_auto_off();
	// Debut du code
	
	POINT p, courante;
	p = init_balle(0,0);
	
	while (p.x < WIDTH)
	{
		courante = p;
		efface_balle(courante);
		p = deplace_balle(p,2,2);
		affiche_balle(p);
				
		//nv.x = p.x + 2; nv.y = p.y + 2;
		//efface_affiche(p,nv);
		//p = nv;
		
		//affiche_all();
		//wait_clic();
		attendre(5);
	}
	
	// Fin du code
	wait_escape();
	exit(0);
}
