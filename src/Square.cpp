#include "Square.h"
#include <stdexcept>
#include <cmath>

Square::Square(Point p1, Point p2, Point p3, Point p4) {
    vertices = {p1, p2, p3, p4};
}

Point Square::geometricCenter() const {
    return Figure::geometricCenter();
}

double Square::area() const {
    if (vertices.size() != 4) return 0;
    
    double side = std::sqrt(std::pow(vertices[1].x - vertices[0].x, 2) + 
                           std::pow(vertices[1].y - vertices[0].y, 2));
    return side * side;
}

Square::operator double() const {
    return area();
}