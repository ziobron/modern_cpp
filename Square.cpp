#include "Square.hpp"
#include <iostream>

Square::Square(double x, Color color)
    : Rectangle(x, x, color)
{}

double Square::getArea() const
{
    return getX() * getX();
}

double Square::getPerimeter() const
{
    return 4 * getX();
}

std::string Square::getName() const
{
    return "Square";
}

void Square::print() const
{
    std::cout << getName() << ":    x: " << getX()
              << ", area: " << getArea()
              << ", perimeter: " << getPerimeter() << std::endl;
}
