#include "uvsqgraphics.h"

//indianred, dodgerblue, mediumspringgreen
POINT P;
int i = 0; // i compteur bleu (clics à gauche) 
int j = 0; // j compteur rouge (clics à droite)
void separation()
{
	POINT b,h;
	b.x = WIDTH/2; b.y = 0;
	h.x = WIDTH/2; h.y = WIDTH;
	draw_line(b,h,white);
}

POINT symetrique(POINT P) 
{
	POINT p2;
	//Return le point symetrique par rapport à la droite D
	if (P.x > WIDTH/2) {
		p2.x = WIDTH/2 - (P.x - 300); // Milieu - distance Milieu / Point P
		j++;
	}
	else {
		p2.x = WIDTH/2 + (300 - P.x);
		i++;
	}
	
	p2.y = P.y;
	
	return p2;
}

void aff_sym(POINT P) {
	draw_circle(P,50,dodgerblue);
	P = symetrique(P);
	draw_circle(P,50,indianred);
}

int main()
{
	init_graphics(600,600);

	// Debut du code
	separation();
	
	while(i < j + 3) {
		P = wait_clic();
		aff_sym(P);
		write_text("i : "); write_int(i); //write_ln();
		write_text("         j : "); write_int(j); write_ln();
	}
	
	wait_escape();
	exit(0);
	
	// Fin du code
	
}
