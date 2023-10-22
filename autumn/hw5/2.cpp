#include <iostream>
#include <string>

enum class convert_emum
{
    SI = 0,
    CGS = 1
};

class ElementaryParticle
{

public:
    ElementaryParticle(const std::string& name,
                       double electric_charge,
                       double mass,
                       double spin,
                       double diametr,
                       double lifetime,
                       convert_emum units_system)
        : m_name(name), m_electric_charge(electric_charge), m_mass(mass), m_spin(spin), m_diametr(diametr), m_lifetime(lifetime), m_units_system(units_system){};

    void print();

    ~ElementaryParticle() { std::cout << "...Deconstructing card for " << m_name << "\n"; }

    std::string& GetName(convert_emum);
    double GetCharge(convert_emum);
    double GetMass(convert_emum);
    double GetSpin(convert_emum);
    double GetDiametr(convert_emum);
    double GetLifetime(convert_emum);

    void SetName(const std::string &, convert_emum);
    void SetCharge(double, convert_emum);
    void SetMass(double, convert_emum);
    void SetSpin(double, convert_emum);
    void SetDiametr(double, convert_emum);
    void SetLifetime(double, convert_emum);

private:
    std::string m_name;
    double m_electric_charge;
    double m_mass;
    double m_spin;
    double m_diametr;
    double m_lifetime;
    const double m_charge_const = 2997924580;
    const double m_mass_const = 1000;
    const double m_diametr_const = 100;
    convert_emum m_units_system;
};

// Определение геттеров
std::string& ElementaryParticle::GetName(convert_emum type)
{
    return m_name;
}
double ElementaryParticle::GetCharge(convert_emum type)
{
    if (type == m_units_system)
        return m_electric_charge;
    else if (type == convert_emum::SI)
        return m_electric_charge / m_charge_const;
    else
        return m_electric_charge * m_charge_const;
}
double ElementaryParticle::GetMass(convert_emum type)
{
    if (type == m_units_system)
        return m_mass;
    else if (type == convert_emum::SI)
        return m_mass / m_mass_const;
    else
        return m_mass * m_mass_const;
}
double ElementaryParticle::GetSpin(convert_emum type)
{
    return m_spin;
}
double ElementaryParticle::GetDiametr(convert_emum type)
{
    if (type == m_units_system)
        return m_diametr;
    else if (type == convert_emum::SI)
        return m_diametr / m_diametr_const;
    else
        return m_diametr * m_diametr_const;
}
double ElementaryParticle::GetLifetime(convert_emum type)
{
    return m_lifetime;
}

// Определение сеттеров
void ElementaryParticle::SetName(const std::string &name, convert_emum type)
{
    m_name = name;
}
void ElementaryParticle::SetCharge(double electric_charge, convert_emum type)
{
    if (type == m_units_system)
        m_electric_charge = electric_charge;
    else if (type == convert_emum::SI)
        m_electric_charge = electric_charge * m_charge_const;
    else
        m_electric_charge = electric_charge / m_charge_const;
}
void ElementaryParticle::SetMass(double mass, convert_emum type)
{
    if (type == m_units_system)
        m_mass = mass;
    else if (type == convert_emum::SI)
        m_mass = mass * m_mass_const;
    else
        m_mass = mass / m_mass_const;
}
void ElementaryParticle::SetSpin(double spin, convert_emum type)
{
    m_spin = spin;
}
void ElementaryParticle::SetDiametr(double diametr, convert_emum type)
{
    if (type == m_units_system)
        m_diametr = diametr;
    else if (type == convert_emum::SI)
        m_diametr = diametr * m_diametr_const;
    else
        m_diametr = diametr / m_diametr_const;
}
void ElementaryParticle::SetLifetime(double lifetime, convert_emum type)
{
    m_lifetime = lifetime;
}

void ElementaryParticle::print()
{
    std::cout << "----------------------------";
    std::cout << "\nName: " << m_name;
    std::cout << "\nCharge: " << m_electric_charge;
    std::cout << "\nMass: " << m_mass;
    std::cout << "\nSpin: " << m_spin;
    std::cout << "\nDiametr: " << m_diametr;
    std::cout << "\nLifetime: " << m_lifetime;
    std::cout << "\nSystem of units: ";
    if (m_units_system == convert_emum::SI)
        std::cout << "SI";
    else
        std::cout << "CGS";
    std::cout << "\n----------------------------\n";
}

int main()
{
    ElementaryParticle Electron = {"Electron", -1.62e-19, 9.1e-31, 0.5, 1e-18, 1e30, convert_emum::SI};
    Electron.print();
    std::cout << Electron.GetCharge(convert_emum::SI) << "\n";
    Electron.SetCharge(4.8e-10, convert_emum::CGS);
    std::cout << Electron.GetCharge(convert_emum::SI) << "\n";
    Electron.print();
}