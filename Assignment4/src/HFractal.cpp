/*
 * File: HFractal.cpp
 * ------------------
 * This program draws an H-fractal on the graphics window.int main() {
 */

#include "gwindow.h"

/* Function prototypes */

void drawHFractal(GWindow & gw, double x, double y, double size, int order);

/* Test program */

int test1() {
   GWindow gw;
   double xc = gw.getWidth() / 2;
   double yc = gw.getHeight() / 2;
   drawHFractal(gw, xc, yc, 100, 3);
   return 0;
}

/*
 * Function: drawHFractal
 * Usage: drawHFractal(gw, x, y, size, order);
 * -------------------------------------------
 * Draws a fractal diagram consisting of an H in which each additional
 * fractal layer draws half-size fractals at the four endpoints of each H.
 */

void drawHFractal(GWindow & gw, double x, double y, double size, int order) {
   gw.setColor("Black");

   //TODO
   // Coordinates are consisted of top, bottom, left, right
   int top = y - size/2;
   int mid = y;
   int bottom = y + size/2;
   int left = x - size/2;
   int right = x + size/2;
   // Recursive end condition
   if (order == 0) {
       gw.drawLine(left,  top, left,  bottom);
       gw.drawLine(right, top, right, bottom);
       gw.drawLine(left,  mid, right, mid);
       return;
   }
   // Recursion to draw H.
   else {
       gw.drawLine(left,  top, left,  bottom);
       gw.drawLine(right, top, right, bottom);
       gw.drawLine(left,  mid, right, mid);
       order -= 1;  // order minus 1 every time
       // Recursion at every point, size/2
       drawHFractal(gw, left, top, size/2, order);
       drawHFractal(gw, right, top, size/2, order);
       drawHFractal(gw, left, bottom, size/2, order);
       drawHFractal(gw, right, bottom, size/2, order);
   }
   //Hint: you may use the function "gw.drawLine(···)"

}
