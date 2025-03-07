#pragma once
#include "raylib.h"
#include "buttons.h"

class Menu { 
public:
    void draw(int state);
    void update(int& state); 
};

//start menu buttons
extern Button SignUp;
extern Button LogIn;
