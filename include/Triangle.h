#pragma once
#include "Figure.h"

class Triangle : public Figure {
public:
    Triangle() = default;
    Triangle(Point p1, Point p2, Point p3);
    
    Point geometricCenter() const override;
    double area() const override;  
    operator double() const override;
};