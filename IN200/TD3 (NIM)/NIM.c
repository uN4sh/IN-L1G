#include "uvsqgraphics.h"

//indianred, dodgerblue, mediumspringgreen

/* Jeu de NIM
 * N allumettes et 2 joueurs
 * Chaque joueur retire alternativement 1, 2 ou 3 alumettes
 * Celui qui retire la dernière a perdu
 * 23 allumettes au départ
 * On stocke le nombre d'allumettes restantes à chaque fois
*/


// TOUT MARCHE, MANQUE PLUS QU'A REGLER LE GAGNANT ...

int n; // nbr d'allumettes
int o = 0; // joueur1

void texte_zalamittes();

void affiche_une_allumette(POINT);
void allumette_old(POINT);

void efface_une_allumette(POINT);
void efface_allumettes(int);

void affiche_allumettes(int);

void affiche_123();
void mini_allumette(POINT);

int get_valeur();

void jouer_humain();

void jouer();
int test_gagnant();

int main()
{
	init_graphics(700,400);

	/*while(1) {
		POINT p;
		p = wait_clic();
		affiche_une_allumette(p);
		p.x -= 15;
		allumette_old(p);
	}*/
	n = 23;
	affiche_allumettes(23);
	affiche_123();
	
	/*write_ln();
	write_text("              ");
	write_text("                       Zalamittes = "); write_int(n);
	*/
	texte_zalamittes();
	
	int gagnant = 100;
	
	while(gagnant == 100) {
		jouer();
		gagnant = test_gagnant();
	}
	
	POINT bg,hd;
	bg.x = 100; bg.y = 250;
	hd.x = 500; hd.y = 400;
	draw_fill_rectangle(bg,hd,black);
	if (o==0) { POINT t;
	t.x = 350; t.y = 270;
	aff_pol_centre("BIEN OUEJ JOUEUR 1",35,t,dodgerblue); }
	if (o==1) {POINT t;
	t.x = 350; t.y = 270;
	aff_pol_centre("BIEN OUEJ JOUEUR 2",35,t,dodgerblue);}
	

	wait_escape();
	exit(0);
}


void texte_zalamittes()
{
	POINT t;
	t.x = 260; t.y = 390;
	aff_pol("ZALAMITTES = ",22,t,mediumspringgreen);
	POINT bg,hd;
	bg.x = 432; bg.y = 360;
	hd.x = 470; hd.y = 390;
	draw_fill_rectangle(bg,hd,black);
	t.x = 435;
	aff_int(n,22,t,mediumspringgreen);
}

void affiche_une_allumette(POINT p) // OK
{
	
	POINT bg, hd;
	POINT cercle;
	
	bg = p;
	
	hd.x = p.x + 4; hd.y = p.y + 95;
	draw_fill_rectangle(p,hd,navajowhite);
	bg.x += 3;
	draw_fill_rectangle(bg,hd,peru);
	
	cercle.x = p.x + 2; cercle.y = p.y;
	draw_fill_circle(cercle,2,navajowhite);
	
	cercle.x = p.x + 2; cercle.y = p.y + 95;
	draw_fill_circle(cercle,4,red);
	cercle.y += 2;
	draw_fill_circle(cercle,4,tomato);
	cercle.y += 2;
	draw_fill_circle(cercle,4,crimson);
}

void allumette_old(POINT p) // OK
{
	
	POINT hd;
	POINT cercle;
	
	hd.x = p.x + 4; hd.y = p.y + 95;
	draw_fill_rectangle(p,hd,navajowhite);
	
	
	cercle.x = p.x + 2; cercle.y = p.y + 99;
	draw_fill_circle(cercle,4,red);

}

void affiche_allumettes(int n) // OK
{
	// Affiche n allumettes au coordonnées (20,200) (40,200) ...
	POINT p;
	int i;
	p.y = 200; 
	
	for (i = 0; i < n ; i++)
	{
		//p.x = i*20 + 20;
		p.x = WIDTH/n + i * (WIDTH-(WIDTH/n))/n; 
		affiche_une_allumette(p);
	}	
}

void efface_une_allumette(POINT p) // OK but soon... n
{
	POINT hd;
	POINT cercle;
	
	hd.x = p.x + 4; hd.y = p.y + 95;
	draw_fill_rectangle(p,hd,black);
	
	cercle.x = p.x + 2; cercle.y = p.y;
	draw_fill_circle(cercle,2,black);
	
	cercle.x = p.x + 2; cercle.y = p.y + 95;
	draw_fill_circle(cercle,4,black);
	cercle.y += 2;
	draw_fill_circle(cercle,4,black);
	cercle.y += 2;
	draw_fill_circle(cercle,4,black);

}

