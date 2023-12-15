#ifndef MENU_H
#define MENU_H

#include <raylib.h>
#include <string>
#include "constants.h"

class Menu {
private:
    int option;
    int level;
public:
    Menu();
    int getOption();
    int getLevel();
    void render();
};

#endif