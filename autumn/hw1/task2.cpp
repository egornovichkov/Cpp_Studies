#include <iostream>

int main()
{

    setlocale(LC_ALL, "");
    int convert_type;
    float value;
    const double const_length = 1e2;
    const double const_mass = 1e3;
    const double const_force = 1e5;
    const double const_energy = 1e7;
    const double const_current = 3.33564e-10;
    const double const_voltage = 2.997925e2;
    const double const_elect_field = 2.997825e4;
    const double const_magnetic_flux = 299.7925;

    while (convert_type != 0)
    {
        std::string quantity;
        std::wcout << L"Для перевода СИ -> СГСЭ напишите 1, для перевода СГСЭ -> СИ напишите 2, для выхода из программы напишите 0" << std::endl;
        std::cin >> convert_type;
        if (convert_type == 0)
        {
            return 0;
        }
        if (convert_type == 1)
        {
            std::wcout << L"Конвертер поддерживает перевод следующих величин из СИ в СГСЭ:\n1. длина\n2. масса\n3. время\n4. сила\n5. энергия\n6. сила тока\n7. напряжение\n8. напряженность электрического поля\n9. магнитный поток.\nНапишите номер величины которую хотите конвертировать: ";
            std::cin >> quantity;
            std::wcout << L"Введите значение величины в СИ: ";
            std::cin >> value;
            if (quantity == "1")
            {
                std::wcout << value / const_length << L" см" << std::endl;
            }
            else if (quantity == "2")
            {
                std::wcout << value / const_mass << L" г" << std::endl;
            }
            else if (quantity == "3")
            {
                std::wcout << value << L" с" << std::endl;
            }
            else if (quantity == "4")
            {
                std::wcout << value / const_force << L" дин" << std::endl;
            }
            else if (quantity == "5")
            {
                std::wcout << value / const_energy << L" эрг" << std::endl;
            }
            else if (quantity == "6")
            {
                std::wcout << value / const_current << L" фр" << std::endl;
            }
            else if (quantity == "7")
            {
                std::wcout << value / const_voltage << L" статВ" << std::endl;
            }
            else if (quantity == "8")
            {
                std::wcout << value / const_elect_field << L" статВ/см" << std::endl;
            }
            else if (quantity == "9")
            {
                std::wcout << value / const_magnetic_flux << L" статВб" << std::endl;
            }
        }
        else
        {
            std::wcout << L"Конвертер поддерживает перевод следующих величин из СГСЭ в СИ:\n1. длина\n2. масса\n3. время\n4. сила\n5. энергия\n6. сила тока\n7. напряжение\n8. напряженность электрического поля\n9. магнитный поток.\nНапишите номер величины которую хотите конвертировать: ";
            std::cin >> quantity;
            std::wcout << L"Введите значение величины в СГСЭ: ";
            std::cin >> value;
            if (quantity == "1")
            {
                std::wcout << value * const_length << L" м" << std::endl;
            }
            else if (quantity == "2")
            {
                std::wcout << value * const_mass << L" кг" << std::endl;
            }
            else if (quantity == "3")
            {
                std::wcout << value << L" с" << std::endl;
            }
            else if (quantity == "4")
            {
                std::wcout << value * const_force << L" Н" << std::endl;
            }
            else if (quantity == "5")
            {
                std::wcout << value * const_energy << L" Дж" << std::endl;
            }
            else if (quantity == "6")
            {
                std::wcout << value * const_current << L" А" << std::endl;
            }
            else if (quantity == "7")
            {
                std::wcout << value * const_voltage << L" В" << std::endl;
            }
            else if (quantity == "8")
            {
                std::wcout << value * const_elect_field << L" В/м" << std::endl;
            }
            else if (quantity == "9")
            {
                std::wcout << value * const_magnetic_flux << L" Вб" << std::endl;
            }
        }
    }
}
