#pragma once
#include "Figure.h"

class Octagon : public Figure {
public:
    Octagon() = default;
    Octagon(Point p1, Point p2, Point p3, Point p4, Point p5, Point p6, Point p7, Point p8);
    
    Point geometricCenter() const override;
    double area() const override;
    operator double() const override;
};