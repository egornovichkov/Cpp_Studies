#include <iostream>

class Rectangle : public Polygon
{
public:
    Rectangle() : m_length(0), m_width(0){}
    Rectangle(double length, double width) : m_length(validate(length)), m_width(validate(width)){}

    virtual double perimetr() final;
    virtual double square() final;

    virtual ~Rectangle();

protected:
    virtual std::ostream& print() const override;
    double m_length;
    double m_width;
};