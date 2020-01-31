#include "uvsqgraphics.h"

int main()
{
	init_graphics(600,400);

	// Debut du code
	int a;
	int b;
	a = 7;
	b = a;
	a = a + 2;
	write_int(a);
	writeln(); //pour sauter une ligne sinon il colle les valeurs
	write_int(b);
	writeln();
	
	a = (10/3)*3;
	b=(10*3)/3;
	write_int(a);
	writeln(); 
	write_int(b);
	//on trouve 2 valeurs différents pcq la division est entière, 10/3 = 3 pour l'ordi


	// Fin du code

	wait_escape();
	exit(0);
}
