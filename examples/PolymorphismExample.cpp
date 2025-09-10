#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

// Abstract base class
class Shape {
public:
    virtual ~Shape() {}
    virtual double area() const = 0;
    virtual void draw() const = 0;
};

// Derived class: Circle
class Circle : public Shape {
public:
    Circle(double radius) : m_radius(radius) {}

    double area() const override {
        return M_PI * m_radius * m_radius;
    }

    void draw() const override {
        std::cout << "Drawing Circle with radius " << m_radius << " and area " << area() << std::endl;
    }

private:
    double m_radius;
};

// Derived class: Rectangle
class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : m_width(width), m_height(height) {}

    double area() const override {
        return m_width * m_height;
    }

    void draw() const override {
        std::cout << "Drawing Rectangle with width " << m_width << ", height " << m_height << " and area " << area() << std::endl;
    }

private:
    double m_width;
    double m_height;
};

// Derived class: Triangle
class Triangle : public Shape {
public:
    Triangle(double base, double height) : m_base(base), m_height(height) {}

    double area() const override {
        return 0.5 * m_base * m_height;
    }

    void draw() const override {
        std::cout << "Drawing Triangle with base " << m_base << ", height " << m_height << " and area " << area() << std::endl;
    }

private:
    double m_base;
    double m_height;
};


int main() {
    // Using smart pointers for automatic memory management
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));
    shapes.push_back(std::make_unique<Triangle>(3.0, 4.0));
    shapes.push_back(std::make_unique<Circle>(2.5));

    // Polymorphically call draw() and area()
    for (const auto& shape : shapes) {
        shape->draw();
    }

    return 0;
}
