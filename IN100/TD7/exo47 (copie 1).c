#include "uvsqgraphics.h"

void draw_pixel(COULEUR color)
{
	draw_rectangle(
}

void dessine_ellipse(POINT f1, POINT f2, int dist, COULEUR c)
{
	int dist1, dist2;
	POINT a;
	dist1 = (sqrt(pow((a.x - f1.x),2) + pow((a.y - f1.y),2)));
	dist2 = (sqrt(pow((a.x - f2.x),2) + pow((a.y - f2.y),2)));
	
	dist = dist1 + dist2;
	
	// ON CALCULE LA DISTANCE ENTRE FOYER ET POINT, ET DRAW PIXEL LA BAS 
}

int main()
{
	init_graphics(600,600);

	// Debut du code
	
	
	
	// Fin du code

	wait_escape();
	exit(0);
}
