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

    return 0;
}
