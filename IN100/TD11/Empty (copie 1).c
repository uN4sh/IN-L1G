#include "uvsqgraphics.h" 
// 1 3 4 5 6 7 8 9
// 2 c'était 200
//indianred, dodgerblue, mediumspringgreen
void affiche_contenu(int a, int b)
{
	write_text("x: ");
	write_int(a);
	write_text(" ");
	write_text("y: ");
	write_int(b);
	writeln();
}

int f(int x) {
	if (x<0) x = -x;
	return x;
}

int main() {
	init_graphics(600,600);
	int x,y = 0;
	
	x = -3;
	x = f(x);
	affiche_contenu(x,y);
	wait_escape();
	return 1;
}

