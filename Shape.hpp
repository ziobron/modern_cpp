#pragma once

enum class Color
{
    RED,
    GREEN,
    BLUE
};

class Shape
{
public:
    virtual ~Shape() {}
    Shape() = default;
    Shape(Shape && other) noexcept = default;
    Shape& operator=(Shape&& other) noexcept = default;
    Shape(const Shape & other) = default;
    Shape& operator=(const Shape & other) = default;

    virtual double getArea() const noexcept = 0;
    virtual double getPerimeter() const noexcept = 0;
    virtual void print() const;

private:
    Color c_ = Color::RED;
};
