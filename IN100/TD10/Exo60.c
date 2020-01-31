#include "uvsqgraphics.h"

int plateau[10][10];
// WIDTH = 1000
// (WIDTH/10) = 100
// (WIDTH/10)/2 = 50

void dessine_jeton(int i, int j)
{
	// calcule la couleur et le centre de la case, et dessine le cercle
	COULEUR coul;
	POINT centre;
	
	if (plateau[i][j] == 0) coul = blanc;
	else 					coul = noir;
	
	centre.x = i*(WIDTH/10) + (WIDTH/10)/2; centre.y = j*(WIDTH/10) + (WIDTH/10)/2;
	draw_fill_circle(centre, (WIDTH/10)/2, coul);
}

void initialise_plateau()
{
	int i,j;
	POINT centre;
	COULEUR coul;
	
	for(j=0; j<10; j++) {
		for(i=0; i<10; i++) {
			
			centre.x = i*(WIDTH/10) + (WIDTH/10)/2; centre.y = j*(WIDTH/10) + (WIDTH/10)/2;
			
			if(alea_int(2) == 0) {coul = blanc; plateau[i][j] = 0;}
			else 				 {coul = noir; plateau[i][j] = 1;}
			
			draw_fill_circle(centre,(WIDTH/10)/2,coul);
		}
	}
}

void affiche_plateau()
{
	fill_screen(gris);
	initialise_plateau();
}

void modifie_plateau(POINT p) // toutes cases, bords et angles
{
	int i,j;
	
	i = p.x / (WIDTH/10);
	j = p.y / (WIDTH/10);
	
	plateau[i][j] = 1 - plateau[i][j];
	dessine_jeton(i,j);
	
		
	if (j==0) { // Bas
		j = j+1; //en haut [i][j+1]
		plateau[i][j] = 1 - plateau[i][j];
		dessine_jeton(i,j);
		if (i==0) { // Bas gauche
			j = j-1; i = i+1; //à droite [i+1][j]
			plateau[i][j] = 1 - plateau[i][j];
			dessine_jeton(i,j);
		}
		else if (i==9) { // Bas droite
			j = j-1; i = i-1; //à gauche [i-1][j]
			plateau[i][j] = 1 - plateau[i][j];
			dessine_jeton(i,j);
		}
		else { // Bas milieu
			j = j-1; i = i+1; //à droite [i+1][j]
			plateau[i][j] = 1 - plateau[i][j];
			dessine_jeton(i,j);
			
			i = i-2; //à gauche [i-1][j]
			plateau[i][j] = 1 - plateau[i][j];
			dessine_jeton(i,j);
		}
	}
	
	else if (j==9) { // Haut
		j = j-1; //en bas 
		plateau[i][j] = 1 - plateau[i][j];
		dessine_jeton(i,j);
		if (i==0) { // haut gauche
			j = j+1; i = i+1; //à droite [i+1][j]
			plateau[i][j] = 1 - plateau[i][j];
			dessine_jeton(i,j);
		}
		else if (i==9) { // Bas droite
			j=j+1; i = i-1; //à gauche [i-1][j]
			plateau[i][j] = 1 - plateau[i][j];
			dessine_jeton(i,j);
		}
		else { // haut milieu
			j=j+1; i = i+1; //à droite [i+1][j]
			plateau[i][j] = 1 - plateau[i][j];
			dessine_jeton(i,j);
			
			i = i-2; //à gauche [i-1][j]
			plateau[i][j] = 1 - plateau[i][j];
			dessine_jeton(i,j);
		}
	}
	
	if ((j!=0)&&(j!=9)) { // Milieu
		j = j-1; //en bas 
		plateau[i][j] = 1 - plateau[i][j];
		dessine_jeton(i,j);
		j = j+2; //en haut 
		plateau[i][j] = 1 - plateau[i][j];
		dessine_jeton(i,j);
		if (i==0) { // bord gauche
			j = j-1; i = i+1; //à droite [i+1][j]
			plateau[i][j] = 1 - plateau[i][j];
			dessine_jeton(i,j);
		}
		else if (i==9) { // bord droite
			j = j-1; i = i-1; //à gauche [i-1][j]
			plateau[i][j] = 1 - plateau[i][j];
			dessine_jeton(i,j);
		}
		else { // haut milieu
			j = j-1; i = i+1; //à droite [i+1][j]
			plateau[i][j] = 1 - plateau[i][j];
			dessine_jeton(i,j);
			
			i = i-2; //à gauche [i-1][j]
			plateau[i][j] = 1 - plateau[i][j];
			dessine_jeton(i,j);
		}
	}
	
	
}


int encore() 
{
	int i, j;
	int n=0;
	
	for(j=0; j<10; j++) {
		for(i=0; i<10; i++) {
			
			if (plateau[i][j] == 0) 	n+=1;
			else 						n-=1;
			
		} 
	}
	if ((n==100)||(n==-100))		return 0;
	else 							return 666;
	 // si tous les jetons sont différents de zéro ou 1
}


void jeu() 
{
	// if (encore = 0) OU (n<100)
	affiche_plateau();
	POINT p;
	int n = 0;
	
	while ((encore() == 666) && (n<100)){
		p = wait_clic();
		modifie_plateau(p);
		encore();
		n++;
	}
	
	wait_escape();
}

int main()
{
	init_graphics(800,800);
	
	jeu();

	wait_escape();
	exit(0);
}
