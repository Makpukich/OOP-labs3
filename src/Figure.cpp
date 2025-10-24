#include "Figure.h"
#include <cmath>

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

bool Figure::operator==(const Figure& other) const {
    if (vertices.size() != other.vertices.size()) return false;
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (!(vertices[i] == other.vertices[i])) return false;
    }
    return true;
}

Point Figure::geometricCenter() const {
    if (vertices.empty()) return Point();
    
    double sumX = 0, sumY = 0;
    for (const auto& vertex : vertices) {
        sumX += vertex.x;
        sumY += vertex.y;
    }
    return Point(sumX / vertices.size(), sumY / vertices.size());
}

Figure::operator double() const {
    return area();
}

void Figure::print(std::ostream& os) const {
    for (const auto& vertex : vertices) {
        os << vertex << " ";
    }
}

std::ostream& operator<<(std::ostream& os, const Figure& fig) {
    fig.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& fig) {
    fig.vertices.clear();
    Point p;
    while (is >> p) {
        fig.vertices.push_back(p);
    }
    return is;
}