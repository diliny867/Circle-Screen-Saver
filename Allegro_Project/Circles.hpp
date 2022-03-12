#include "Circle.hpp"
#include <windows.h>
#include "AllegroBase.hpp"
#include <vector>
#include <ctime>
#include <iostream>

class Circles {
protected:
    std::vector<Circle*>circles;
public:
    Circles();
    void CreateCircles(int n);
    void Move();
    void Draw();
};