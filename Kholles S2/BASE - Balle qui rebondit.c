#include "uvsqgraphics.h"

//indianred, dodgerblue, mediumspringgreen

struct balle
{
	POINT centre;
	int rayon;
	COULEUR coul;
	int dx, dy;
};

typedef struct balle BALLE;

BALLE init_balle(BALLE B)
{
	
	B.centre.x = 200; B.centre.y = 200;
	B.rayon = 60;
	B.coul = mediumspringgreen;
	return B; 
}

BALLE deplace_balle(BALLE B)
{
	B.centre.x += B.dx;
	B.centre.y += B.dy;
	return B;
}

void efface_balle(BALLE B)
{
	B.coul = black;
	draw_fill_circle(B.centre,B.rayon,B.coul);
}

void affiche_balle(BALLE B)
{
	draw_fill_circle(B.centre,B.rayon,B.coul);
}

BALLE rebond_balle(BALLE B) // modifie dx et dy si la balle dépasse d'un bord
{
	// Bord droite
	if ((B.centre.x >= (WIDTH - B.rayon))||(B.centre.x <= B.rayon))		B.dx = -B.dx;
	if ((B.centre.y >= (HEIGHT - B.rayon))||(B.centre.y <= B.rayon)) 	B.dy = -B.dy;
	return B;
}


int main()
{
	init_graphics(600,600);

	// Debut du code
	BALLE B;
	B.dx = 2; B.dy = 1;
	B = init_balle(B);
	affiche_auto_off();
	while(1) 
	{
		efface_balle(B);
		B = rebond_balle(B);
		B = deplace_balle(B);
		affiche_balle(B);
		
		attendre(1);
		affiche_all();
	}
	// Fin du code

	wait_escape();
	exit(0);
}
