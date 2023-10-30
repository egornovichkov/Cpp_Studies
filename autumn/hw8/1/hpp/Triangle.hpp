#include <iostream>

class Triangle : public Polygon
{
public:
    Triangle() : m_side1(0), m_side2(0), m_side3(0) {}
    Triangle(double, double, double);
    virtual double perimetr() final;
    virtual double square() final;

    virtual ~Triangle();

protected:
    virtual std::ostream& print() const final;

    bool validate_triangle(double, double, double);

    double m_side1;
    double m_side2;
    double m_side3;
};