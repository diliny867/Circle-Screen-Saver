#include "Figure.hpp"

Figure::Figure() :
    x1(0),
    y1(0),
    x2(0),
    y2(0),
    dx(0),
    dy(0),
    color(al_map_rgb(255, 255, 255))
{}
Figure::Figure(double x10, double x20, double y10, double y20, double dx0, double dy0, ALLEGRO_COLOR col):
    x1(x10),
    x2(x20),
    y1(y10),
    y2(y20),
    dx(dx0),
    dy(dy0),
    color(col)
{}
Figure::~Figure()
{}
 void Figure::Move()
{}
void Figure::Draw()
{}
double Figure::GetX1() {
    return x1;
}
double Figure::GetX2() {
    return x2;
}
double Figure::GetY1() {
    return y1;
}
double Figure::GetY2() {
    return y2;
}
void Figure::SetX1(double n) {
    x1 = n;
}
void Figure::SetX2(double n) {
    x2 = n;
}
void Figure::SetY1(double n) {
    y1 = n;
}
void Figure::SetY2(double n) {
    y2 = n;
}

