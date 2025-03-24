// test.cpp
#include "test.h"
#include "questions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "raylib.h"

Test::Test(const std::string& filename)
    : currentQuestionIndex(0), score(0), finished(false), filename(filename), selectedOption(-1) {
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
        // Draw the circle next to each option (if it's selected, fill it)
        Vector2 circlePos = { 100, 160 + i * 40 };
        if (selectedOption == i) {
            DrawCircle(circlePos.x + 10, circlePos.y + 5, 7, GREEN); // Filled circle when selected
        }
        else {
            DrawCircle(circlePos.x + 10, circlePos.y + 5, 7, DARKGRAY); // Empty circle
        }

        // Draw the option text next to the circle
        DrawText((std::to_string(i + 1) + ". " + q.options[i]).c_str(), 120, 160 + i * 40, 20, optionColor);
    }
}

void Test::handleInput() {
    if (finished) return;

    // Handle key press for selecting an option
    for (int i = 0; i < 4; i++) {
        if (IsKeyPressed(KEY_ONE + i)) {
            selectedOption = i;  // Update selected option when a key is pressed
        }
    }

    // Confirm the selected option with Enter key
    if (IsKeyPressed(KEY_ENTER) && selectedOption != -1) {
        // Check if the selected option is correct
        if (selectedOption == questions[currentQuestionIndex].correctAnswerIndex) {
            score++;
        }
        currentQuestionIndex++;

        // Reset selectedOption for the next question
        selectedOption = -1;

        if (currentQuestionIndex >= TOTAL_QUESTIONS) {
            finished = true;
        }
    }
}

bool Test::isFinished() const {
    return finished;
}

int Test::getScore() const {
    return score;
}

std::string Test::getFileName() const {
    return filename;
}