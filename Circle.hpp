#pragma once

#include "Shape.hpp"

class Circle final : public Shape
{
public:
    Circle(double r, Color color);
    Circle(const Circle & other) = default;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    double getRadius() const;
    std::string getName() const override;
    void print() const override;

private:
    double r_;
};
