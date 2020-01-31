#include "uvsqgraphics.h"

//indianred dodgerblue mediumspringgreen

int T[20], i, min, imin;

void recherche(int n){
	min=T[n];
	for(i=n;i<20;i++){
		if(min>T[i]){
			min=T[i];
			imin=i;
		}
	}
	write_int(min);
}

void echange(int n) {
	int c;
	POINT bg, hd;
	
	c = T[n];
	bg.x=(100+20*n);bg.y=50;
	hd.x=(100+20*n+19);hd.y=(50+3*T[n]);
	draw_fill_rectangle(bg,hd,noir);
	T[n] = T[imin];
	T[imin] = c;
	
	for (i=n ; i<20 ; i++) { 
		bg.x = 100 + (20*i); bg.y=50;
		hd.x = 100 + 20*i +19; hd.y = 50 + 3*T[i];
		draw_fill_rectangle(bg, hd, dodgerblue);
	}
}

int main()
{
	init_graphics(600,400);

	// Debut du code
	
	POINT bg, hd;
	int n=0;

	for (i=0 ; i<20 ; i++) { T[i] = alea_int(100); }
	
	for (i=0 ; i<20 ; i++) { 
		bg.x = 100 + (20*i); bg.y=50;
		hd.x = 100 + 20*i +19; hd.y = 50 + 3*T[i];
		draw_fill_rectangle(bg, hd, dodgerblue);
		}
	
	wait_clic();
	for (n = 0; n < 20; n++)
	{
		recherche(n);
		echange(n);
		wait_clic();
	}
	
	
	
	/*
	bg.x = 100 + (20*0);
	hd.x = 100 + 20*0 +19;
	hd.y = 50 + 3*T[0];
	draw_fill_rectangle(bg, hd, mediumspringgreen); // Premiere valeur en vert
	
	bg.x = 100 + (20*imin);
	hd.x = 100 + 20*imin +19;
	hd.y = 50 + 3*min;
	draw_fill_rectangle(bg, hd, white); // Plus petite valeur en blanc
	
	echange(T[0],min); //min devient T[0] & imin devient i
	
	wait_clic();
	
	fill_screen(black);
	tableau(); // redessine le tableau avec les memes valeurs et T0 devenu min, 
	
	
	bg.x = 100 + (20*imin);
	hd.x = 100 + 20*imin + 19;
	hd.y = 50 + 3*min;
	draw_fill_rectangle(bg, hd, mediumspringgreen); // ancienne premiere
	
	bg.x = 100 + (20*0);
	hd.x = 100 + 20*0 +19;
	hd.y = 50 + 3*T[0];
	draw_fill_rectangle(bg, hd, white); // ancienne min, devenue premiere
	*/
	
	//indianred, dodgerblue, mediumspringgreen
	
	
	// Fin du code

	wait_escape();
	exit(0);
}
