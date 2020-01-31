#include "uvsqgraphics.h"

//indianred, dodgerblue, mediumspringgreen
int vies = 3;
int rebonds = 0;

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

void interface()
{
	POINT bg, hd;
	bg.x = 0; bg.y = HEIGHT - 60;
	hd.x = WIDTH; hd.y = HEIGHT;
	draw_fill_rectangle(bg,hd,seashell);
	hd.y = HEIGHT - 58;
	draw_fill_rectangle(bg,hd,seagreen);
	
	POINT p;
	p.x = 20; p.y = HEIGHT - 17;
	pol_style(GRAS);aff_pol("Score :", 20, p, midnightblue);
	p.x = 113;
	aff_int(rebonds, 20, p, midnightblue);
	
	p.x = 270;
	aff_pol("Vies restantes :", 20, p, indianred);
	p.x = 465;
	aff_int(vies, 20, p, indianred);
}

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
	POINT bg, hd;
	bg.x = R.bg.x - 8; bg.y = R.bg.y ;
	hd.x = R.hd.x + 8; hd.y = R.hd.y ;
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

// ------------------------- BALLE

 BALLE init_balle(BALLE B)
{
	
	B.centre.x = WIDTH/2; B.centre.y = 90;
	B.rayon = 10;
	B.coul = dodgerblue;
	B.dx = 2; B.dy = 1;
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
	if ((B.centre.y >= (HEIGHT - 60 - B.rayon))) 	B.dy = -B.dy;
	
	if ((B.centre.y <= B.rayon)) 
	{ 
		vies = vies - 1;
		rebonds = 0;
		printf("Balles restantes = %d\n",vies);
		interface();
		attendre(600);
		efface_balle(B);
		B = init_balle(B);
		// On pourrait aussi réinitialiser la raket ?
	}
	// if ((B.centre.y + B.rayon) <= 90) B.dy = -B.dy; //fake rebond
	
	return B;
}


// ----------------------- FIN BALLE


int choc(BALLE B, RAKET R)
{
	// renvoie 1 si y'a intersection entre balle et raket, et 0 si non
	if (((B.centre.y - B.rayon) <= (R.hd.y)) 
	&& ((B.centre.x) >= R.bg.x) 
	&& ((B.centre.x) <= R.hd.x)) { 
		rebonds += 1; 
		printf("Boom = %d\n",rebonds);
		interface();
		return 1; 
		}
	
	if (((B.centre.y + B.rayon) <= (R.bg.y)) 
	&& ((B.centre.x) >= R.bg.x) 
	&& ((B.centre.x) <= R.hd.x)) return 1;
	
	
	if (((B.centre.x + B.rayon) >= (R.bg.x)) 
	&& (B.centre.y <= R.hd.y) && (B.centre.y >= R.bg.y)
	&& ((B.centre.x) >= R.bg.x) 
	&& ((B.centre.x) <= R.hd.x)) return 2;
	
	if (((B.centre.x - B.rayon) <= (R.hd.x)) 
	&& (B.centre.y <= R.hd.y) && (B.centre.y >= R.bg.y)
	&& ((B.centre.x) >= R.bg.x) 
	&& ((B.centre.x) <= R.hd.x)) return 2;
	
	else return 0;
}

BALLE recale_balle(BALLE B, RAKET R)
{
	int a;
	a = choc(B,R);
	
	if (a==1) B.dy = -B.dy;
	if (a==2) B.dx = -B.dx;
	
	return B;
}





int main()
{
	init_graphics(500,460);
	
	BALLE B;
	
	B = init_balle(B);
	affiche_balle(B);
	
	RAKET R;
	R = init_raket(R);
	affiche_raket(R);
	
	interface();
	
	affiche_auto_off();
	
	POINT p;
	while(1) {
		p.x = 0;
		//while (p.x == 0) //si tu actives ça, la balle est bloquée
		p = get_arrow();
		//printf("p.x = %d\n",p.x);
		int dx = 0;
			if (p.x > 0) dx = 1;
			if (p.x < 0) dx = -1;
		
		efface_balle(B);
		B = deplace_balle(B);
		affiche_balle(B);
		B = rebond_balle(B);
		
		efface_raket(R);
		dx = recale_raket(R, dx);
		R = deplace_raket(R, 3*dx);
		affiche_raket(R);
		
		B = recale_balle(B,R);
		
		if (vies == 0) wait_escape();
		
		
		attendre(3);
		affiche_all();
	}
	
						
	
	
	wait_escape();
	exit(0);
}
