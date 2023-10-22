#include <iostream>
#include "CelestialBody.hpp"

void thermometr (const CelestialBody &obj)
{
    std::cout << "Temparature of this object is: " << obj.m_surface_temp << "\n";
}

int main()
{
    CelestialBody Earth{};
    Earth.print();
    CelestialBody Mars{"Mars", "Planet", 2000, 3e23, -61, 0};
    Mars.print();
    thermometr(Earth);
    thermometr(Mars);
    std::cout << Mars.get_mass() << "\n";
    std::cout << Earth.get_type() << "\n";
    CelestialBody Halley;
    Halley.set_name("Halley");
    Halley.set_type("Comet");
    Halley.set_mass(2.2e14);
    Halley.set_radius(11);
    Halley.set_surface_temp(80);
    Halley.set_islife(0);
    Halley.print();

    return 0;
}
