#include <iostream>
#include <vector>
#include "./hpp/Abstract_Base.hpp"
#include "./hpp/Shape.hpp"
#include "./hpp/Polygon.hpp"
#include "./hpp/Ellipse.hpp"
#include "./hpp/Circle.hpp"
#include "./hpp/Rectangle.hpp"
#include "./hpp/Triangle.hpp"
#include "./hpp/Square.hpp"

int main()
{
    Shape *e = new Ellipse(1, 2);
    Shape *c = new Circle(5);
    Shape *r = new Rectangle(2, 4);
    Shape *s = new Square(7);
    Shape *t = new Triangle(3, 4, 5);

    std::vector<Shape *> v {e, c, r, s, t};
    for (auto &elem : v)
    {
        std::cout << *elem;
        std::cout << "Perimetr: "<< elem->perimetr() << "\n";
        std::cout << "Square: " << elem->square() << "\n";
    }

    return 0;
}
