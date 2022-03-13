#pragma once
#include "AllegroBase.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <ctime>
class Circle{
protected:
    double cx;
    double cy;
    double dx;
    double dy;
    double r;
    double m;
    double v;
public:
    ALLEGRO_COLOR color;
    Circle();
    Circle(double cx0, double cy0, double r0, double m0, double dx0, double dy0, double v0, ALLEGRO_COLOR col);
    bool Overlap(Circle cir);
    bool Touch(double cx2, double cy2, double r2);
    void Random(double cxmin, double cxmax, double cymin, double cymax, double mmin, double mmax,double dmin,double dmax, double vmin, double vmax);
    void Normalise();
    double GetR();
    double GetCx();
    double GetCy();
    double GetDx();
    double GetDy();
    double GetV();
    double GetM();
    void SetR(double n);
    void SetCx(double n);
    void SetCy(double n);
    void SetDx(double n);
    void SetDy(double n);
    void SetV(double n);
    void SetM(double n);
    void IncCx(double n);
    void IncCy(double n);
};