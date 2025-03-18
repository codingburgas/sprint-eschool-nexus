#include "menu.h"
#include "buttons.h"
#include <iostream>
#include "raylib.h"
#include <string>
#include "questions.h"
#include "test.h" 

Menu::Menu() {
    score = 0;
}

// Define button colors
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

Test* currentTest = nullptr;  // Pointer to the active test

void Menu::draw(int state) {
    ClearBackground(RAYWHITE);
    switch (state) {
    case 1:
        DrawText("Welcome to Nexus", 350, 180, 30, DARKGRAY);
        DrawButton(SignUp);
        DrawButton(LogIn);
        break;
    case 2: // Sign-up
        DrawText("Create an Account", 340, 220, 30, DARKGRAY);
        DrawButton(Done);
        DrawButton(Back);
        break;
    case 3: // Log-in
        DrawText("Log Into Your Account", 320, 220, 30, DARKGRAY);
        DrawButton(Done);
        DrawButton(Back);
        break;
    case 4: // Choose subject
        DrawText("Choose a Subject", 370, 250, 35, DARKGRAY);
        DrawButton(Subject1);
        DrawButton(Subject2);
        DrawButton(Subject3);
        break;
    case 5: // Mathematics difficulty selection
    case 6: // Geography difficulty selection
    case 7: // Science difficulty selection
        DrawText("Choose a Difficulty", 360, 270, 35, DARKGRAY);
        DrawButton(Test1);
        DrawButton(Test2);
        DrawButton(Test3);
        DrawButton(Back);
        break;
    case 8: // Display test
        if (currentTest) currentTest->display();
        DrawButton(Back);
        break;
    case 9: // Score screen
        DrawText("Test Completed!", 400, 300, 35, BLACK);
        DrawText(("Score: " + std::to_string(currentTest->getScore()) + "/20").c_str(), 420, 350, 30, BLACK);
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
    case 2: // Sign-up
        if (IsButtonPressed(Done)) state = 4;
        if (IsButtonPressed(Back)) state = 1;
        break;
    case 3: // Log-in
        if (IsButtonPressed(Done)) state = 4;
        if (IsButtonPressed(Back)) state = 1;
        break;
    case 4: // Choose subject
        if (IsButtonPressed(Subject1)) state = 5;
        else if (IsButtonPressed(Subject2)) state = 6;
        else if (IsButtonPressed(Subject3)) state = 7;
        break;
    case 5: // Math difficulty
        if (IsButtonPressed(Test1)) {
            loadTest(state, "easy");
            state = 8;
        }
        else if (IsButtonPressed(Test2)) {
            loadTest(state, "medium");
            state = 8;
        }
        else if (IsButtonPressed(Test3)) {
            loadTest(state, "hard");
            state = 8;
        }
        if (IsButtonPressed(Back)) state = 4;
        break;
    case 6: // Geography difficulty
        if (IsButtonPressed(Test1)) {
            loadTest(state, "easy");
            state = 8;
        }
        else if (IsButtonPressed(Test2)) {
            loadTest(state, "medium");
            state = 8;
        }
        else if (IsButtonPressed(Test3)) {
            loadTest(state, "hard");
            state = 8;
        }
        if (IsButtonPressed(Back)) state = 4;
        break;
    case 7: // Science difficulty
        if (IsButtonPressed(Test1)) {
            loadTest(state, "easy");
            state = 8;
        }
        else if (IsButtonPressed(Test2)) {
            loadTest(state, "medium");
            state = 8;
        }
        else if (IsButtonPressed(Test3)) {
            loadTest(state, "hard");
            state = 8;
        }
        if (IsButtonPressed(Back)) state = 4;
        break;
    case 8: // Running test
        if (currentTest) {
            currentTest->handleInput(); // Let Test handle input
            if (currentTest->isFinished()) state = 9;
        }
        if (IsButtonPressed(Back)) state = 4;
        break;
    case 9: // Score screen
        if (IsButtonPressed(Back)) state = 4;
        break;
    }
}
void Menu::loadTest(int subjectState, const std::string& difficulty) {
    std::string filename;
    if (subjectState == 5) filename = "math_" + difficulty + ".txt";
    else if (subjectState == 6) filename = "geography_" + difficulty + ".txt";
    else if (subjectState == 7) filename = "science_" + difficulty + ".txt";

    if (currentTest) delete currentTest;  // Delete any previous test
    currentTest = new Test(filename);    // Load the new test
}
