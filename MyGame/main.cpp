#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "Game.h"
#include "MainMenu.h"

int main()
{
    MainMenu menu;
    while (menu.isRunning()) {
        menu.render();
    }
    return 0;
}