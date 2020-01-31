#include "uvsqgraphics.h"

int plateau[10][10];
// WIDTH = 1000
// (WIDTH/10) = 100
// (WIDTH/10)/2 = 50

/*
 1/ Non, l'aléatoire ne l'assure pas à 100%
 2/ En initialisant une situation déjà gagnante (Toute blanche); et en faisant jouer l'ordi sur quelques clics pour créer l'aléatoire
 * La partie est donc gagnante à coup sûr car on peut faire les clics inverses de l'ordinateur
 3/ On peut calculer le nombre de clics que l'ordinateur à effectuer pour connaitre le nombre minimal 
*/

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
	
	if ((i!=0)&&(i!=9)&&(j!=0)&&(j!=9)) { // hors 4 bords
		i = i+1; //à droite [i+1][j]
		plateau[i][j] = 1 - plateau[i][j];
		dessine_jeton(i,j);
		
		i = i-2; //à gauche [i-1][j]
		plateau[i][j] = 1 - plateau[i][j];
		dessine_jeton(i,j);
		
		i = i+1; j = j+1; //en haut [i][j+1]
		plateau[i][j] = 1 - plateau[i][j];
		dessine_jeton(i,j);
		
		j = j-2; //en bas [i][j-1]
		plateau[i][j] = 1 - plateau[i][j];
		dessine_jeton(i,j);
	}
	
	if (i==9) { // droite
		i = i-1; //à gauche [i-1][j]
		plateau[i][j] = 1 - plateau[i][j];
		dessine_jeton(i,j);
		
		if (j==0) { // bas droite
			i = i+1; j = j+1; //en haut [i][j+1]
			plateau[i][j] = 1 - plateau[i][j];
			dessine_jeton(i,j);
		}
		else if (j==9) { // haut droite
			i = i+1; j = j-1; //en bas [i][j-1]
			plateau[i][j] = 1 - plateau[i][j];
			dessine_jeton(i,j);
			}
			else {
					i = i+1; j = j+1; // haut 
					plateau[i][j] = 1 - plateau[i][j];
					dessine_jeton(i,j);
					j = j-2; // bas 
					plateau[i][j] = 1 - plateau[i][j];
					dessine_jeton(i,j);
				}
		}
		
	if (i==0) { // gauche
		i = i+1; // droite
		plateau[i][j] = 1 - plateau[i][j];
		dessine_jeton(i,j);
		
		if (j==0) { // bas à gauche
			i = i-1; j = j+1; //en haut
			plateau[i][j] = 1 - plateau[i][j];
			dessine_jeton(i,j);
		}
		else if (j==9) { // haut à gauche
				i = i-1; j = j-1; //en bas
				plateau[i][j] = 1 - plateau[i][j];
				dessine_jeton(i,j);
				}
				else {
					i = i-1; j = j+1; // haut 
					plateau[i][j] = 1 - plateau[i][j];
					dessine_jeton(i,j);
					j = j-2; // bas 
					plateau[i][j] = 1 - plateau[i][j];
					dessine_jeton(i,j);
				}
	}
	
	if ((j==0)&&(i!=0)&&(i!=9)) { // bas
		i = i+1; //à droite [i+1][j]
		plateau[i][j] = 1 - plateau[i][j];
		dessine_jeton(i,j);
		
		i = i-2; //à gauche [i-1][j]
		plateau[i][j] = 1 - plateau[i][j];
		dessine_jeton(i,j);
		
		i = i+1; j = j+1; //en haut [i][j+1]
		plateau[i][j] = 1 - plateau[i][j];
		dessine_jeton(i,j);
	}
	
	if ((j==9)&&(i!=0)&&(i!=9)) { // haut
		i = i+1; //à droite [i+1][j]
		plateau[i][j] = 1 - plateau[i][j];
		dessine_jeton(i,j);
		
		i = i-2; //à gauche [i-1][j]
		plateau[i][j] = 1 - plateau[i][j];
		dessine_jeton(i,j);
		
		i = i+1; j = j-1; //en bas 
		plateau[i][j] = 1 - plateau[i][j];
		dessine_jeton(i,j);
	}
		
}

int encore() // PAS FONCTIONNEL
{
	int i, j;
	
	for(j=0; j<10; j++) {
		for(i=0; i<10; i++) {
			
			if ((plateau[i][j] == 0))
				return 0;
			else 
				return 666;
		}
	}
	return 666;
	 // si tous les jetons sont différents de zéro ou 1
}

void jeu() // JUSTE EN FONCTION DES 100 COUPS ET PAS DE LA WIN
{
	// if (encore = 0) OU (n<100)
	affiche_plateau();
	POINT p;
	int n = 0;
	
	//while ((/*encore() == 666*/) && (n<100)){
	while ((n<100)){
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
