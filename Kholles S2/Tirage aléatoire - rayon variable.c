#include "uvsqgraphics.h"

//indianred, dodgerblue, mediumspringgreen

// Balle rebondit
// Chaque déplacement, tirage aléatoire en 100, si inférieur à 5 : balle stop
// Attend un clic quand balle est stop
// Si clic dans la balle, rayon diminue de 5, balle démarre 
// Si clic dehors de la balle, rayon augmente de 5, balle démarre
// Programme stop quand 30 rebonds
// w tahia eldjazair 

int rebonds = 0;

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
	
	B.centre.x = 100; B.centre.y = 200;
	B.rayon = 60;
	B.dx = 10; B.dy = 5;
	B.coul = blanc;
	return B; 
}

BALLE deplace_balle(BALLE B)
{
	POINT clic;
	
	if (alea_int(100) < 5) {
		//B.dx = 0;
		//B.dy = 0;
		clic = wait_clic();
		if (distance(clic, B.centre) < B.rayon) 	B.rayon -= 5;
		else 										B.rayon += 5;
	}
	
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
	if ((B.centre.x >= (WIDTH - B.rayon))||(B.centre.x <= B.rayon))	{
		B.dx = -B.dx;
		rebonds += 1;
		printf("rebonds = %d", rebonds);
		}
	if ((B.centre.y >= (HEIGHT - B.rayon))||(B.centre.y <= B.rayon)) {
		B.dy = -B.dy;
		rebonds += 1;
		printf("rebonds = %d", rebonds);
		}
	return B;
}


int main()
{
	init_graphics(600,600);

	// Debut du code
	BALLE B;
	
	B = init_balle(B);
	affiche_auto_off();
	
	while(rebonds < 30)
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