void efface_allumettes(int k)
{
	// efface 1, 2 ou 3 allumettes
	// je veux qu'elle efface les dernières allumettes en fonction de n
	// test avec la dernière allumette
	// boucle de 0 à k
	POINT p;
	int i;
	p.y = 200;
	for (i = 0; i < k; i++)
	{
		p.x = WIDTH/23 + (n-1) * (WIDTH-(WIDTH/23))/23;
		// n-1 parceque les alumettes vont de 0 à 22
		efface_une_allumette(p);
		n = n - 1; // diminue le n
		/*write_ln();
		write_text("              ");
		write_text("                       Zalamittes = "); write_int(n);
		*/
		texte_zalamittes();
	}
	
}

void affiche_123() // OK
{
	POINT bg, hd;
	POINT mini;
	
		bg.x = 100; bg.y = 50; // (100;50)(200;150)
		hd.x = bg.x + 100; hd.y = bg.y + 100;
		draw_fill_rectangle(bg,hd,whitesmoke);
		draw_rectangle(bg,hd,midnightblue);
		mini.x = 146; mini.y = 70;
		mini_allumette(mini);
		
		
		bg.x = 300; bg.y = 50; // (300;50)(400;150)
		hd.x = bg.x + 100; hd.y = bg.y + 100;
		draw_fill_rectangle(bg,hd,whitesmoke);
		draw_rectangle(bg,hd,midnightblue);
		mini.x = 330; mini.y = 70;
		mini_allumette(mini);
		mini.x = 365; mini.y = 70;
		mini_allumette(mini);
		
		
		bg.x = 500; bg.y = 50; // (500;50)(600;150)
		hd.x = bg.x + 100; hd.y = bg.y + 100;
		draw_fill_rectangle(bg,hd,whitesmoke);
		draw_rectangle(bg,hd,midnightblue);
		mini.x = 522; mini.y = 70;
		mini_allumette(mini);
		mini.x = 547; mini.y = 70;
		mini_allumette(mini);
		mini.x = 572; mini.y = 70;
		mini_allumette(mini);
	
}

void mini_allumette(POINT bg) // OK
{
	POINT cercle;
	POINT hd;
	
	hd.x = bg.x + 4; hd.y = bg.y + 55;
	draw_fill_rectangle(bg,hd,navajowhite);
	bg.x += 3;
	draw_fill_rectangle(bg,hd,peru);
	
	bg.x -= 3;
	cercle.x = bg.x + 2; cercle.y = bg.y;
	draw_fill_circle(cercle,2,navajowhite);
	
	cercle.x = bg.x + 2; cercle.y = bg.y + 55;
	draw_fill_circle(cercle,4,red);
	cercle.y += 2;
	draw_fill_circle(cercle,4,tomato);
	cercle.y += 2;
	draw_fill_circle(cercle,4,crimson);
}

int get_valeur() // NORMALEMENT OK
{
	POINT clic;
	clic = wait_clic();
	
	while (1) {
		if ((clic.y < 150)&&(clic.y > 50)) {
			if ((clic.x < 200)&&(clic.x > 100))		return 1;
				
			if ((clic.x < 400)&&(clic.x > 300))		return 2;
					
			if ((clic.x < 600)&&(clic.x > 500))		return 3;
		}
		clic = wait_clic();
	}
}

void jouer_humain() // Juste à régler les textes
{
	int k; // 1, 2 ou 3
	k = get_valeur();
	
	efface_allumettes(k);
	o = 1-o;
}

void jouer()
{
	POINT bg,hd;
	bg.x = 375; bg.y = 320;
	hd.x = 400; hd.y = 350;
	draw_fill_rectangle(bg,hd,black);
	if (o==0) { POINT t;
	t.x = 335; t.y = 340;
	aff_pol_centre("JOUEUR 1",22,t,dodgerblue); }
	if (o==1) {POINT t;
	t.x = 335; t.y = 340;
	aff_pol_centre("JOUEUR 2",22,t,dodgerblue);}
	
	
	jouer_humain();
	
}

int test_gagnant()
{
	if (n<=0) return 111;
	else return 100;
}
