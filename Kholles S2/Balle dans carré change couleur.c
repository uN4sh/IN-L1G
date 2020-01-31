#include "uvsqgraphics.h"

// largeur / 4, hauteur 50, rouge vert bleu jaune
// quand le CENTRE de la balle passe dans une zone, elle prend la couleur
// quand elle rebondit en haut, couleur devient blanc
// 30 rebonds fin
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
	B.rayon = 20;
	B.dx = 10; B.dy = 3;
	B.coul = blanc;
	return B; 
}

BALLE deplace_balle(BALLE B)
{
	B.centre.x += B.dx;
	B.centre.y += B.dy;
	
	return B;
}

BALLE couleur_balle(BALLE B)
{
	if ((B.centre.y) < 50) {
		if ((B.centre.x) > 0 && (B.centre.x) < 150)
			B.coul = rouge;
		if ((B.centre.x) > 150 && (B.centre.x) < 300)
			B.coul = vert;
		if ((B.centre.x) > 300 && (B.centre.x) < 450)
			B.coul = bleu;
		if ((B.centre.x) > 450 && (B.centre.x) < WIDTH)
			B.coul = jaune;
	}
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
	}
		
	if ((B.centre.y <= B.rayon)) {
		B.dy = -B.dy;
		rebonds += 1;
	}
		
	if ((B.centre.y >= (HEIGHT - B.rayon))) {
		B.dy = -B.dy;
		B.coul = blanc;
		rebonds += 1;
	}
		
	return B;
}

void carres()
{
	
	POINT bg, hd;
	
	bg.x = 0; bg.y = 0;
	hd.x = WIDTH/4; hd.y = 50;
	draw_fill_rectangle(bg, hd, rouge);
	
	bg.x = WIDTH/4; bg.y = 0;
	hd.x = 2*(WIDTH/4); hd.y = 50;
	draw_fill_rectangle(bg, hd, vert);
	
	bg.x = 2*(WIDTH/4); bg.y = 0;
	hd.x = 3*(WIDTH/4); hd.y = 50;
	draw_fill_rectangle(bg, hd, bleu);
	
	bg.x = 3*(WIDTH/4); bg.y = 0;
	hd.x = WIDTH; hd.y = 50;
	draw_fill_rectangle(bg, hd, jaune);
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
		carres();
		
		efface_balle(B);
		B = rebond_balle(B);
		B = deplace_balle(B);
		B = couleur_balle(B);
		affiche_balle(B);
		
		attendre(1);
		affiche_all();
	}
	// Fin du code

	wait_escape();
	exit(0);
}
