#include "uvsqgraphics.h"

int T[20], i, min, imin;

void echange() {
	int c;
	/*
	c = i;
	i = imin;
	imin = 0;
	*/
	c = min;
	min = T[0];
	T[0] = c; 
}

// On a le tableau T[0..20] avec des hauteurs dedans
// DONT T[imin] = min
// On echange alors T[imin] avec T[0] et imin avec 0

// imin devient 0
// 0 devient imin
// T[imin] devient T[0]

// Exp : T[0] = 50
//		 T[imin] = 3

void tableau() {
	POINT bg, hd;
	
	bg.y = 50;
	for (i=0 ; i<20 ; i++) 
	{ 
		bg.x = 100 + (20*i);
		
		hd.x = 100 + 20*i +19;
		hd.y = 50 + 3*T[i];
		
		draw_fill_rectangle(bg, hd, indianred);
	}
}

int main()
{
	init_graphics(600,400);

	// Debut du code
	
	POINT bg, hd;
	/*
	int T[20];
	int i;
	
	int imin, min;
	*/
	imin = 0; min = 100; // Tri par comparaison à 100
	
	bg.y = 50;
	for (i=0 ; i<20 ; i=i+1) 
	{ 
		T[i] = alea_int(100); 
		bg.x = 100 + (20*i);
		
		hd.x = 100 + 20*i +19;
		hd.y = 50 + 3*T[i];
		
		draw_fill_rectangle(bg, hd, dodgerblue);
		
		if (T[i] < min)	{
			imin = i;
			min = T[i];
		}
	}
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
	
	
	//indianred, dodgerblue, mediumspringgreen
	
	
	// Fin du code

	wait_escape();
	exit(0);
}
