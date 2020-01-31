#include "uvsqgraphics.h"

//indianred, dodgerblue, mediumspringgreen

#define PI 3.1415

struct chrono {
	int h;
	int m;
	int s;
};
typedef struct chrono CHRONO;

void scindage();

/* --------------------- */
/* HORLOGE DIGITALE      */
/* --------------------- */

int m = 1; // Clignotage deux points

void transforme(int a, int segments[7]);

void afficher_dizaine_heure();
void afficher_unite_heure();

void deux_points();

void afficher_dizaine_minutes();
void afficher_unite_minutes();

void afficher_dizaine_secondes();
void afficher_unite_secondes();

void affiche_seg(POINT b, int segments[7]);

/* --------------------- */
/*      CHRONOMETRE      */
/* --------------------- */

void afficher_bouton();
CHRONO init_chronometre();
void afficher_chrono(CHRONO c);

int main()
{
	init_graphics(900,600);
	
	scindage();
	afficher_bouton();
	
	while (1) {
		afficher_dizaine_heure();
		afficher_unite_heure();
		
		deux_points();

		afficher_dizaine_minutes();
		
		afficher_unite_minutes();
		
		afficher_dizaine_secondes();

		afficher_unite_secondes();
		printf("s = %d\n", (int)seconde());
		afficher_bouton();
		attendre(1000);
	}
	
	wait_escape();
	exit(0);
}


void scindage()
{
	POINT bg, hd;
	bg.x = 0; hd.x = WIDTH;
	bg.y = HEIGHT/3; hd.y = bg.y;
	draw_line(bg,hd,white);
}

void transforme(int a, int segments[7])
{
	int i;
	for (i = 0; i <= 7; i++)
	{
		segments[i] = 0;
	}
	
	switch(a)
	{
	case 0:
		segments[6]=segments[1]=segments[2]=segments[3]=segments[4]=segments[5]=1;
		//segments[7]=0;
		break;
	case 1 :
		segments[1] = 1;
		segments[6] = 1;
		break;
	case 2 :
		segments[2] = 1;
		segments[1] = 1;
		segments[7] = 1;
		segments[4] = 1;
		segments[5] = 1;
		break;
	case 3 :
		segments[2] = 1;
		segments[1] = 1;
		segments[7] = 1;
		segments[6] = 1;
		segments[5] = 1;
		break;
	case 4 :
		segments[3] = 1;
		segments[1] = 1;
		segments[7] = 1;
		segments[6] = 1;
		break;
	case 5 :
		segments[2] = 1;
		segments[3] = 1;
		segments[7] = 1;
		segments[6] = 1;
		segments[5] = 1;
		break;
	case 6 :
		segments[2] = 1;
		segments[3] = 1;
		segments[7] = 1;
		segments[6] = 1;
		segments[5] = 1;
		segments[4] = 1;
		break;
	case 7 :
		segments[2] = 1;
		segments[1] = 1;
		segments[6] = 1;
		break;
	case 8 :
		segments[1] = 1;
		segments[2] = 1;
		segments[3] = 1;
		segments[4] = 1;
		segments[5] = 1;
		segments[6] = 1;
		segments[7] = 1;
		break;
	case 9 :
		segments[1] = 1;
		segments[2] = 1;
		segments[3] = 1;
		segments[7] = 1;
		segments[5] = 1;
		segments[6] = 1;
		break;
	}
}

// 50 chaque chiffre
// 10 entre les chiffres
// 20 entre les 2 points
// 5 de long les deux points
// 50 * 6 chiffres + 20 * 4 espaces + 10 * 3 espaces + 5 * 2 deux points = 420
// 900 de long - 420 = 480
// 480 / 2 = 240 de chaque côtés pour centrer les chiffres

// Maintenant comment tout mettre en fonction de WIDTH ?

void afficher_dizaine_heure()
{
	int segments[7];
	int h = heure()/10;
	transforme(h,segments);
	POINT b;
	b.x = 240; b.y = 50;
	affiche_seg(b, segments);
}

void afficher_unite_heure()
{
	int segments[7];
	int h = heure()%10;
	transforme(h,segments);
	POINT b;
	b.x = 300; b.y = 50;
	affiche_seg(b, segments);
		
}

