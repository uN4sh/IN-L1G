#include "uvsqgraphics.h"

//indianred, dodgerblue, mediumspringgreen

struct balle
{
	POINT centre;
	int rayon;
	COULEUR coul;
	int dx, dy;
	int spawn;
};

typedef struct balle BALLE;


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

int gauche_droite(BALLE B)
{
	if (B.centre.x <= (WIDTH/2)) return 0; //gauche
	else return 1; //droite
	
}

BALLE rebond_balle(BALLE B) // modifie dx et dy si la balle dépasse d'un bord
{
	// Bord droite
	if ((B.centre.x >= (WIDTH - B.rayon))||(B.centre.x <= B.rayon))		B.dx = -B.dx;
	if ((B.centre.y >= (HEIGHT - B.rayon))||(B.centre.y <= B.rayon)) 	B.dy = -B.dy;
	//if (B.centre.x >= (200))	B.dx = -B.dx;
	
	
	if (B.spawn == 0 && B.dx>0) 
		{ if ((B.centre.x >= (WIDTH/2 - B.rayon)))	B.dx = -B.dx; } // Pour ceux nés à gauche
	if (B.spawn == 1 && B.dx<0)
		{ if (B.centre.x <= (WIDTH/2 + B.rayon))	B.dx = -B.dx; }
		
	return B;
}

void init_tableau(int n, BALLE T[n])
{
	int i;
	int o;
	for (i = 0; i < n; i++)
	{
		T[i].centre.x = alea_int(400) + 100; T[i].centre.y = alea_int(200) + 100;
		T[i].rayon = alea_int(35)+5;
		T[i].coul = couleur_RGB(alea_int(256),alea_int(256),alea_int(256));
		
		T[i].dx = alea_int(4) + 1; // Entre 1 et 5
		o = alea_int(1); // 0 ou 1
		if (o == 1) T[i].dx = - T[i].dx;
		
		T[i].dy = alea_int(10) - 5;
		o = alea_int(1); // 0 ou 1
		if (o == 1) T[i].dy = - T[i].dy;
		
		T[i].spawn = gauche_droite(T[i]);
	}
}

void balles(int n, BALLE T[n])
{
	int i;
	
	for (i = 0; i < n; i++) 
		{
			efface_balle(T[i]);
			T[i] = rebond_balle(T[i]);
			T[i] = deplace_balle(T[i]);
			affiche_balle(T[i]);	
		}
}

int main()
{
	init_graphics(800,800);
	
	affiche_auto_off();
	
	int n = 13;
	BALLE T[n];
	
	
	init_tableau(n, T);
	POINT b,h;
	b.x = WIDTH/2; b.y = 0; h.x = WIDTH/2; h.y = HEIGHT;
	draw_line(b,h,blanc);
	while(1) 
	{
		balles(n, T);
		attendre(5);
		affiche_all();
		draw_line(b,h,blanc);
	}

	wait_escape();
	exit(0);
}
