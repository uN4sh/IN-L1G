#include "uvsqgraphics.h"

struct balle
{
	POINT centre;
	int rayon;
	COULEUR coul;
	int dx, dy;
};

typedef struct balle BALLE;

BALLE deplace_balle(BALLE B)
{
	B.centre.x+=B.dx;
	B.centre.y+=B.dy;
	return B;
}
void efface_balle(BALLE B)
{
	draw_fill_circle(B.centre,B.rayon,noir);
}
void affiche_balle(BALLE B)
{
	draw_fill_circle(B.centre,B.rayon,B.coul);
}
BALLE rebondir(BALLE B)
{
	if(B.centre.x+B.rayon>=WIDTH || B.centre.x-B.rayon<=0) B.dx=-B.dx;
	if(B.centre.y+B.rayon>=HEIGHT || B.centre.y-B.rayon<=0) B.dy=-B.dy;
	return B;
}

void affiche_balles_aleatoire(int n)
{
	BALLE T[n];
	int i;
	
	for(i=0;i<n;i++)
	{
		T[i].centre.x=alea_int(200)+100;
		T[i].centre.y=alea_int(200)+100;
		T[i].rayon=alea_int(25)+5;
		T[i].coul=couleur_RGB(alea_int(256),alea_int(256),alea_int(256));
		T[i].dx=alea_int(10)-5;
		T[i].dy=alea_int(10)-5;
	}
	
	affiche_auto_off();
	
	while(1)
	{
		for(i=0;i<n;i++)
		{
			efface_balle(T[i]);
			T[i]=rebondir(T[i]);
			T[i]=deplace_balle(T[i]);
			affiche_balle(T[i]);
			attendre(1);
		}
		affiche_all();
	}
}
int main()
{
	init_graphics(800,800);
	
	affiche_balles_aleatoire(100);
	
	wait_escape();
	return 0;
}
