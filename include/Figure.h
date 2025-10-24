#pragma once
#include <iostream>
#include <vector>
#include <memory>

class Point {
public:
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    friend std::istream& operator>>(std::istream& is, Point& p);
};

class Figure {
protected:
    std::vector<Point> vertices;

public:
    Figure() = default;
    virtual ~Figure() = default;
    
    Figure(const Figure& other) = default;
    Figure& operator=(const Figure& other) = default;
    
    bool operator==(const Figure& other) const;
    
    virtual Point geometricCenter() const;
    virtual double area() const = 0;
    virtual operator double() const;
    
    virtual void print(std::ostream& os) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Figure& fig);
    friend std::istream& operator>>(std::istream& is, Figure& fig);
};