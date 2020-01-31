#include "uvsqgraphics.h"

//indianred, dodgerblue, mediumspringgreen

#define LARGEUR 8
#define HAUTEUR 12

COULEUR B[LARGEUR][HAUTEUR];

int score;
int dark = 0;

COULEUR couleur_aleatoire();
void init_boules();

void affiche_quadrillage();
void affiche_boules();
void affiche_score(COULEUR coul);
void affiche();

int mettre_a_noir(COULEUR coul, int i, int j);
void gestion_clic();

int test_ensemble(COULEUR coul, int i, int j);

void descendre_colonne();
void deplacement_droite();

int test_colonne(int i);

int main()
{
	init_graphics(600,930);
	
	affiche();
	
	affiche_auto_off();
	while(1) {
	
	gestion_clic();
	
	affiche_all();
	}
	
	wait_escape();
	exit(0);
}


COULEUR couleur_aleatoire()
{
	// Tire une couleur aléatoire entre le jaune, rouge, bleu et vert
	int a;
	a = alea_int(4);
	
	COULEUR coul;
	
	if (a == 0) 	coul = indianred;
	if (a == 1) 	coul = dodgerblue;
	if (a == 2) 	coul = gold;
	if (a == 3) 	coul = citronvert;
	
	return coul;
}

void init_boules()
{
	// initialise le tableau B avec des boules colorées
	int i,j;
	
	for (i = 0; i < LARGEUR; i++)
	{
		for (j = 0; j < HAUTEUR; j++)
		{
			B[i][j] = couleur_aleatoire();
		}	
	}	
}

void affiche_quadrillage()
{
	POINT b,g,h,d;
	
	b.y = 0; h.y = HEIGHT -30;
	g.x = 0; d.x = WIDTH;
	
	for (b.x = 0; b.x < WIDTH; b.x += WIDTH/LARGEUR)
	{
		h.x = b.x;
		draw_line(b,h,blanc);
	}	
	
	for (g.y = 0; g.y <= HEIGHT-30; g.y += (HEIGHT-30)/HAUTEUR)
	{
		d.y = g.y;
		draw_line(g,d,blanc);	
	}	
}

void affiche_boules()
{
	int i,j;
	POINT c;
	affiche_auto_off();
	for (i = 0; i < LARGEUR; i++)
	{
		for (j = 0; j < HAUTEUR; j++)
		{
			c.x = i*(WIDTH/LARGEUR) + (WIDTH/LARGEUR)/2;
			c.y = j*((HEIGHT-30)/HAUTEUR) + ((HEIGHT-30)/HAUTEUR)/2;
			draw_fill_circle(c,((HEIGHT-30)/HAUTEUR)/2 ,B[i][j]);
			affiche_all();
		}	
	}	
	affiche_auto_on();
}

void affiche_score(COULEUR coul)
{
	POINT bg,hd;
	bg.x = 0; bg.y = 901;
	hd.x = 600; hd.y = 930;
	draw_fill_rectangle(bg,hd,noir);
	
	POINT p;
	p.x = 480; p.y = 929;
	aff_pol("Score :", 20, p, coul);
	p.x = 560;
	aff_int(score, 20, p, coul);
	
	p.x = 300; p.y = 915;
	int a;
	a=alea_int(8);
	if(a==0)	aff_pol_centre("pov' con", 20, p, indianred);
	if(a==1)	aff_pol_centre("sombre merde", 20, p, antiquewhite);
	if(a==2)	aff_pol_centre("gros porc", 20, p, dodgerblue);
	if(a==3)	aff_pol_centre("enculer", 20, p, blanc);
	if(a==4)	aff_pol_centre("carotte", 20, p, orange);	
	if(a==5)	aff_pol_centre("sale abruti", 20, p, mediumspringgreen);
	if(a==6)	aff_pol_centre("mongole", 20, p, blanc);
	if(a==7)	aff_pol_centre("triceratopz", 20, p, gold);
	
	/* ** FILTRE DE LANGAGE ** */
	hd.x = 470;
	draw_fill_rectangle(bg,hd,noir);
	if(a==0)	aff_pol_centre("Yeaaah !", 20, p, indianred);
	if(a==1)	aff_pol_centre("Oh pas ouf la..", 20, p, antiquewhite);
	if(a==2)	aff_pol_centre("Wonderful!", 20, p, dodgerblue);
	if(a==3)	aff_pol_centre("Awesome!", 20, p, blanc);
	if(a==4)	aff_pol_centre("Trql trql..", 20, p, orange);	
	if(a==5)	aff_pol_centre("pingouin", 20, p, mediumspringgreen);
	if(a==6)	aff_pol_centre("Wow!", 20, p, blanc);
	if(a==7)	aff_pol_centre("Fouuu !", 20, p, gold); 
	
}

