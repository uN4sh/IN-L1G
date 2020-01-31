#include "uvsqgraphics.h"


POINT T[8][8];
int couleur[8][8];
//Tableau des centres des cases en partant d'en bas à droites
// Tableau de couleur, 0 = blanc, 1 = noir

POINT c;
int i,j;
COULEUR couleur_precedente;

void bloc(POINT BG, POINT HD, COULEUR coul) //Graphique
{
	POINT bg1, hd1;
	bg1.x = BG.x + 2; bg1.y = BG.y + 2;
	hd1.x = HD.x - 2; hd1.y = HD.y - 2;
	
	draw_fill_rectangle(BG, HD, gray);
	draw_fill_rectangle(bg1, hd1, coul);
}

void echiquier() //Dessine echiquier et stocke centres dans le tableau
{
	POINT BG, HD;
	COULEUR coul;
	int i, j, n;
	POINT centre;
	
	BG.x = 0; BG.y = 0;
	HD.x = 100; HD.y = 100;
	
	i = 0; j = 0; n = 0;
	while (j < 8)
	{
		while (i < 8)
		{
			if (n % 2 == 0) {
				coul = blanc;
				couleur[i][j] = 0;
			}
				
			else {
				coul = noir;
				couleur[i][j] = 1;
			}
			
			bloc(BG, HD, coul);
			//draw_fill_rectangle(BG, HD, coul);
			
			centre.x= BG.x + 50; centre.y = BG.y + 50;
			T[i][j] = centre;
			// T[0][0] = la case en bas à droite 
			// T[1][0] = celle juste à droite
			// T[0][1] = 2eme ligne en partant du bas, premiere case à droite
			
			n++;
			i++;
			BG.x += 100; HD.x += 100;
		}
		
		if (j % 2 == 0)
			n = 1;
		else
			n = 0;
			
		i = 0;
		j++;
		BG.x = 0; HD.x = 100;
		BG.y += 100; HD.y += 100;
	}
	
	
}

POINT calcul_centre(POINT p) // Quand on clic dans une case, ca donne le centre
{
	int i, j;
	
	// si la distance entre le clic et le centre de telle case < 50, donner le centre
	for (j=0; j<8; j++) {
		for (i=0; i<8; i++) {
			if (distance(p, T[i][j]) < 50)
				c = T[i][j];
		}
	}
	return c;
}

int calcul_couleur(POINT cp) // Donne les i j du centre précédent pour donner la couleur
{
	
	
	// si la distance entre le clic et le centre de telle case < 50, donner le centre
	for (j=0; j<8; j++) {
		for (i=0; i<8; i++) {
			if ((T[i][j].x == cp.x)&&(T[i][j].y == cp.y)) {
				return i;
				return j; }
		}
	}
}


void bouge_pion(POINT p)
{
	//retiens l'ancien centre
	//cercle noir ancien centre
	//cercle rouge nouveau centre
	POINT cp; //c précédent
	cp = c;
	
	calcul_centre(p); //return c
	//echiquier();
	calcul_couleur(cp); //return le i,j de cp
	if(couleur[i][j]==0)	draw_fill_circle(cp, 45, white);
	else	draw_fill_circle(cp, 45, noir);
	
	draw_fill_circle(c, 45, magenta);
}

int main()
{
	init_graphics(800,800);

	// Debut du code
	
	echiquier();
	
	POINT p;
	
	c.x = 50; c.y = 50;
	draw_fill_circle(c, 45, magenta);
	
	p = wait_clic();
	
	while (((p.x < c.x+50)&&(p.x > c.x-50)) || ((p.y < c.y+50)&&(p.y > c.y-50))) {
		// POUR LA TOUR
		bouge_pion(p);
		p = wait_clic();
	}
	
	// Fin du code

	wait_escape();
	exit(0);
}
