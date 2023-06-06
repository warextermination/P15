// P15.cpp

#include <iostream>
#include <string>




int main()
{
int P, P1, P2, P3;
    setlocale(LC_ALL, "es_MX.UFT-8");
    std::cout << "Bienvenidos a himalaya \n";
    std::cout << "Escoje tu pokemon mi maracaamigo \n";
    std::cout << "1-Silveon, 2-Bulbasour, 3-Charizard \n";
    std::cin >> P;
    switch (P)
    {
    case 1: 
        std::cout << "Escogiste a Silveon excelente eleccion \n";
        std::cin >> P1;
        break;
    case 2:
        std::cout << "Escogiste a Bulbasour excelente eleccion \n";
        std::cin >> P2;
        break;
    case 3:
        std::cout << "Escogiste a Charizard excelente eleccion \n";
        std::cin >> P3;
        break;
    default:
        std::cout << "Ese pokemon no lo ha creado Satoshi Tajiri \n";
        break;
    }
    if (P1)
    {

    }
}

