#include "Circle.hpp"
#include <math.h>
#include <iostream>

Circle::Circle(double r, Color color)
    : Shape(color)
    , r_(r)
{}

double Circle::getArea() const noexcept
{
    return M_PI * r_ * r_;
}

double Circle::getPerimeter() const noexcept
{
    return 2 * M_PI * r_;
}

double Circle::getRadius() const
{
    return r_;
}

std::string Circle::getName() const
{
    return "Circle";
}

void Circle::print() const
{
    std::cout << getName() << ":    radius: " << getRadius()
              << ", area: " << getArea()
              << ", perimeter: " << getPerimeter() << std::endl;
}
