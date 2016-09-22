#pragma once

#include <string>

enum class Color
{
    ORANGE,
    GREEN,
    BLUE,
};

//struct Foo
//{
//constexpr Foo(int i, int k)
//    : i_(i), k_(k)
//{}

//constexpr int vvv() const
//{
//    return i_ * k_;
//}


//int i_, k_;
//};

class Shape
{
public:
    constexpr Shape(Color color)
        : m_color(color)
    {}

    Shape(Shape const& src) = default;

    virtual ~Shape() = default;

    virtual double getArea() const noexcept = 0;
    virtual double getPerimeter() const noexcept= 0;
    virtual std::string getName() const;
    virtual void print() const;

    Color getColor() const
    {
//        static_assert(5 < Foo(14,414).vvv());
        return m_color;
    }


private:
    Color m_color;
};
