#include <string>
#include <iostream>
#include "CelestialBody.hpp"


CelestialBody::CelestialBody(std::string name, std::string type, double radius, double mass, double surface_temp, bool islife)
    : m_name(name),
        m_type(type),
        m_radius(radius),
        m_mass(mass),
        m_surface_temp(surface_temp),
        m_islife(islife)
{
    std::cout << "...Constructing card for " << type << " " << name;
}

void CelestialBody::print()
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