void deux_points()
{
	POINT b, h;
	COULEUR coul;
	
	if (m == 1)  coul = white;
	else 		coul = noir;
	
	b.x = 370; b.y = 80;
	h.x = 375; h.y = 87;
	draw_rectangle(b,h,coul);
	
	h.y = 120; b.y = 113;
	draw_rectangle(b,h,coul);
	
	b.x = 525; b.y = 80;
	h.x = 530; h.y = 87;
	draw_rectangle(b,h,coul);
	
	h.y = 120; b.y = 113;
	draw_rectangle(b,h,coul);
	
	m = 1 - m;
	
	
}

void afficher_dizaine_minutes()
{
	int segments[7];
	int m = minute()/10;
	m=2;
	transforme(m,segments);
	POINT b;
	b.x = 395; b.y = 50;
	affiche_seg(b, segments);
		
}

void afficher_unite_minutes()
{
	int segments[7];
	int m = minute()%10;
	transforme(m,segments);
	POINT b;
	b.x = 455; b.y = 50;
	affiche_seg(b, segments);
		
}

void afficher_dizaine_secondes()
{
	int segments[7];
	int s = seconde()/10;
	transforme(s,segments);
	POINT b;
	b.x = 550; b.y = 50;
	affiche_seg(b, segments);
}

void afficher_unite_secondes()
{
	int segments[7];
	int s;
	s = (int)seconde() %10; // Conversion forcée en int
	transforme(s,segments);
	POINT b;
	b.x = 610; b.y = 50;
	affiche_seg(b, segments);
}

void affiche_seg(POINT b, int segments[7])
{
	POINT h;
	
	/* 4 */
	h.x = b.x; h.y = b.y + 50;
		if(segments[4] == 1)		draw_line(b,h,white);
		else 					draw_line(b,h,black);
	/* 3 */
	b.x = b.x; b.y += 50;
	h.x = b.x; h.y = b.y + 50;
		if(segments[3] == 1)		draw_line(b,h,white);
		else 					draw_line(b,h,black);
	/* 2 */
	b.x = b.x; /*195*/		b.y += 50; //150
	h.x = b.x + 50; /*245*/ h.y = b.y; // 150
		if(segments[2] == 1)		draw_line(b,h,white);
		else 					draw_line(b,h,black);
	/* 1 */
	b.x += 50 /*245*/; b.y -= 50; //100
	h.x = b.x; h.y = b.y + 50; //150
		if(segments[1] == 1)		draw_line(b,h,white);
		else 					draw_line(b,h,black);
	/* 6 */
	b.x = b.x; b.y -= 50; //50
	h.x = b.x; h.y = b.y + 50;
		if(segments[6] == 1)		draw_line(b,h,white);
		else 					draw_line(b,h,black);
	/* 5 */
	b.x -= 50; /*195*/ b.y = b.y;
	h.x = b.x + 50; h.y = b.y;
		if(segments[5] == 1)		draw_line(b,h,white);
		else 					draw_line(b,h,black);
	/* 7 */
	b.x = b.x; b.y += 50;
	h.x = b.x + 50; h.y += 50;
		if(segments[7] == 1)		draw_line(b,h,white);
		else 					draw_line(b,h,black);		
}

/* --------------------- */
/*      CHRONOMETRE      */
/* --------------------- */

void afficher_bouton()
{
	POINT bg, hd;
	int segments[7];
	POINT clic;
	clic = wait_clic();
	
	bg.x = 0; bg.y = 0;
	hd.x = 70; hd.y = 50;
	draw_fill_rectangle(bg,hd,indianred);
	
	POINT b;
	if (clic.x < 70 && clic.y < 50)
	{
		while (1) {
			transforme(0,segments);
			
			deux_points();
			
			b.x = 240; b.y = 50;
			affiche_seg(b, segments);
			b.x = 300; b.y = 50;
			affiche_seg(b, segments);
			b.x = 395; b.y = 50;
			affiche_seg(b, segments);
			b.x = 455; b.y = 50;
			affiche_seg(b, segments);
			b.x = 550; b.y = 50;
			affiche_seg(b, segments);
			b.x = 610; b.y = 50;
			affiche_seg(b, segments);
			
			attendre(500);
		}
	}
}
