#include "uvsqgraphics.h"

//indianred, dodgerblue, mediumspringgreen

COULEUR T1[256];
COULEUR T2[512][512];
COULEUR T3[512][512];

void remplir_gris()
{
	// Remplis la i ème case du tableau avec une couleur (i,i,i)
	//COULEUR couleur_RGB(int r, int g, int b);
	int i;
	for (i = 0; i < 256; i++)
	
	T1[i] = couleur_RGB(i,i,i);
}

void remplir_rouge()
{
	int i;
	//COULEUR couleur_RGB(int r, int g, int b);
	for (i = 0; i < 256; i++)
	{
		T1[i] = couleur_RGB(i,0,0);
	}
	
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

void affiche_vertical()
{
	int i;
	POINT bg, hd;
	
	bg.x = 0; hd.x = WIDTH;
	
	for (i = 0; i < 256; i++)
	{
		bg.y = 2*i; hd.y = 2*i + 2;
		draw_rectangle(bg,hd,T1[i]);
	}
}

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
	
	for (i = 0; i < 256; i++)
	{
		for (j = 0; j < 512; j++)
		{
			bg.x = 2*i; bg.y = 2*j;
			hd.x = 2*i + 2; hd.y = 2*j + 2;
			draw_rectangle(bg,hd,bateau[i][j]);
		}
	}
}

void remplir_aleatoire() //Pour T3
{
	int i,j;
	int r,g,b;
	//COULEUR couleur_RGB(int r, int g, int b);
	
	for (i = 0; i < 512; i++)
	{
		for (j = 0; j < 512; j++)
		{
			r = alea_int(256);
			g = alea_int(256);
			b = alea_int(256);
			T3[i][j] = couleur_RGB(r,g,b);
		}
	}	
}


int main()
{
	init_graphics(512,512);

	// Debut du code
	affiche_auto_off();
	
	//remplir_gris();
	//remplir_rouge();
	remplir_rouge_bleu();
	
	//while (1)
	//{
		//remplir_aleatoire();
		//affiche_2D(T3);
		//affiche_all();
	//} 
	
	
	affiche_2D(T2);
	
	//affiche_horizontal();
	//affiche_vertical();
	
	affiche_all();
	// Fin du code

	wait_escape();
	exit(0);
}
