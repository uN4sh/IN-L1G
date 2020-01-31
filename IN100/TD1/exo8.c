#include "uvsqgraphics.h"

int main()
{
	init_graphics(600,400);

	// Debut du code
	int a;
	int b;
	int c;
	int d;
	int e;
	
	a = 5;
	b = 10;
	
	c = a/b;
	d = a%b;
	
	write_int(c);
	writeln(); //pour sauter une ligne sinon il colle les valeurs
	write_int(d);
	writeln();
	// a/b = c, donc a = c*b + d
	e = c*b+d;
	write_int(e);
	// ok ca marche
	

	// Fin du code

	wait_escape();
	exit(0);
}
