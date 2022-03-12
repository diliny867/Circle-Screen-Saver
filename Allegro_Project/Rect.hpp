#pragma once
#include "Figure.hpp"

class Rect :public Figure {
public:
    Rect(double x10, double x20, double y10, double y20, double dx0, double dy0, ALLEGRO_COLOR col);
    bool Overlap(double x3, double x4, double y3, double y4);
    int Touch(double x3, double x4, double y3, double y4);
};