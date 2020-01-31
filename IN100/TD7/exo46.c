#include "uvsqgraphics.h"

COULEUR courante;
int i = 1;

void dessine_couleurs()
{
	POINT bg, hd;
	bg.y = 0; hd.y = 50;
	bg.x = 0; hd.x = 50;
	COULEUR coul[4];
	
	coul[0] = vert; coul[1] = rouge; coul[2] = blanc; coul[3] = jaune;
	int i = 0;
	int n = 0;
	
	while (n < 4)
	{
		draw_fill_rectangle(bg, hd, coul[i%4]);
		bg.x += 50;
		hd.x += 50;
		n++;
		i++;
	}
}

COULEUR choix_couleur(POINT p)
{
		if ((p.y < 50) && (p.x < 200))
		{
			if (p.x < 50)
				courante = vert;
				// sauvegarder vert
			else if (p.x < 100)
				courante = rouge;
				// sauvegarder rouge
				else if (p.x < 150)
					courante = blanc;
					// sauvegarder blanc
					else 
					courante = jaune;
					// sauvegarder jaune
		}
		else 
			courante = noir;
		return courante;
}

void dessine_cercle(POINT c)
{
	draw_circle(c, 100, courante);
	i++;
}

int main()
{
	init_graphics(600,600);

	// Debut du code
	POINT p;
	
	
	dessine_couleurs();
	
	p = wait_clic();
	while (i < 21)
	{	
		while ((p.y < 50) && (p.x < 200))
		{
			choix_couleur(p); //return courante
			p = wait_clic();
		}
		
		dessine_cercle(p);
		p = wait_clic();
	}		
	
	// Fin du code

	wait_escape();
	exit(0);
}
