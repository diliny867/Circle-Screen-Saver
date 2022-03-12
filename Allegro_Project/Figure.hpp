#pragma once
#include "AllegroBase.hpp"
class Figure {
protected:
    double x1;
    double x2;
    double y1;
    double y2;
public:
    double dx;
    double dy;
    ALLEGRO_COLOR color;
    Figure();
    Figure(double x10, double x20, double y10, double y20, double dx0, double dy0, ALLEGRO_COLOR col);
    virtual ~Figure();
    virtual void Move();
    virtual void Draw();
    double GetX1();
    double GetX2();
    double GetY1();
    double GetY2();
    void SetX1(double);
    void SetX2(double);
    void SetY1(double);
    void SetY2(double);
};