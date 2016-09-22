#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle(double x, double y, Color color);
    Rectangle(const Rectangle & other) = default;

    double getArea() const override;
    double getPerimeter() const override;
    double getX() const;
    double getY() const;
    std::string getName() const override;
    void print() const override;

private:
    double x_;
    double y_;
};
