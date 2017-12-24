#include <iostream>
#include <cstdlib>

bool homeMenu = true;
bool inHomeMenu()
{
    std::cout << "************************************************************************* " << std::endl;
    std::cout << "*     \\      /\\      / |----- |       /---  /---\\   |\\    /| |----       *" << std::endl;
    std::cout << "*      \\    /  \\    /  |____  |      |     |     |  | \\  / | |___        *" << std::endl;
    std::cout << "*       \\  /    \\  /   |      |      |     |     |  |  \\/  | |           *" << std::endl;
    std::cout << "*        \\/      \\/    |----- |-----  \\---  \\---/   |      | |----       *" << std::endl;
    std::cout << "*------------------------------------------------------------------------*" << std::endl;
    std::cout << "*|                                                                      |*" << std::endl;
    std::cout << "*|                                                                      |*" << std::endl;
    std::cout << "*|                   E-Waste Management Solutions Inc.                  |*" << std::endl;
    std::cout << "*|                                                                      |*" << std::endl;
    std::cout << "*|                      PRESS ANY KEY TO CONTINUE...                    |*" << std::endl;
    std::cout << "*|                                                                      |*" << std::endl;
    std::cout << "*|                                                                      |*" << std::endl;
    std::cout << "*|                                                                      |*" << std::endl;
    std::cout << "*|----------------------------------------------------------------------|*" << std::endl;
    std::cout << "**************************************************************************" << std::endl;
    system("pause>null");
    return homeMenu;
}

