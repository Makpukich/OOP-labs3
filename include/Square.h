#pragma once
#include "Figure.h"

class Square : public Figure {
public:
    Square() = default;
    Square(Point p1, Point p2, Point p3, Point p4);
    
    Point geometricCenter() const override;
    double area() const override;
    operator double() const override;
};