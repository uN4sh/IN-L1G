#include "uvsqgraphics.h"

void affiche_contenu(int a, int b)
{
	write_text("a: ");
	write_int(a);
	write_text(" ");
	write_text("b : ");
	write_int(b);
	writeln();
}

int a;
void f (int b) 
{
	a = a+1;
	b = b+1;
	affiche_contenu(a,b);
}

int main()
{
	init_graphics(600,600);
	int a, b;
	a = 2;
	b = 3;
	affiche_contenu(a,b);
	f(a);
	affiche_contenu(a,b);
	wait_escape();
}

/*
int a;
void modifie(int b)
{
	int a;
	b = b + 10;
	a = b * 2;
	affiche_contenu(a,b);
}

int main()
{
	init_graphics(300,300);
	int b;
	a = 10;
	b = 30;
	modifie(b);
	modifie(a);
*/

