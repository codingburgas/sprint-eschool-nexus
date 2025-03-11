#ifndef MENU_H
#define MENU_H

#include "raylib.h"
#include "buttons.h"
#include "questions.h"

class Menu { 
public:
    Menu();
    void draw(int state);
    void update(int& state);

};


#endif 