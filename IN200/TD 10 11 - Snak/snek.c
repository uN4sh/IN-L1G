#include "uvsqgraphics.h"

// Définition des différentes formes

#define VIDE 0
#define CERCLE 100
#define CARRE 101
#define CROIX 102

// Définition des types

struct elem {
  int i,j; // position sur le quadrillage de l'élément
  int forme; // vaut VIDE, CERCLE, CARRE ou CROIX
  COULEUR coul; // vaut bleu, rouge, jaune ou vert
};


struct serpent {
  int longueur; // nombre d'éléments dans le corps du serpent
  struct elem A[200]; // les éléments constitutifs du serpent
};

// Fonctions à écrire

void init_jeu(struct elem J[40][60])
{
	// Initialise le plateau de jeu avec éléments au hasard sur le plateau
	// alea pour i, j, forme et couleur
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			if (alea_int(2) == 1) { // Case pleine
				J[i][j].forme = 100 + alea_int(3); // 100 ou 101 ou 102
				if (alea_int(4) == 0)	J[i][j].coul = rouge;
				if (alea_int(4) == 1)	J[i][j].coul = jaune;
				if (alea_int(4) == 2)	J[i][j].coul = vert;
				if (alea_int(4) == 3)	J[i][j].coul = bleu;
			}
			else { // Case vide
				J[i][j].forme = 0; 
			}
		}
	}
}

struct serpent init_serpent()
{
	struct serpent S;
	
	return S;
}


void affiche_jeu(struct elem J[40][60])
{
	POINT c, bg, hd;
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			c.x = i*10 + 5; c.y = j*10 + 5;
			bg.x = i*10; bg.y = j*10; hd.x = bg.x + 10; hd.y = bg.y + 10;
			if(J[i][j].forme == 100)	draw_circle(c, 5, J[i][j].coul);
			if(J[i][j].forme == 101)	draw_rectangle(bg, hd, J[i][j].coul);
			if(J[i][j].forme == 102)	{draw_line(bg, hd, J[i][j].coul); bg.x += 10; hd.x -= 10; draw_line(bg, hd, J[i][j].coul);}
		}
	}
}

void affiche_serpent(struct serpent S)
{
	
}

int main()
{

  struct elem J[40][60];
  struct serpent S;

  init_graphics(400,600);
  init_jeu(J);
  S = init_serpent();
  affiche_jeu(J);
  affiche_serpent(S);

  wait_escape();
  exit(0);
}
