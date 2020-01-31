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


int main()
{
	init_graphics(900,600);


	//fill_screen(dimgray);
	scindage();
	afficher_cadran();
	
	int h,m;
	int s;
	
	 affiche_auto_off();
	
	while(1)
	{
		h = heure(); m = minute(); 
		s = seconde();
		
		//h = 20; m = 35;
		
		afficher_cadran();
		afficher_aiguilles(h,m,s);
		printf("s = %d \n", s);
	
		affiche_all();
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
	draw_fill_circle(c,185,white);
	draw_fill_circle(c,180, black);
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
