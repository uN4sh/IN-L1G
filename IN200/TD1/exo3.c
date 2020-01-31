//indianred, dodgerblue, mediumspringgreen
/* EN GROS
 * Quand on est en affiche on, ca affiche le cercle au clic direct normal genre
 * Quand on est en off, les clics affichent rien, mais genre c'est retenu
 * et des qu'on met affiche all, ca affiche tout
 * genre ils sont en attente
*/
#include "uvsqgraphics.h"

int main()
{
	POINT p;
	init_graphics(900,900);
	
	// Par d´efaut on est en "affiche_auto_on"
	p = wait_clic();
	draw_fill_circle(p,200,bleu);
	p = wait_clic();
	draw_fill_circle(p,200,rouge);
	
	// On passe en off
	affiche_auto_off();
	p = wait_clic();
	draw_fill_circle(p,200,vert);
	p = wait_clic();
	draw_fill_circle(p,200,jaune);
	// Il faut faire affiche_all pour que ca s’affiche
	affiche_all();
	
	// On est toujours en off
	p = wait_clic();
	draw_fill_circle(p,200,gris);
	p = wait_clic();
	draw_fill_circle(p,200,orange);
	// Il faut faire affiche_all pour que ca s’affiche
	affiche_all();
	
	// On passe en on
	// Plus besoin d’affiche_all
	affiche_auto_on();
	p = wait_clic();
	draw_fill_circle(p,200,cyan);
	p = wait_clic();
	
	draw_fill_circle(p,200,magenta);
	wait_escape();
	exit(0);
}
