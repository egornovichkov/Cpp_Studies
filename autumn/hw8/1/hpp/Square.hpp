#ifndef SQUARE_H
#define SQUARE_H
#include "Rectangle.hpp"

class Square final : public Rectangle
{

public:
    Square() : Rectangle(0, 0) {}
    Square(double side) : Rectangle(side, side) {}

    virtual ~Square(){};

protected:
    virtual std::string print() const final;
};
#endif