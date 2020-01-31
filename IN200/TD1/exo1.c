#include "uvsqgraphics.h"

//indianred, dodgerblue, mediumspringgreen

void croixx(POINT bg, int longueur)
{
	POINT bd, hg, hd;
	bd.x = bg.x + longueur; bd.y = bg.y;
	hg.x = bg.x; hg.y = bg.y + longueur;
	hd.x = hg.x + longueur; hd.y = hg.y;
	
	draw_rectangle(bg,hd,mediumspringgreen);
	draw_line(bg,hd,mediumspringgreen);
	draw_line(bd,hg,mediumspringgreen);
}

void mur(POINT bg, int longueur, int nbl, int nbc)
{
	int i,j;
	
	for (i = 0; i < nbl; i++)
	{
		for (j = 0; j < nbc; j++)
		{
			croixx(bg,longueur);
			bg.x += longueur;
		}
		//bg.x doit revenir à 0
		bg.x = bg.x - longueur*nbc;
		bg.y += longueur;
	}
}


int main()
{
	init_graphics(600,600);

	// Debut du code
	
	POINT bg; int lg; int nbl; int nbc;
	lg = lire_entier_clavier();
	nbl = lire_entier_clavier();
	nbc = lire_entier_clavier();
	bg = wait_clic();
	
	mur(bg, lg, nbl, nbc);
	
	// Fin du code

	wait_escape();
	exit(0);
}
