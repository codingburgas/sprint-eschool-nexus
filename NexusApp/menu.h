// menu.h
#ifndef MENU_H
#define MENU_H

#include "buttons.h"
#include "test.h"
#include "account.h"
#include <string>

class Menu {
private:
    int score; // Declare score as a member variable
    Test* currentTest; // Declare currentTest pointer
    Account* currentAccount;
    std::string usernameInput;
public:
    Menu();
    void draw(int state);
    void update(int& state);
    void loadTest(int subjectState, const std::string& difficulty);
    void handleUsernameInput();
    void drawScores();
};

#endif // MENU_H