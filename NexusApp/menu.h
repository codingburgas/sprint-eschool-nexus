#ifndef MENU_H
#define MENU_H

#include "buttons.h"
#include <string>
#include "test.h" // Include test.h if you use Test in the header.

class Menu {
private:
    int score; // Declare score as a member variable
    Test* currentTest; // Declare currentTest pointer
public:
    Menu();
    void draw(int state);
    void update(int& state);
    void loadTest(int subjectState, const std::string& difficulty);
};

#endif // MENU_H