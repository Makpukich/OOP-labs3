#include "Triangle.h"
#include <stdexcept>
#include <cmath>

Triangle::Triangle(Point p1, Point p2, Point p3) {
    vertices = {p1, p2, p3};
}

Point Triangle::geometricCenter() const {
    return Figure::geometricCenter();
}

double Triangle::area() const {
    if (vertices.size() != 3) return 0;
    
    double x1 = vertices[0].x, y1 = vertices[0].y;
    double x2 = vertices[1].x, y2 = vertices[1].y;
    double x3 = vertices[2].x, y3 = vertices[2].y;
    
    return std::abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}

Triangle::operator double() const {
    return area();
}