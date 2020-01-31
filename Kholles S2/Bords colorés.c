#include "uvsqgraphics.h"

int rebonds = 0;

struct balle
{
    POINT centre;
    int rayon;
    COULEUR coul;
    int dx, dy;
};

typedef struct balle BALLE;

BALLE init_balle(BALLE B)
{

    B.centre.x = 100; B.centre.y = 200;
    B.rayon = 60;
    B.dx = 10; B.dy = 3;
    B.coul = blanc;
    return B;
}
void dessiner_bord()
{
	POINT hg,hd,bg,bd;
	bg.x=2;bg.y=2;
	bd.x=598;bd.y=bg.y;
	hg.x=bg.x;hg.y=598;
	hd.x=bd.x;hd.y=hg.y;
	draw_line(hg,hd,rouge);
	draw_line(hd,bd,vert);
	draw_line(bg,bd,bleu);
	draw_line(hg,bg,jaune);
}	
BALLE deplace_balle(BALLE B)
{
   // POINT clic;

    /*if (alea_int(100) < 5) {
        //B.dx = 0;
        //B.dy = 0;
        clic = wait_clic();
        if (distance(clic, B.centre) < B.rayon)    
			B.rayon -= 5;
        else 	
			B.rayon += 5;
    }
*/
    B.centre.x += B.dx;
    B.centre.y += B.dy;

    return B;
}

void efface_balle(BALLE B)
{
    B.coul = black;
    draw_fill_circle(B.centre,B.rayon,B.coul);
}

void affiche_balle(BALLE B)
{
    draw_fill_circle(B.centre,B.rayon,B.coul);
}

BALLE rebond_balle(BALLE B) // modifie dx et dy si la balle dépasse d'un bord
{
    // Bord droite
    if ((B.centre.x >= (WIDTH - B.rayon))) 
		{
			  B.coul=vert;
			  B.dx = -B.dx;
			  rebonds++;
		}
		 if ((B.centre.x <= B.rayon)) 
		 {
			 B.coul=jaune;
			  B.dx = -B.dx;
			  rebonds++;	
		 } 
    if (B.centre.y >= (HEIGHT - B.rayon)) 
		{
		  B.coul=rouge;
		  B.dy = -B.dy;
		  rebonds++;
		}
	if(B.centre.y <= B.rayon)
	{
		  B.coul=bleu;
		  B.dy = -B.dy;
		  rebonds++;
	}
    return B;
}


int main()
{
    init_graphics(600,600);

    // Debut du code
    BALLE B;

    B = init_balle(B);
    affiche_auto_off();

    while(rebonds < 30)
    {
        efface_balle(B);
        B = rebond_balle(B);
        B = deplace_balle(B);
        affiche_balle(B);
		dessiner_bord();
        attendre(30);
        affiche_all();
    }
    // Fin du code

    wait_escape();
    exit(0);
}
