#ifndef MENU_H
#define MENU_H
#pragma once
#include <raylib.h>
#include <string>
#include "constants.h"

using namespace std;



class Menu {
private:
    int option;
    int level;
    // Music added
    Music musicSound;
    Sound moveSound;
    // Help screen
    double lastColorChangeTime = GetTime();
    Color currentTextColor = WHITE;
public:
    Menu();
    Color getRandomColor();
    int getOption();
    int getLevel();
    void drawHelpScreen();
    void render();
};

#endif