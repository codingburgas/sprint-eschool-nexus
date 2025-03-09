#include "menu.h"
#include "buttons.h"
#include <iostream>
#include "raylib.h"
#include "score.h"
#include <string>
#include "questions.h"

Menu::Menu() {
   
    
    score = 0;
}

// Button definitions
Button SignUp = { {425, 300, 150, 50}, "  Sign Up ", BLUE, DARKBLUE };
Button LogIn = { {425, 400, 150, 50}, "   Log in ", BLUE, DARKBLUE };
Button Done = { {425, 400, 150, 50}, "   Done ", BLUE, DARKBLUE };
Button Test1 = { {425, 350, 150, 50}, "  Test", GREEN, DARKGREEN };
Button Test2 = { {425, 400, 150, 50}, "  Test", YELLOW, GOLD };
Button Test3 = { {425, 450, 150, 50}, "  Test", RED, MAROON };
Button Back = { {800, 600, 150, 50}, "  Back", RED, MAROON };
Button Subject1 = { {425, 350, 150, 50}, "  Subject ", RED, MAROON };
Button Subject2 = { {425, 400, 150, 50}, "  Subject", YELLOW, GOLD };
Button Subject3 = { {425, 450, 150, 50}, "  Subject", GREEN, DARKGREEN };



void Menu::draw(int state) {
    switch (state) {
    case 1:
        DrawButton(SignUp);
        DrawButton(LogIn);
        break;
    case 2:
    case 3:
        DrawButton(Done);
        break;
    case 4:
        DrawButton(Subject1);
        DrawButton(Subject2);
        DrawButton(Subject3);
        break;
    case 5:
    case 6:
    case 7:
        DrawButton(Test1);
        DrawButton(Test2);
        DrawButton(Test3);
        break;
    case 8:
       
        break;

    case 9:
   
        DrawButton(Back);
        break;
    }
}

void Menu::update(int& state) {
    switch (state) {
    case 1: // Main menu 
        if (IsButtonPressed(SignUp)) state = 2;
        if (IsButtonPressed(LogIn)) state = 3;
        break;

    case 2: // Sign-up menu 
    case 3: // Log-in menu 
        if (IsButtonPressed(Done)) state = 4;
        break;

    case 4: // Subject menu
        if (IsButtonPressed(Subject1)) state = 5;
        else if (IsButtonPressed(Subject2)) state = 6;
        else if (IsButtonPressed(Subject3)) state = 7;
        break;

    case 5: // Subject 1 - Test Selection
        if (IsButtonPressed(Test1)) state = 8;
        else if (IsButtonPressed(Test2)) state = 8;
        else if (IsButtonPressed(Test3)) state = 8;
        break;
    case 6: // Subject 2 - Test Selection
        if (IsButtonPressed(Test1)) state = 8;
        else if (IsButtonPressed(Test2)) state = 8;
        else if (IsButtonPressed(Test3)) state = 8;
        break;
    case 7: // Subject 3 - Test Selection
        if (IsButtonPressed(Test1)) state = 8;
        else if (IsButtonPressed(Test2)) state = 8;
        else if (IsButtonPressed(Test3)) state = 8;
        break;
        
        break;

    case 8: 
       
        break;

    case 9: // Score screen
        if (IsButtonPressed(Back)) {
           
            state = 4;
        }
        break;
    }
}
  