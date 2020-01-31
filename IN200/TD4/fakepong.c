#include "uvsqgraphics.h"

//indianred, dodgerblue, mediumspringgreen

struct balle
{
	POINT centre;
	int rayon;
	COULEUR coul;
	int dx, dy;
};

typedef struct balle BALLE;

struct raket
{
	POINT bg, hd;
	int largeur, hauteur;
	COULEUR coul;
	//int dx;
};

typedef struct raket RAKET;


RAKET init_raket(RAKET R)
{
	R.largeur = 100; R.hauteur = 20;
	R.bg.x = WIDTH/2 - R.largeur/2; R.bg.y = 50;
	R.hd.x = WIDTH/2 + R.largeur/2; R.hd.y = R.bg.y + R.hauteur;
	R.coul = mediumspringgreen;
	//R.dx = 0;
	
	//R.bg.x = centre - largeur /2 
	
	return R;
}

void design(RAKET R)
{
	POINT centre;
	centre.x = R.bg.x + 2; centre.y = R.bg.y + R.hauteur/2;
	draw_fill_circle(centre, R.hauteur/2, mediumspringgreen); 
	centre.x += R.largeur - 4;
	draw_fill_circle(centre, R.hauteur/2, mediumspringgreen);
	
	R.hd.y -= 18; R.bg.x -= 3; R.hd.x += 3;
	draw_fill_rectangle(R.bg, R.hd, green); 
}

void affiche_raket(RAKET R)
{
	
	draw_fill_rectangle(R.bg, R.hd, R.coul);
	design(R);
}

void efface_raket(RAKET R)
{
	/*
	R.coul = black;
	R.bg.x -= 3; R.hd.x += 3;
	R.bg.y -=3; R.hd.y += 3;
	
	draw_fill_rectangle(R.bg, R.hd, R.coul); */
	
	POINT bg, hd;
	bg.x = R.bg.x - 10; bg.y = R.bg.y -10;
	hd.x = R.hd.x + 10; hd.y = R.hd.y +2;
	draw_fill_rectangle(bg,hd,black);
}

RAKET deplace_raket(RAKET R, int dx)
{
	
	R.bg.x += dx; 
	R.hd.x += dx;
	
	return R;
}

int recale_raket(RAKET R, int dx)
{
	
	if (R.bg.x <= 0 && dx < 0) dx = 0; 
	if (R.hd.x >= WIDTH && dx > 0)  dx = 0; 
	return dx;
}

// -------------------------

 BALLE init_balle(BALLE B)
{
	
	B.centre.x = 200; B.centre.y = 200;
	B.rayon = 10;
	B.coul = dodgerblue;
	return B; 
}

BALLE deplace_balle(BALLE B)
{
	B.centre.x += B.dx;
	B.centre.y += B.dy;
	return B;
}

void efface_balle(BALLE B)
{
	B.coul = noir;
	draw_fill_circle(B.centre,B.rayon,B.coul);
}

void affiche_balle(BALLE B)
{
	draw_fill_circle(B.centre,B.rayon,B.coul);
}

BALLE rebond_balle(BALLE B) // modifie dx et dy si la balle dépasse d'un bord
{
	// Bord droite
	if ((B.centre.x >= (WIDTH - B.rayon))||(B.centre.x <= B.rayon))		B.dx = -B.dx;
	if ((B.centre.y >= (HEIGHT - B.rayon))||(B.centre.y <= B.rayon)) 	B.dy = -B.dy;
	
	if ((B.centre.y + B.rayon) <= 90) B.dy = -B.dy;
	
	return B;
}




int main()
{
	init_graphics(500,400);
	
	BALLE B;
	B.dx = 2; B.dy = 1;
	B = init_balle(B);
	affiche_balle(B);
	
	RAKET R;
	R = init_raket(R);
	affiche_raket(R);
	
	
	
	affiche_auto_off();
	
	POINT p;
	while(1) {
		p.x = 0;
		//while (p.x == 0)
		p = get_arrow();
		printf("p.x = %d\n",p.x);
		
		int dx = 0;
		if (p.x > 0) dx = 1;
		if (p.x < 0) dx = -1;
		
		efface_balle(B);
		B = deplace_balle(B);
		affiche_balle(B);
		B = rebond_balle(B);
		
		
		efface_raket(R);
		
		//if (B.dx > 0) dx = B.dx +1;
		//if (B.dx < 0) dx = B.dx +1;
		dx = B.dx;
		dx = recale_raket(R, dx);
		
		R = deplace_raket(R, dx);
		// LA ON DOIT TESTER SI ELLE TOUCHE LECRAN OU NON POUR LA RECALE
		
		affiche_raket(R);
		
		attendre(3);
		affiche_all();
	}
	
						
	
	
	wait_escape();
	exit(0);
}
