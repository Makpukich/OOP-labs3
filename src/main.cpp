#include <iostream>
#include <vector>
#include <memory>
#include "Figure.h"
#include "Octagon.h"
#include "Triangle.h"
#include "Square.h"

class Array {
private:
    std::vector<std::shared_ptr<Figure>> figures;

public:
    void addFigure(Figure* fig) {
        figures.push_back(std::shared_ptr<Figure>(fig));
    }

    void printFigures() const {
        for (size_t i = 0; i < figures.size(); ++i) {
            std::cout << "Figure " << i << ": ";
            figures[i]->print(std::cout);
            std::cout << "Center: (" << figures[i]->geometricCenter().x 
                      << ", " << figures[i]->geometricCenter().y << ") ";
            std::cout << "Area: " << static_cast<double>(*figures[i]) << std::endl;
        }
    }

    double getAllArea() const {
        double total = 0;
        for (const auto& fig : figures) {
            total += fig->area();
        }
        return total;
    }

    Figure* operator[](size_t index) const {
        if (index < figures.size()) {
            return figures[index].get();
        }
        return nullptr;
    }
};

int main() {
    Triangle triangle({0, 0}, {4, 0}, {0, 3});
    Square square({0, 0}, {2, 0}, {2, 2}, {0, 2});
    Octagon octagon({1, 0}, {2, 1}, {2, 2}, {1, 3}, {0, 3}, {-1, 2}, {-1, 1}, {0, 0});

    std::cout << "Triangle: ";
    triangle.print(std::cout);
    std::cout << "Center: (" << triangle.geometricCenter().x 
              << ", " << triangle.geometricCenter().y << ") ";
    std::cout << "Area: " << static_cast<double>(triangle) << std::endl;

    std::cout << "Square: ";
    square.print(std::cout);
    std::cout << "Center: (" << square.geometricCenter().x 
              << ", " << square.geometricCenter().y << ") ";
    std::cout << "Area: " << static_cast<double>(square) << std::endl;

    std::cout << "Octagon: ";
    octagon.print(std::cout);
    std::cout << "Center: (" << octagon.geometricCenter().x 
              << ", " << octagon.geometricCenter().y << ") ";
    std::cout << "Area: " << static_cast<double>(octagon) << std::endl << std::endl;

    Array arr;
    arr.addFigure(new Triangle(triangle));
    arr.addFigure(new Square(square));
    arr.addFigure(new Octagon(octagon));

    arr.printFigures();

    std::cout << "Total area: " << arr.getAllArea() << std::endl;

    Figure* figure = arr[1];
    std::cout << "Figure at index 1: ";
    figure->print(std::cout);
    std::cout << "Area: " << static_cast<double>(*figure) << std::endl;

    return 0;
}