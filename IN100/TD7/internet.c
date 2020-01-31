#include "uvsqgraphics.h"

void dessine_ellipse(POINT f1,POINT f2,int dist,COULEUR c)
    {
        POINT o;
        POINT p;
        
        int d = distance(f1,f2)/2; //demi-distance focale d
    
        float i;
        int b;                     // le demi-petit axe de l'ellipse
        int a = (d + dist)/2;      // le demi grand axe de l'ellipse           
        b = a*a + d*d;
        b = sqrt(b); 
        
        if (f1.x < f2.x) 
			o.x = f1.x + (f2.x - f1.x)/2;
		else 
			o.x = f2.x + (f1.x-f2.x)/2;
        if (f1.y < f2.y) 
			o.y = f1.y + (f2.y-f1.y)/2; 
		else 
			o.y = f2.y + (f1.y-f2.y)/2;
        
        draw_pixel(o,jaune);
        
        for(i=0;i<=50;i=i+0.1)
        {
          { p.x = o.x + a*cos(i);//si a>b l'ellipise est horizontale (echange(a,b)) sinon elle est verticale
            p.y = o.y + b*sin(i);
            draw_pixel(p,c);
          }
            
        }    
    }
    
    int main()
{
        init_graphics(900,600);
        while(1)
        {
            
        POINT f1 = wait_clic() ;
        POINT f2 = wait_clic();
        dessine_ellipse(f1,f2,10,bleu);
        }
        
        wait_escape();
        return 0;         
}
