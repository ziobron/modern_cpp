#pragma once

#include <string>

enum class Color
{
    ORANGE,
    GREEN,
    BLUE,
};


class Shape
{
public:
    Shape(Color color)
        : m_color(color)
    {}

    Shape(Shape const& src) = default;

    virtual ~Shape() = default;

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual std::string getName() const;
    virtual void print() const;

    Color getColor() const
    {
        return m_color;
    }


private:
    Color m_color;
};
