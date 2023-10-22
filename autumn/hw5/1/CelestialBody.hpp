#include <string>
#include <iostream>

class CelestialBody
{

public:
    CelestialBody(std::string &&name = "Earth",
                  std::string &&type = "Planet",
                  double radius = 6371,
                  double mass = 5.9722e24,
                  double surface_temp = 12,
                  bool islife = 1);

    void print();

    std::string & get_name();
    std::string & get_type();
    double get_radius();
    double get_mass();
    double get_surface_temp();
    bool get_islife();

    void set_name(std::string &&);
    void set_type(std::string &&);
    void set_radius(double);
    void set_mass(double);
    void set_surface_temp(double);
    void set_islife(bool);

    ~CelestialBody() { std::cout << "...Deconstructing card for " << m_type << " " << m_name << "\n"; }

private:
    std::string m_name;
    std::string m_type;
    double m_radius;
    double m_mass;
    double m_surface_temp;
    bool m_islife;

    friend void thermometr(const CelestialBody &obj);
};
