#include "uvsqgraphics.h"

//indianred, dodgerblue, mediumspringgreen

COULEUR T2[512][512];

void remplir_rouge_bleu()
{
	int i,j;
	//COULEUR couleur_RGB(int r, int g, int b);
	for (i = 0; i < 512; i++)
	{
		for (j = 0; j < 512; j++)
		{
			T2[i][j] = couleur_RGB(i,0,j);
		}
	}	
}

void affiche_2D(COULEUR bateau[512][512]) //A mettre soit pour T2 soit T3
{
	// Comment on met un tableau en argument pour pouvoir mettre soit T2 soit T3 ?
	int i,j;
	POINT bg, hd;
	
	for (i = 0; i < 512; i++)
	{
		for (j = 0; j < 512; j++)
		{
			bg.x = 2*i; bg.y = 2*j;
			hd.x = 2*i + 2; hd.y = 2*j + 2;
			draw_rectangle(bg,hd,bateau[i][j]);
		}
	}
}



int main()
{
	init_graphics(512,512);

	// Debut du code
	affiche_auto_off();
	
	
	remplir_rouge_bleu();

	
	affiche_2D(T2);

	
	affiche_all();

	wait_escape();
	exit(0);
}
