#include "uvsqgraphics.h"

//indianred, dodgerblue, mediumspringgreen

COULEUR T1[256];

void remplir_gris(int i)
{
	// Remplis la i ème case du tableau avec une couleur (i,i,i)
	COULEUR couleur_RGB(int r, int g, int b);
	T1[i] = couleur_RGB(i,i,i);
}

void affiche_horizontal()
{
	// Affiche le tableau en rectangle avec chaque 2px la couleur T[i]
	int i;
	POINT bg, hd;
	bg.y = 0; hd.y = HEIGHT;
	
	for (i = 0; i < 256; i++)
	{
		bg.x = 2*i; hd.x = 2*i + 2;
		draw_rectangle(bg,hd,T1[i]);
	}
	
}


int main()
{
	init_graphics(512,512);

	// Debut du code
	int i;
	
	for (i = 0; i < 256; i++)
	{
		remplir_gris(i);
	}
	
	affiche_horizontal();
	
	// Fin du code

	wait_escape();
	exit(0);
}
