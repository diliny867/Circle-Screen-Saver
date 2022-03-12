#include "Rect.hpp"
#include "Figure.hpp"
#include <cstdlib>

Rect::Rect(double x10, double x20, double y10, double y20, double dx0, double dy0, ALLEGRO_COLOR col):
    Figure(x10,x20,y10,y20,dx0,dy0,col)
{}

bool Rect::Overlap(double x3, double x4, double y3, double y4) {
    if (!(x1 > x4) && !(x3 > x2) && !(y1 > y4) && !(y3 > y2)) {
        return true;
    }
    return false;
}

int Rect::Touch(double x3, double x4, double y3, double y4) {
    double n = 8.0;
    if ((((y4 >= y1 && y4 <= y2) || (y3 >= y1 && y3 <= y2))) && ((x4 >= x1 && x4 <= x1 + n) || (x3 <= x2 && x3 >= x2 - n))) {
        return 1;
    }
    if ((((x4 >= x1 && x4 <= x2) || (x3 >= x1 && x3 <= x2))) && ((y4 >= y1 && y4 <= y1 + n) || (y3 <= y2 && y3 >= y2 - n))) {
        return 2;
    }
    return 0;
}