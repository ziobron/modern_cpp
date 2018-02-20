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

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;

private:
    Color c_ = Color::RED;
};
