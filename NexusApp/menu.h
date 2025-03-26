#ifndef MENU_H
#define MENU_H

#include "buttons.h" 
#include "test.h"    
#include "account.h" 
#include <string>    
class Menu {
private:
    int score;             
    Test* currentTest;     // Pointer to the current Test object
    Account* currentAccount; // Pointer to the current Account object
    std::string usernameInput; // Stores the username input by the user

public:
    Menu(); // Constructor for the Menu class
    void draw(int state); 
    void update(int& state); 
    void loadTest(int subjectState, const std::string& difficulty); 
    void handleUsernameInput(); // Function to handle username input from the keyboard
    void drawScores(); // Function to draw the scoreboard
};

#endif // MENU_H