void affiche()
{
	affiche_quadrillage();
	init_boules();
	affiche_boules();
	affiche_score(indianred);
}

/* ************** */
/* ** VRAI JEU ** */
/* ************** */

int mettre_a_noir(COULEUR coul, int i, int j) 
{
	// La fonction s'appelle en boucle si les cases voisines sont de la meme couleurs
	int n = 0;
	
	if (i == 100) return 0;
	
	if (B[i][j] == coul) {	
		
		B[i][j] = noir;
		n++;
		
		
		if(i > 0 /*&& B[i-1][j] == coul*/)				n += mettre_a_noir(coul, i-1, j);
		if(j > 0 /*&& B[i][j-1] == coul*/) 				n += mettre_a_noir(coul, i, j-1);
		if(i < LARGEUR-1 /*&& B[i+1][j] == coul*/) 		n += mettre_a_noir(coul, i+1, j);
		if(j < HAUTEUR-1 /*&& B[i][j+1] == coul*/) 		n += mettre_a_noir(coul, i, j+1);
		
		return n;
	}
	
	else return 0;
}

// Probleme aux clics sur la ligne du dessus j=11, ca suit à celle i+1 et j=0
// Du coup fallait faire j<11 et pas 12

void gestion_clic()
{
	POINT p;
	p = wait_clic();
	
	int i, j;
	int ensemble;
	
	
	COULEUR memoire;
	
	if (p.y < 900) { 
		i = p.x / 75; 
		j = p.y / 75;
		
		printf("i : %d  j : %d\n", i,j);
		memoire = B[i][j];
		
		ensemble = test_ensemble(memoire, i, j);
		
		if (ensemble == 1 && memoire != noir) {
			score += mettre_a_noir(memoire, i, j);
			descendre_colonne();
			
			deplacement_droite();
			
			attendre(100);
			affiche_boules();
			affiche_score(indianred);
		}
	}
	
	if (p.y > 900 && p.x > 500)	{
		affiche_auto_off();
		if (dark == 1) {
			fill_screen(black);
			affiche_boules();
			affiche_quadrillage();
			affiche_score(indianred);
		}
		else {
			fill_screen(white);
			affiche_boules();
			affiche_score(dodgerblue);
			
		}
		dark = 1 - dark;
		affiche_all();
		printf("dark = %d\n", dark);
	}
}

int test_ensemble(COULEUR coul, int i, int j)
{
	if(i > 0 && B[i-1][j] == coul) 			return 1;
	if(j > 0 && B[i][j-1] == coul)			return 1;
	if(i < LARGEUR && B[i+1][j] == coul) 	return 1;
	if(j < HAUTEUR && B[i][j+1] == coul) 	return 1;
		
	return 0;
}

void descendre_colonne()
{
	// Les groupes de boules tombent dans les espaces vides (noirs)
	int i,j;
	
	for (i = 0; i < LARGEUR; i++)
	{
		for (int k= 0; k < HAUTEUR-1; k++)
		{
		
			for (j = 0; j < HAUTEUR - 1; j++)
			{
				if (B[i][j] == noir ) {
					B[i][j] = B[i][j+1];
					B[i][j+1]=noir;				
				}
			}
		}
	}
}


int test_colonne(int i)
{
	// Test si une colonne est vide
	int j, k = 0;
	for (j = 0; j < HAUTEUR; j++)
	{
		if (B[i][j] == noir)
		{
			k++;
		}
	}
	
	if (k == HAUTEUR) return 100;
	else return 0;
}

void deplacement_droite()
{
	// SI elle est vide, déplace toute la derniere colonne à droite
	int i,j;
	
	for (int k = 0; k < LARGEUR; k++)
	{
		for (i = 1; i < LARGEUR; i++)
		{
			if (test_colonne(i) == 100) {
				for (j = 0; j < HAUTEUR; j++)
				{
					B[i][j] = B[i-1][j];
					B[i-1][j]=noir;	
				}
			}
		}
	}
	
	
}

