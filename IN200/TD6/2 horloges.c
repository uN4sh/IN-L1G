#include "uvsqgraphics.h"

//indianred, dodgerblue, mediumspringgreen

#define PI 3.1415

void scindage();

void afficher_cadran();

void afficher_aiguille_heure(int h, int m, int s);
void effacer_aiguille_heure(int h, int m, int s);

void afficher_aiguille_minute(int h, int m, int s);
void effacer_aiguille_minute(int h, int m, int s);

void afficher_aiguille_seconde(int h, int m, int s);
void effacer_aiguille_seconde(int h, int m, int s);

void afficher_aiguilles(int h, int m, int s);

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

int main()
{
	init_graphics(900,600);
	
	scindage();
	afficher_cadran();
	int h, m, s;
	affiche_auto_off();
	
	while (1) {
		h = heure(); m = minute(); s = seconde();
		
		afficher_dizaine_heure();
		afficher_unite_heure();
		
		deux_points();

		afficher_dizaine_minutes();
		
		afficher_unite_minutes();
		
		afficher_dizaine_secondes();

		afficher_unite_secondes();
		
		afficher_cadran();
		afficher_aiguilles(h,m,s);
		
		printf("s = %d\n", (int)seconde());
		affiche_all();
		attendre(500);
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


void afficher_cadran()
{
	
	POINT c;
	c.x = WIDTH/2; c.y = (HEIGHT + HEIGHT/3) / 2;
	draw_fill_circle(c,190,white);
	draw_fill_circle(c,185, black);
	draw_fill_circle(c,3,white);
	
	
	POINT p;
	
	//p.x = (WIDTH/2) + 180 + cosf(0); p.y  = 2*(HEIGHT/3) + sinf (0);
	p.x = c.x + 160*cosf(0); p.y = c.y + 160*sinf(0);
	pol_style(GRAS);aff_pol_centre("3", 35, p, white);
	
	p.x = c.x + 160*cosf(PI/6); p.y = c.y + 160*sinf(PI/6);
	aff_pol_centre("2", 35, p, white);
	
	p.x = c.x + 160*cosf(2*PI/6); p.y = c.y + 160*sinf(2*PI/6);
	aff_pol_centre("1", 35 , p, white);
	
	p.x = c.x + 160*cosf(3*PI/6); p.y = c.y + 160*sinf(3*PI/6);
	aff_pol_centre("12", 35, p, white);
	
	p.x = c.x + 160*cosf(4*PI/6); p.y = c.y + 160*sinf(4*PI/6);
	aff_pol_centre("11", 35, p, white);
	
	p.x = c.x + 160*cosf(5*PI/6); p.y = c.y + 160*sinf(5*PI/6);
	aff_pol_centre("10", 35, p, white);
	
	p.x = c.x + 160*cosf(6*PI/6); p.y = c.y + 160*sinf(6*PI/6);
	aff_pol_centre("9", 35, p, white);
	
	p.x = c.x + 160*cosf(7*PI/6); p.y = c.y + 160*sinf(7*PI/6);
	aff_pol_centre("8", 35, p, white);
	
	p.x = c.x + 160*cosf(8*PI/6); p.y = c.y + 160*sinf(8*PI/6);
	aff_pol_centre("7", 35, p, white);
	
	p.x = c.x + 160*cosf(9*PI/6); p.y = c.y + 160*sinf(9*PI/6);
	aff_pol_centre("6", 35, p, white);
	
	p.x = c.x + 160*cosf(10*PI/6); p.y = c.y + 160*sinf(10*PI/6);
	aff_pol_centre("5", 35, p, white);
	
	p.x = c.x + 160*cosf(11*PI/6); p.y = c.y + 160*sinf(11*PI/6);
	aff_pol_centre("4", 35, p, white);
	
	pol_style(NORMAL);
	/*
	int i;
	for (i = 0; i < 60; i++)
	{
		p.x = c.x + 160*cosf(i*PI/30); p.y = c.y + 160*sinf(i*PI/30);
		aff_pol_centre(",", 20, p, white);
	}
	*/
	
}

void afficher_aiguille_heure(int h, int m, int s)
{
	int r = 90;
	POINT c;
	POINT p;
	c.x = WIDTH/2; c.y = (HEIGHT + HEIGHT/3) / 2;
	
	
	//p.x = c.x + r*cosf((PI/2)-(h*PI/6));
	//p.y = c.y + r*sinf((PI/2)-(h*PI/6));
		
	
	p.x = c.x + r*cosf( (PI/2)- (h*PI/6)-m*PI/(6*60) );
	p.y = c.y + r*sinf( (PI/2)- (h*PI/6)-m*PI/(6*60) );
	
	draw_line(c,p,white);
	
	
}

void effacer_aiguille_heure(int h, int m, int s)
{
	int r = 90;
	POINT c;
	POINT p;
	c.x = WIDTH/2; c.y = (HEIGHT + HEIGHT/3) / 2;
	
	p.x = c.x + r*cosf((PI/2)-(h*PI/6)-m*PI/(6*60));
	p.y = c.y + r*sinf((PI/2)-(h*PI/6)-m*PI/(6*60));
	
	draw_line(c,p,black);
}

void afficher_aiguille_minute(int h, int m, int s)
{
	int r = 120;
	POINT c;
	POINT p;
	c.x = WIDTH/2; c.y = (HEIGHT + HEIGHT/3) / 2;
	
	p.x = c.x + r*cosf( (PI/2)- 2*m*PI/(60)-  s*PI/(6*60*60) );
	p.y = c.y + r*sinf( (PI/2)-  2*m*PI/(60)-  s*PI/(6*60*60) );
	
	draw_line(c,p,white);
}

void effacer_aiguille_minute(int h, int m, int s)
{
	int r = 120;
	POINT c;
	POINT p;
	c.x = WIDTH/2; c.y = (HEIGHT + HEIGHT/3) / 2;
	
	p.x = c.x + r*cosf((PI/2)-m*PI/(6*60)-s*PI/(6*60*60));
	p.y = c.y + r*sinf((PI/2)-m*PI/(6*60)-s*PI/(6*60*60));
	
	draw_line(c,p,black);
}

void afficher_aiguille_seconde(int h, int m, int s)
{
	int r = 130;
	POINT c;
	POINT p;
	c.x = WIDTH/2; c.y = (HEIGHT + HEIGHT/3) / 2;
	
	p.x = c.x + r*cosf((PI/2)-  2* s*PI/(60));
	p.y = c.y + r*sinf((PI/2)-  2* s*PI/(60));
	
	draw_line(c,p,blue);
}

void effacer_aiguille_seconde(int h, int m, int s)
{
	int r = 130;
	POINT c;
	POINT p;
	c.x = WIDTH/2; c.y = (HEIGHT + HEIGHT/3) / 2;
	
	p.x = c.x + r*cosf((PI/2)-  2* s*PI/(60));
	p.y = c.y + r*sinf((PI/2)-  2* s*PI/(60));
	
	draw_line(c,p,black);
}

void afficher_aiguilles(int h, int m, int s)
{
	afficher_aiguille_heure(h,m,s);
	afficher_aiguille_minute(h,m,s);
	afficher_aiguille_seconde(h,m,s);
}


/* HORLOGE DIGITALE */

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
