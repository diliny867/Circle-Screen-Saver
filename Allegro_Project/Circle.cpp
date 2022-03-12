#include "Circle.hpp"
Circle::Circle():
    cx(0),
    cy(0),
    r(0),
    dx(0),
    dy(0),
    v(0),
    color(al_map_rgb(255, 255, 255))
{
}
Circle::Circle(double cx0, double cy0, double r0, double dx0, double dy0, double v0, ALLEGRO_COLOR col):
    cx(cx0),
    cy(cy0),
    r(r0),
    dx(dx0),
    dy(dy0),
    v(v0),
    color(col)
{}
bool Circle::Overlap(Circle cir) {
    if (sqrt((cir.cx - cx)* (cir.cx - cx)+(cir.cy - cy)*(cir.cy - cy))>r+cir.r) {
        return false;
    }
    return true;
}
bool Circle::Touch(double cx2, double cy2, double r2) {
    double n = 5;
    if (0<=(sqrt((cx2 - cx) * (cx2 - cx) + (cy2 - cy) * (cy2 - cy)) - (r + r2))<=5) {
        return false;
    }
    return true;
}
void Circle::Random(double cxmin, double cxmax, double cymin, double cymax, double rmin, double rmax, double dmin, double dmax, double vmin, double vmax)
{//to not get outside the screen ,cxmin and cymin should be >=rmax, and cxmax and cymax should be <=(SCREEN_W or SCREEN_H)-rmax
    r  = rmin + rand() % (long)(rmax - rmin)+ (double)rand() * 2 / (RAND_MAX - 1);
    cx = cxmin + rand() % (long)(cxmax - cxmin) + (double)rand() * 2 / (RAND_MAX - 1);
    cy = cymin + rand() % (long)(cymax - cymin) + (double)rand() * 2 / (RAND_MAX - 1);
    v = vmin + rand() % (long)(vmax-vmin)+(double)rand() / (RAND_MAX - 1);
    printf("r: %f cx: %f cy: %f\nv: %f\n",r,cx,cy,v);
    dx = dmin + rand() % (long)(dmax - dmin) + (double)rand() * 2 / (RAND_MAX - 1);
    dy = dmin + rand() % (long)(dmax - dmin) + (double)rand() * 2 / (RAND_MAX - 1);
}
void Circle::Normalise() {
    double l = sqrt(dx * dx + dy * dy);
    dx *= (1 / l);
    dy *= (1 / l);
    std::cout << "dx: " << dx << "\n";
    std::cout << "dy: " << dy << "\n";
}
double Circle::GetR() {
    return r;
}
double Circle::GetCx() {
    return cx;
}
double Circle::GetCy() {
    return cy;
}
double Circle::GetDx() {
    return dx;
}
double Circle::GetDy() {
    return dy;
}
double Circle::GetV() {
    return v;
}
void Circle::SetR(double n) {
    r = n;
}
void Circle::SetCx(double n) {
    cx = n;
}
void Circle::SetCy(double n) {
    cy = n;
}
void Circle::SetDx(double n) {
    dx = n;
}
void Circle::SetDy(double n) {
    dy = n;
}
void Circle::SetV(double n) {
    v = n;
}
void Circle::IncCx(double n) {
    cx += n;
}
void Circle::IncCy(double n) {
    cy += n;
}
