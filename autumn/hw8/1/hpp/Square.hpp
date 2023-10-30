#include <iostream>

class Square : public Rectangle
{

public:
    Square() : Rectangle(0, 0) {}
    Square(double side) : Rectangle(side, side) {}

    virtual ~Square();

protected:
    virtual std::ostream& print() const final;
};