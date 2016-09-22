#pragma once

#include "Shape.hpp"

class Circle final : public Shape
{
public:
    Circle(double r, Color color);
    Circle(const Circle & other) = default;

    double getArea() const override;
    double getPerimeter() const override;
    double getRadius() const;
    std::string getName() const override;
    void print() const override;

private:
    double r_;
};
