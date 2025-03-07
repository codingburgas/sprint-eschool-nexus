#include "menu.h"
#include "buttons.h"
#include <iostream>


Button SignUp = { {425, 300, 150, 50}, "  Sign Up ", BLUE, DARKBLUE };
Button LogIn = { {425, 400, 150, 50}, "   Log in ", BLUE, DARKBLUE };

void Menu::draw(int state) {
    switch (state) {
    case 1:
        DrawButton(SignUp);
        DrawButton(LogIn);
        break;
    }
}

void Menu::update(int& state) { 
      switch (state) {
    case 1:
        if (IsButtonPressed(SignUp)) {
            std::cout << "Sign up button " << std::endl;
        }
        if (IsButtonPressed(LogIn)) {
            std::cout << "Log In Button " << std::endl;
        }
        break;
    }
}
