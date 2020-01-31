#include "uvsqgraphics.h"

int haut_ou_bas;
int gauche_ou_droite;
int OU_CA;

void qui_dit_ou_c_est(POINT p)
{
	// 0 = bas, 1 = haut
	// 0 = gauche, 1 = droite
	if (p.x < WIDTH/2)
	{
		gauche_ou_droite = 0;
		if (p.y < HEIGHT/2)
			haut_ou_bas = 0;
		else 
			haut_ou_bas = 1;
	}
	else
	{
		gauche_ou_droite = 1;
		if (p.y < HEIGHT/2)
			haut_ou_bas = 0;
		else 
			haut_ou_bas = 1;
	}
}

void calcul_OU_CA()
{
	if (haut_ou_bas == 0) 
	{
		if (gauche_ou_droite == 0)
			OU_CA = 0;
		else
			OU_CA = 1;
	}
	else
	{
		if (gauche_ou_droite == 0)
			OU_CA = 2;
		else
			OU_CA = 3;
	}
}

void dessine_cercle_couleur(POINT centre)
{
	if (OU_CA == 0)
		draw_circle(centre, 100, bleu);
	if (OU_CA == 1)
		draw_circle(centre, 100, rouge);
	if (OU_CA == 2)
		draw_circle(centre, 100, vert);
	if (OU_CA == 3)
		draw_circle(centre, 100, jaune);
}

int main()
{
	init_graphics(600,600);

	// Debut du code
	int i;
	POINT p;
	
	for (i = 0; i<20; i++)
	{
		p = wait_clic();
		qui_dit_ou_c_est(p);
		calcul_OU_CA();
		dessine_cercle_couleur(p);
	}
	// Fin du code

	wait_escape();
	exit(0);
}
