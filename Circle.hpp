#pragma once

#include "Shape.hpp"

class alignas(2) Circle final : public Shape
{
public:
    Circle(const Circle & other) = default;
    Circle(Circle && other) noexcept;
    Circle& operator=(Circle && other) noexcept;

    Circle(double r);
    Circle(double r, Color c);

    double getArea() const noexcept override;
    double getPerimeter() const noexcept(true) override;
    double getRadius() const;
    void print() const override;

    [[deprecated("getPi is deprecated, please use M_PI instead")]]
    double getPi() const;

private:
    Circle() = delete; // doesn't allow to call default constructor

    double r_;
};
