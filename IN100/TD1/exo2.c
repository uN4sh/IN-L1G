#include "uvsqgraphics.h"

int main()
{
init_graphics(900,600);

// Debut du code
POINT p1;
POINT p2;
POINT p3;
POINT p4;
POINT p5;
POINT p6;
POINT p7;

p1.x = 100; p1.y =  300;
p2.x = 800; p2.y = 300;
p3.x = 450; p3.y = 300;

draw_line(p1, p2, jaune);
draw_circle(p1, 100, blanc);
draw_circle(p2, 100, blanc); 
draw_circle(p3, 100, blanc);
//Fin q1

p1.x = 100; p1.y = 400;
p2.x = 800; p2.y = 400;
draw_line(p1, p2, orange);

p1.x = 100; p1.y = 500;
p2.x = 800; p2.y = 500;
draw_line(p1,p2, rouge);

p1.x = 100; p1.y = 200;
p2.x = 800; p2.y = 200;
draw_line(p1,p2, vert);

p1.x = 100; p1.y = 100;
p2.x = 800; p2.y = 100;
draw_line(p1,p2, bleu);
//Fin Q2

p1.x = 20; p1.y = 20;
p2.x = 120; p2.y = 120;
draw_rectangle(p1,p2, blanc);
//Fin Q3

p1.x = 200; p1.y = 200;
p2.x = 300; p2.y = 200;
draw_line(p1,p2, bleu);

p1.x = 300; p1.y = 200;
p2.x = 300; p2.y = 300;
draw_line(p1,p2, vert);

p1.x = 300; p1.y = 300;
p2.x = 200; p2.y = 300;
draw_line(p1,p2, rouge);

p1.x = 200; p1.y = 300;
p2.x = 200; p2.y = 200;
draw_line(p1,p2, orange);
//Fin Q4

p1.x = 95; p1.y = 145;
p2.x = 145; p2.y = 195;
draw_rectangle(p1,p2, blanc);
draw_line(p1,p2,blanc);
p1.x = 95; p1.y = 195;
p2.x = 145; p2.y = 145;
draw_line(p1, p2, blanc);
//Fin Q5

p1.x = 350; p1.y = 300;
p2.x = 400; p2.y = 386;
p3.x = 500; p3.y = 386;
p4.x = 550; p4.y = 300;
p5.x = 500; p5.y = 214;
p6.x = 400; p6.y = 214;
p7.x = 450; p7.y = 300;

draw_circle(p7, 100, rouge);
draw_line(p1, p2, blanc);
draw_line(p2, p3, blanc);
draw_line(p3, p4, blanc);
draw_line(p4, p5, blanc);
draw_line(p5, p6, blanc);
draw_line(p6, p1, blanc);
//Fin Q6 et Fin exo 2


// Fin du code

wait_escape();
exit(0);
}
