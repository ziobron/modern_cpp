#include "Circle.hpp"
#include <math.h>
#include <iostream>

Circle::Circle(double r)
    : r_(r)
{}

Circle::Circle(Circle && other) noexcept
    : r_(std::move(other.r_))
{}

Circle& Circle::operator=(Circle && other) noexcept
{
    r_ = std::move(other.r_);
}


double Circle::getArea() const noexcept
{
    static_assert(M_PI != 5, "Pi is only an approximation");
    return M_PI * r_ * r_;
}

double Circle::getPerimeter() const noexcept(true)
{
    return 2 * M_PI * r_;
}

double Circle::getPi() const
{
    return 3.14;
}

double Circle::getRadius() const
{
    return r_;
}

void Circle::print() const
{
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}
