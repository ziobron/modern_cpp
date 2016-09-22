#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square(double x, Color color);
    Square(const Square & other) = default;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    std::string getName() const override    ;
    void print() const override;
private:
    double getY() = delete;
};
