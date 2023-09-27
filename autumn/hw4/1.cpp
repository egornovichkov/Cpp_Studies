#include <iostream>

struct CelestialBody
{
    std::string m_name;
    std::string m_type;
    double m_radius;
    double m_mass;
    double m_surface_temp;
    bool m_islife;

    CelestialBody(std::string name = "Earth", std::string type = "Planet", double radius = 6371, double mass = 5.9722e24, double surface_temp = 12, bool islife = 1)
        : m_name(name),
          m_type(type),
          m_radius(radius),
          m_mass(mass),
          m_surface_temp(surface_temp),
          m_islife(islife)
    {
        std::cout << "...Constructing card for " << type << " " << name;
    }

    ~CelestialBody()
    {
        std::cout << "...Deconstructing card for " << m_type << " " << m_name;
    }

    void print()
    {
        std::cout << "\n----------------------------";
        std::cout << "\nName: " << m_name;
        std::cout << "\nType: " << m_type;
        std::cout << "\nRadius: " << m_radius;
        std::cout << "\nMass: " << m_mass;
        std::cout << "\nSurface Temperature: " << m_surface_temp;
        std::cout << "\nThere is life: " << std::boolalpha << m_islife;
        std::cout << "\n----------------------------\n";
    }

};

int main()
{
    CelestialBody Earth{};
    Earth.print();
    CelestialBody Mars{"Mars", "Planet", 2000, 3e23, -61, 0};
    Mars.print();

    return 0;
}
