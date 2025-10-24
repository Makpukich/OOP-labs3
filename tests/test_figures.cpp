#include <gtest/gtest.h>
#include <cmath>
#include "../include/Figure.h"
#include "../include/Octagon.h"
#include "../include/Triangle.h"
#include "../include/Square.h"

class Array {
private:
    std::vector<std::shared_ptr<Figure>> figures;

public:
    void addFigure(Figure* fig) {
        figures.push_back(std::shared_ptr<Figure>(fig));
    }

    double getAllArea() const {
        double total = 0;
        for (const auto& fig : figures) {
            total += fig->area();
        }
        return total;
    }

    size_t size() const {
        return figures.size();
    }
};

TEST(PointTest, Equality) {
    Point p1(1.0, 2.0);
    Point p2(1.0, 2.0);
    Point p3(3.0, 4.0);
    
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

TEST(TriangleTest, AreaCalculation) {
    Triangle triangle({0.0, 0.0}, {4.0, 0.0}, {0.0, 3.0});
    EXPECT_NEAR(triangle.area(), 6.0, 0.001);
}

TEST(TriangleTest, GeometricCenter) {
    Triangle triangle({0.0, 0.0}, {4.0, 0.0}, {0.0, 3.0});
    Point center = triangle.geometricCenter();
    
    EXPECT_NEAR(center.x, 4.0 / 3.0, 0.001);
    EXPECT_NEAR(center.y, 1.0, 0.001);
}

TEST(TriangleTest, DoubleConversion) {
    Triangle triangle({0.0, 0.0}, {4.0, 0.0}, {0.0, 3.0});
    double area = static_cast<double>(triangle);
    EXPECT_NEAR(area, 6.0, 0.001);
}

TEST(SquareTest, AreaCalculation) {
    Square square({0.0, 0.0}, {2.0, 0.0}, {2.0, 2.0}, {0.0, 2.0});
    EXPECT_NEAR(square.area(), 4.0, 0.001);
}

TEST(SquareTest, GeometricCenter) {
    Square square({0.0, 0.0}, {4.0, 0.0}, {4.0, 4.0}, {0.0, 4.0});
    Point center = square.geometricCenter();
    
    EXPECT_NEAR(center.x, 2.0, 0.001);
    EXPECT_NEAR(center.y, 2.0, 0.001);
}

TEST(OctagonTest, AreaCalculation) {
    Octagon octagon(
        {2.0, 0.0},      
        {1.414, 1.414},  
        {0.0, 2.0},      
        {-1.414, 1.414}, 
        {-2.0, 0.0},    
        {-1.414, -1.414},
        {0.0, -2.0},     
        {1.414, -1.414}  
    );
    
    double area = octagon.area();
    EXPECT_NEAR(area, 11.31, 0.1);
}

TEST(FigureTest, PrintMethod) {
    Triangle triangle({0.0, 0.0}, {1.0, 0.0}, {0.0, 1.0});
    
    testing::internal::CaptureStdout();
    triangle.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_FALSE(output.empty());
}

TEST(FigureTest, EqualityOperator) {
    Triangle triangle1({0.0, 0.0}, {1.0, 0.0}, {0.0, 1.0});
    Triangle triangle2({0.0, 0.0}, {1.0, 0.0}, {0.0, 1.0});
    Triangle triangle3({0.0, 0.0}, {2.0, 0.0}, {0.0, 2.0});
    
    EXPECT_TRUE(triangle1 == triangle2);
    EXPECT_FALSE(triangle1 == triangle3);
}

TEST(FigureTest, CopyConstructor) {
    Triangle triangle1({0.0, 0.0}, {1.0, 0.0}, {0.0, 1.0});
    Triangle triangle2 = triangle1;
    
    EXPECT_TRUE(triangle1 == triangle2);
}

TEST(FigureTest, AssignmentOperator) {
    Triangle triangle1({0.0, 0.0}, {1.0, 0.0}, {0.0, 1.0});
    Triangle triangle2({0.0, 0.0}, {2.0, 0.0}, {0.0, 2.0});
    
    triangle2 = triangle1;
    EXPECT_TRUE(triangle1 == triangle2);
}

TEST(ArrayTest, TotalArea) {
    Array array;
    
    Triangle triangle({0.0, 0.0}, {4.0, 0.0}, {0.0, 3.0});
    Square square({0.0, 0.0}, {2.0, 0.0}, {2.0, 2.0}, {0.0, 2.0});
    
    array.addFigure(new Triangle(triangle));
    array.addFigure(new Square(square));
    
    EXPECT_NEAR(array.getAllArea(), 10.0, 0.001);
}

TEST(ArrayTest, EmptyArray) {
    Array array;
    EXPECT_NEAR(array.getAllArea(), 0.0, 0.001);
}

TEST(FigureTest, StreamOutput) {
    Triangle triangle({1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0});
    
    testing::internal::CaptureStdout();
    std::cout << triangle;
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("1") != std::string::npos);
    EXPECT_TRUE(output.find("2") != std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}