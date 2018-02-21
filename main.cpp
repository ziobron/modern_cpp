#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

void printCollectionElements(const Collection& collection)
{
    for(auto it : collection)
    {
        if(it != nullptr)
        {
            it->print();
        }
    }
}

void printAreas(const Collection& collection)
{
    for(auto it : collection)
    {
        if(it != nullptr)
        {
            cout << it->getArea() << std::endl;
        }
    }
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     std::function< bool(shared_ptr<Shape>) > predicate,
                                     std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != nullptr)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

class A
{
    ~A() = delete;
};

constexpr int fibonacci(int a)
{
    if (a <= 2)
    {
        return 1;
    }
    return fibonacci(a - 1) + fibonacci(a - 2);
}

template<class DerivedType, class... Arguments>
std::shared_ptr<Shape> make_shape(Arguments&&... args)
{
    return make_shared<DerivedType>(forward<Arguments>(args)...);
}

int main()
{
//    constexpr int i = 45;
//    fibonacci(i);
    //A* a = new A();
    //delete a;
    Collection shapes {
        make_shape<Circle>(2.0, Color::RED),
        shared_ptr<Shape>(new Circle(3.0)),
        nullptr,
        make_shape<Circle>(4.0),
        make_shape<Rectangle>(10.0, 5.0, Color::GREEN),
        make_shape<Square>(3.0, Color::BLUE),
        make_shape<Circle>(4.0),
    };

    auto lambda = [shapes]() mutable { shapes.clear(); };
    lambda();

    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), [](shared_ptr<Shape> first, shared_ptr<Shape> second)
    {
        if(first == nullptr || second == nullptr)
        {
            return false;
        }
        return (first->getArea() < second->getArea());
    });

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    shared_ptr<Shape> square = make_shared<Square>(4.0);
    shapes.push_back(square);

    unique_ptr<Shape> cc = make_unique<Circle>(5.0);
    shapes.push_back(move(cc));

//    auto cc = new Circle(4.0);
//    shapes.emplace_back(std::move(cc));

//    Circle circle(2.0);
//    Circle c2(std::move(circle));

//    c2.getPerimeter();

    auto perimeterBiggerThan20 = [](shared_ptr<Shape> s)
    {
        if(s)
        {
            return (s->getPerimeter() > 20);
        }
        return false;
    };

    int x = 10;
    auto areaLessThanX = [x](shared_ptr<Shape> s)
    {
        if(s)
        {
            return (s->getArea() < x);
        }
        return false;
    };

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    std::cout << alignof(Circle) << std::endl;

    return 0;
}

