#include "uvsqgraphics.h"

int plateau[8][8]; //Qui va stocker les couleurs

POINT c;

void bloc(POINT BG, POINT HD, COULEUR coul) // Dessine case en fct de la couleur
{
	POINT bg1, hd1;
	bg1.x = BG.x + 2; bg1.y = BG.y + 2;
	hd1.x = HD.x - 2; hd1.y = HD.y - 2;
	
	draw_fill_rectangle(BG, HD, gray);
	draw_fill_rectangle(bg1, hd1, coul);
}

void echiquier() //Dessine echiquier et stocke couleurs dans le tableau
{
	POINT BG, HD;
	COULEUR coul;
	int i, j, n;
	
	BG.x = 0; BG.y = 0;
	HD.x = (WIDTH/8); HD.y = (WIDTH/8);
	
	n = 0;
	
	for(j=0; j<8; j++) {
		for(i=0; i<8; i++) {
			
			if (n % 2 == 0) {
				coul = blanc;
				plateau[i][j] = 0;
			}
			else {
				coul = noir;
				plateau[i][j] = 1;
			}

			bloc(BG, HD, coul);
			//draw_fill_rectangle(BG, HD, coul);
			n++;
			BG.x += (WIDTH/8); HD.x += (WIDTH/8);
		}
		
		if (j % 2 == 0)		n = 1;
		else				n = 0;

		BG.x = 0; HD.x = (WIDTH/8);
		BG.y += (WIDTH/8); HD.y += (WIDTH/8);
	}
	
	c.x = 50; c.y = 50;
	draw_fill_circle(c, 45, magenta);
	
}

POINT calcul_centre(POINT p) // Quand on clic dans une case, ca donne le centre
{
	int i, j;
	
	i = p.x / (WIDTH/8);
	j = p.y / (WIDTH/8);
	
	c.x = i*(WIDTH/8) + (WIDTH/8)/2; c.y = j*(WIDTH/8) + (WIDTH/8)/2;
	
	return c;
}

void efface_ancien(POINT cp) { // Dessine cercle noir ou blanc sur l'ancien centre
	int i, j;
	POINT centre;
	COULEUR coul;
	
	i = cp.x / (WIDTH/8);
	j = cp.y / (WIDTH/8);
	centre.x = i*(WIDTH/8) + (WIDTH/8)/2; centre.y = j*(WIDTH/8) + (WIDTH/8)/2;
	
	if (plateau[i][j] == 0) 	coul = blanc;
	else 						coul = noir;
	
	draw_fill_circle(centre, 45, coul);
}

void bouge_pion(POINT p)
{
	//cercle rouge nouveau centre
	POINT cp; //c précédent
	cp = c;
	
	efface_ancien(cp);
	
	calcul_centre(p); //return c
	//echiquier();
	
	draw_fill_circle(c, 45, magenta);
}

int main()
{
	init_graphics(800,800);

	// Debut du code
	
	echiquier();
	
	POINT p;
	
	
	p = wait_clic();
	
	/*
	while (((p.x < c.x+50)&&(p.x > c.x-50)) || ((p.y < c.y+50)&&(p.y > c.y-50))) {
		// POUR LA TOUR
		bouge_pion(p);
		p = wait_clic();
	}
	*/
	
	//Deplacement diagonal :
	//SI elle est sur noire, ET le clic est sur noir, deplacer la bas
	if ((p.x/100)*100 
	
	// Fin du code

	wait_escape();
	exit(0);
}
