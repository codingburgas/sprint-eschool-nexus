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

Color DARKORANGE = { 200, 100, 0, 255 };

// Button definitions
Button SignUp = { {425, 300, 150, 50}, "  Sign Up ", BLUE, DARKBLUE };
Button LogIn = { {425, 400, 150, 50}, "   Log in ", BLUE, DARKBLUE };
Button Done = { {425, 400, 150, 50}, "   Done ", BLUE, DARKBLUE };
Button Subject1 = { {425, 350, 150, 50}, "Mathematics", PURPLE, DARKPURPLE };
Button Subject2 = { {425, 400, 150, 50}, "Geography", ORANGE, DARKORANGE };
Button Subject3 = { {425, 450, 150, 50}, "Science", SKYBLUE, DARKBLUE };
Button Test1 = { {425, 350, 150, 50}, "  Easy", GREEN, DARKGREEN };
Button Test2 = { {425, 400, 150, 50}, "  Medium", YELLOW, GOLD };
Button Test3 = { {425, 450, 150, 50}, "  Hard", RED, MAROON };
Button Back = { {400, 700, 200, 60}, "  Back", RED, MAROON };




void Menu::draw(int state) {
    ClearBackground(RAYWHITE);
    switch (state) {
    case 1:
        DrawText("Welcome to Nexus", 350, 180, 30, DARKGRAY);
        DrawButton(SignUp);
        DrawButton(LogIn);
        break;
    case 2://sign
        DrawText("Create an Account", 340, 220, 30, DARKGRAY);
        DrawButton(Done);
        DrawButton(Back);
        break;
    case 3://log in 
        DrawText("Log Into Your Account", 320, 220, 30, DARKGRAY);
        DrawButton(Done);
        DrawButton(Back);
        break;
    case 4:
        DrawText("Choose a Subject", 370, 250, 35, DARKGRAY);
        DrawButton(Subject1);
        DrawButton(Subject2);
        DrawButton(Subject3);
        break;
    case 5://subject1
        DrawButton(Back);
    case 6://subject2
        DrawButton(Back);
    case 7://subject3
        DrawText("Choose a Difficulty", 360, 270, 35, DARKGRAY);
        DrawButton(Test1);
        DrawButton(Test2);
        DrawButton(Test3);
        DrawButton(Back);
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
        if (IsButtonPressed(Back)) state = 1; // Return to Main Menu
        break;

    case 4: // Subject menu
        if (IsButtonPressed(Subject1)) state = 5;
        else if (IsButtonPressed(Subject2)) state = 6;
        else if (IsButtonPressed(Subject3)) state = 7;
        break;
    case 5: // Subject 1 
    case 6: // Subject 2 
    case 7: // Subject 3 
        if (IsButtonPressed(Test1) || IsButtonPressed(Test2) || IsButtonPressed(Test3)) state = 8;
        if (IsButtonPressed(Back)) state = 4; // Return to Subjects
        break;
    case 8:
        if (IsButtonPressed(Back)) state = 4; // Return to Subjects
        break;
        break;
    case 9: // Score screen
        if (IsButtonPressed(Back)) state = 4;
        break;
    }
}
  