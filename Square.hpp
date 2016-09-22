#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square(double x, Color color);
    Square(const Square & other) = default;

    double getArea() const override;
    double getPerimeter() const override;
    std::string getName() const override;
    void print() const override;
private:
    double getY() = delete;
};
