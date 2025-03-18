// test.cpp
#include "test.h"
#include "questions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "raylib.h"

Test::Test(const std::string& filename) : currentQuestionIndex(0), score(0), finished(false), filename(filename) {
    loadQuestions(filename);
}

void Test::loadQuestions(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    std::string line;
    while (getline(file, line) && questions.size() < TOTAL_QUESTIONS) {
        std::string questionText = line;
        std::vector<std::string> options;
        int correctIndex = -1;

        for (int i = 0; i < 4; i++) {
            if (!getline(file, line)) break;
            options.push_back(line);
        }

        std::string correctIndexStr;
        if (getline(file, correctIndexStr)) {
            try {
                correctIndex = std::stoi(correctIndexStr);
            }
            catch (std::exception& e) {
                std::cerr << "Error: Invalid answer index in file " << filename << std::endl;
                correctIndex = -1;
            }
        }

        if (!questionText.empty() && options.size() == 4 && correctIndex >= 0 && correctIndex < 4) {
            questions.emplace_back(questionText, options, correctIndex);
        }
    }
    file.close();
}

void Test::display() {
    if (finished || currentQuestionIndex >= questions.size()) return;

    ClearBackground(RAYWHITE);
    Question& q = questions[currentQuestionIndex];

    DrawText(q.questionText.c_str(), 100, 100, 20, BLACK);

    for (int i = 0; i < 4; i++) {
        Color optionColor = DARKGRAY;
        DrawText((std::to_string(i + 1) + ". " + q.options[i]).c_str(), 120, 160 + i * 40, 20, optionColor);
    }
}

void Test::handleInput() {
    if (finished) return;

    for (int i = 0; i < 4; i++) {
        if (IsKeyPressed(KEY_ONE + i)) {
            if (i == questions[currentQuestionIndex].correctAnswerIndex) {
                score++;
            }
            currentQuestionIndex++;
            if (currentQuestionIndex >= TOTAL_QUESTIONS) {
                finished = true;
            }
        }
    }
}
bool Test::isFinished() const {
    return finished;
}

int Test::getScore() const {
    return score;
}