#include "Octagon.h"
#include <stdexcept>
#include <cmath>

Octagon::Octagon(Point p1, Point p2, Point p3, Point p4, Point p5, Point p6, Point p7, Point p8) {
    vertices = {p1, p2, p3, p4, p5, p6, p7, p8};
}

Point Octagon::geometricCenter() const {
    return Figure::geometricCenter();
}

double Octagon::area() const {
    if (vertices.size() != 8) return 0;
    
    Point center = geometricCenter();
    double total_area = 0.0;
    
    for (size_t i = 0; i < vertices.size(); ++i) {
        size_t j = (i + 1) % vertices.size();
        
        double x1 = center.x, y1 = center.y;
        double x2 = vertices[i].x, y2 = vertices[i].y;
        double x3 = vertices[j].x, y3 = vertices[j].y;
        
        double triangle_area = std::abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
        total_area += triangle_area;
    }
    
    return total_area;
}

Octagon::operator double() const {
    return area();
}