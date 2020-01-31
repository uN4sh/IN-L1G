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
	int f;
	
	a = 15;
	b = 10;
	c = 5;
	
	d = a-b-c;
	e = (a-b)-c;
	f = a-(b-c);
	
	write_int(d);
	writeln();
	write_int(e);
	writeln();
	write_int(f);
	writeln();
	writeln();
	// On constate que parenthèse prioritaire
	// Fin exo9
	
	a = 15;
	b = 10;
	c = 5;
	
	d = a/b/c;
	e = (a/b)/c;
	f = a/(b/c);
	
	write_int(d);
	writeln();
	write_int(e);
	writeln();
	write_int(f);
	//Priorité parenthèse et divisions entières
	
	// Fin du code

	wait_escape();
	exit(0);
}
