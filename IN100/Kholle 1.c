#include "uvsqgraphics.h"

int main()
{
	init_graphics(600,600);

	// Debut du code

	POINT C, P;
	// Centre et Point par utilisateur

	POINT BG, HD;
	BG.x = 200; BG.y =0;
	HD.x = 250; HD.y = 50;
	draw_fill_rectangle(BG, HD, vert);

	BG.x = 250; BG.y =0;
	HD.x = 300; HD.y = 50;
	draw_fill_rectangle(BG, HD, jaune);

	BG.x = 300; BG.y =0;
	HD.x = 350; HD.y = 50;
	draw_fill_rectangle(BG, HD, bleu);
	// 3 carrés en bas de l'écran

	C.x = 300; C.y = 300;
	// Centre initialisé

	P = wait_clic();
	//if ((P.x > 200) && (P.x < 350) && (P.y < 50))
	//{
		while ((P.x > 200) && (P.x < 350) && (P.y < 50))
		{
			if (P.x < 250)
				draw_circle(C, 100, vert);
			else if (P.x < 300)
					draw_circle(C, 100, jaune);
				else
					draw_circle(C, 100, bleu);
					
		P = wait_clic();
		}
	//}
	//else 
		exit(0);


	// Fin du code

}
