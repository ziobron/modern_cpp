#include "Shape.hpp"
#include <iostream>

Shape::Shape(Color c)
    : c_(c)
{}

void Shape::print() const
{
    std::cout << "Unknown Shape" << std::endl;
}
