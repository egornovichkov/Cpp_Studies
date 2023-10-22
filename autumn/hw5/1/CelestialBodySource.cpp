#include <string>
#include <iostream>
#include "CelestialBody.hpp"

CelestialBody::CelestialBody(const std::string &name, const std::string &type, double radius, double mass, double surface_temp, bool islife)
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

std::string &CelestialBody::get_name()
{
    return m_name;
}

std::string &CelestialBody::get_type()
{
    return m_type;
}

double CelestialBody::get_radius()
{
    return m_radius;
}

double CelestialBody::get_mass()
{
    return m_mass;
}

double CelestialBody::get_surface_temp()
{
    return m_surface_temp;
}

bool CelestialBody::get_islife()
{
    return m_islife;
}

void CelestialBody::set_name(const std::string &name)
{
    m_name = name;
}

void CelestialBody::set_type(const std::string &type)
{
    m_type = type;
}

void CelestialBody::set_radius(double radius)
{
    m_radius = radius;
}

void CelestialBody::set_mass(double mass)
{
    m_mass = mass;
}

void CelestialBody::set_surface_temp(double surface_temp)
{
    m_surface_temp = surface_temp;
}

void CelestialBody::set_islife(bool islife)
{
    m_islife = islife;
}