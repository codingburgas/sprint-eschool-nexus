// menu.cpp
#include "account.h"
#include "menu.h"
#include "buttons.h"
#include <iostream>
#include "raylib.h"
#include <string>
#include "questions.h"
#include "test.h"
#include <vector>
#include <algorithm>
#include <map>

Menu::Menu() {
    score = 0;
    currentTest = nullptr;
    currentAccount = nullptr;
    usernameInput = "";
}

// Define button colors
Color DARKORANGE = { 200, 100, 0, 255 };

// Button definitions
Button SignUp = { {425, 300, 150, 50}, "  Sign Up ", BLUE, DARKBLUE };
Button LogIn = { {425, 400, 150, 50}, "    Log in ", BLUE, DARKBLUE };
Button Done = { {425, 500, 150, 50}, "    Done ", GREEN, DARKGREEN };
Button Back = { {400, 700, 200, 60}, "  Back", RED, MAROON };
Button Subject1 = { {425, 350, 150, 50}, "Mathematics", PURPLE, DARKPURPLE };
Button Subject2 = { {425, 400, 150, 50}, "Geography", ORANGE, DARKORANGE };
Button Subject3 = { {425, 450, 150, 50}, "Science", SKYBLUE, DARKBLUE };
Button Test1 = { {425, 350, 150, 50}, "  Easy", GREEN, DARKGREEN };
Button Test2 = { {425, 400, 150, 50}, "  Medium", YELLOW, GOLD };
Button Test3 = { {425, 450, 150, 50}, "  Hard", RED, MAROON };
Button Scores = { {425, 600, 150, 50}, " Scores ", VIOLET, DARKPURPLE };

void Menu::draw(int state) {
    ClearBackground(RAYWHITE);
    switch (state) {
    case 1:
        DrawText("Welcome to Nexus", 350, 180, 30, DARKGRAY);
        DrawButton(SignUp);
        DrawButton(LogIn);
        break;
    case 2: // Sign-up
    case 3: // Log-in
        DrawText(state == 2 ? "Create an Account" : "Log Into Your Account", 340, 220, 30, DARKGRAY);
        DrawText("Enter Username:", 350, 270, 20, BLACK);
        DrawText(usernameInput.c_str(), 350, 300, 20, BLACK);
        DrawButton(Done);
        DrawButton(Back);
        break;
    case 4: // Choose subject
        DrawText("Choose a Subject", 370, 250, 35, DARKGRAY);
        DrawButton(Subject1);
        DrawButton(Subject2);
        DrawButton(Subject3);
        DrawButton(Scores);
        break;
    case 5: case 6: case 7: // Difficulty selection
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
    case 10: //Scores page
        drawScores();
        DrawButton(Back);
        break;
    }
}

void Menu::update(int& state) {
    switch (state) {
    case 1:
        if (IsButtonPressed(SignUp)) state = 2;
        if (IsButtonPressed(LogIn)) state = 3;
        break;
    case 2: case 3:
        handleUsernameInput();
        if (IsButtonPressed(Done) && !usernameInput.empty()) {
            if (state == 2) Account::createAccount(usernameInput);
            if (Account::accountExists(usernameInput)) {
                currentAccount = new Account(usernameInput);
                state = 4;
            }
        }
        if (IsButtonPressed(Back)) state = 1;
        break;
    case 4:
        if (IsButtonPressed(Subject1)) state = 5;
        if (IsButtonPressed(Subject2)) state = 6;
        if (IsButtonPressed(Subject3)) state = 7;
        if (IsButtonPressed(Scores)) state = 10;
        break;
    case 5: case 6: case 7:
        if (IsButtonPressed(Test1)) { loadTest(state, "easy"); state = 8; }
        if (IsButtonPressed(Test2)) { loadTest(state, "medium"); state = 8; }
        if (IsButtonPressed(Test3)) { loadTest(state, "hard"); state = 8; }
        if (IsButtonPressed(Back)) state = 4;
        break;
    case 8:
        if (currentTest) {
            currentTest->handleInput();
            if (currentTest->isFinished()) state = 9;
        }
        if (IsButtonPressed(Back)) state = 4;
        break;
    case 9:
        if (currentAccount) currentAccount->updateScore(currentTest->getScore(), currentTest->getFileName());
        if (IsButtonPressed(Back)) state = 4;
        break;
    case 10:
        if (IsButtonPressed(Back)) state = 4;
        break;
    }
}

void Menu::handleUsernameInput() {
    int key = GetCharPressed();
    while (key > 0) {
        if ((key >= 32) && (key <= 125)) {
            usernameInput += (char)key;
        }
        key = GetCharPressed();
    }
    if (IsKeyPressed(KEY_BACKSPACE) && !usernameInput.empty()) {
        usernameInput.pop_back();
    }
}

void Menu::loadTest(int subjectState, const std::string& difficulty) {
    std::string filename;
    if (subjectState == 5) filename = "math_" + difficulty + ".txt";
    else if (subjectState == 6) filename = "geography_" + difficulty + ".txt";
    else if (subjectState == 7) filename = "science_" + difficulty + ".txt";
    if (currentTest) delete currentTest;
    currentTest = new Test(filename);
}

void Menu::drawScores() {
    DrawText("Scores:", 400, 150, 30, BLACK);
    std::vector<std::pair<std::string, std::map<std::string, int>>> scoreList = Account::getDetailedScoreList();
    int y = 200;
    for (const auto& userScores : scoreList) {
        DrawText((userScores.first + ":").c_str(), 400, y, 20, DARKGRAY);
        y += 25;
        int mathScore = 0, geoScore = 0, scienceScore = 0;
        std::map<std::string, int> bestMathScores, bestGeoScores, bestScienceScores;

        for (const auto& testScore : userScores.second) {
            if (testScore.first.find("math") != std::string::npos) {
                if (bestMathScores.find(testScore.first) == bestMathScores.end() || testScore.second > bestMathScores[testScore.first]) {
                    bestMathScores[testScore.first] = testScore.second;
                }
            }
            else if (testScore.first.find("geography") != std::string::npos) {
                if (bestGeoScores.find(testScore.first) == bestGeoScores.end() || testScore.second > bestGeoScores[testScore.first]) {
                    bestGeoScores[testScore.first] = testScore.second;
                }
            }
            else if (testScore.first.find("science") != std::string::npos) {
                if (bestScienceScores.find(testScore.first) == bestScienceScores.end() || testScore.second > bestScienceScores[testScore.first]) {
                    bestScienceScores[testScore.first] = testScore.second;
                }
            }
        }

        for (const auto& score : bestMathScores) mathScore += score.second;
        for (const auto& score : bestGeoScores) geoScore += score.second;
        for (const auto& score : bestScienceScores) scienceScore += score.second;

        DrawText((" Math: " + std::to_string(mathScore)).c_str(), 420, y, 18, GRAY);
        y += 20;
        DrawText((" Geography: " + std::to_string(geoScore)).c_str(), 420, y, 18, GRAY);
        y += 20;
        DrawText((" Science: " + std::to_string(scienceScore)).c_str(), 420, y, 18, GRAY);
        y += 25;
    }
}