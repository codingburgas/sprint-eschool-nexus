
#include "test.h"
#include "questions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "raylib.h"

// Constructor for the Test class.
Test::Test(const std::string& filename)
    : currentQuestionIndex(0), score(0), finished(false), filename(filename), selectedOption(-1) {
    // Load questions from the specified file.
    loadQuestions(filename);
}

// Loads questions from a file into the 'questions' vector.
void Test::loadQuestions(const std::string& filename) {
    std::ifstream file(filename);
  

    std::string line;
    // Read questions from the file until the end or until 'TOTAL_QUESTIONS' are loaded.
    while (getline(file, line) && questions.size() < TOTAL_QUESTIONS) {
        std::string questionText = line;
        std::vector<std::string> options;
        int correctIndex = -1;

        // Read four options for each question.
        for (int i = 0; i < 4; i++) {
            if (!getline(file, line)) break;
            options.push_back(line);
        }

        std::string correctIndexStr;
        // Read the correct answer index from the file.
        if (getline(file, correctIndexStr)) {
            try {
                correctIndex = std::stoi(correctIndexStr);
            }
            catch (std::exception& e) {
                // Print an error message if the answer index is invalid.
                std::cerr << "Error: Invalid answer index in file " << filename << std::endl;
                correctIndex = -1;
            }
        }

        // If the question data is valid   create a Question object and add it to the vector
        if (!questionText.empty() && options.size() == 4 && correctIndex >= 0 && correctIndex < 4) {
            questions.emplace_back(questionText, options, correctIndex);
        }
    }
    file.close();
}

// Displays the current question and options on the screen
void Test::display() {
    if (finished || currentQuestionIndex >= questions.size()) return;

    ClearBackground(RAYWHITE);
    Question& q = questions[currentQuestionIndex];

    // Draw the question text.
    DrawText(q.questionText.c_str(), 100, 100, 20, BLACK);

    // Draw the options with selection circles.
    for (int i = 0; i < 4; i++) {
        Color optionColor = DARKGRAY;
        Vector2 circlePos = { 100, 160 + i * 40 };

        // Draw a filled circle if the option is selected, an empty circle otherwise .
        if (selectedOption == i) {
            DrawCircle(circlePos.x + 10, circlePos.y + 5, 7, GREEN);
        }
        else {
            DrawCircle(circlePos.x + 10, circlePos.y + 5, 7, DARKGRAY);
        }

        // Draw the option text.
        DrawText((std::to_string(i + 1) + ". " + q.options[i]).c_str(), 120, 160 + i * 40, 20, optionColor);
    }
}

void Test::handleInput() {
    if (finished) return;

    // Handle key press for selecting an option (1-4)
    for (int i = 0; i < 4; i++) {
        if (IsKeyPressed(KEY_ONE + i)) {
            selectedOption = i;
        }
    }

    // Confirm the selected option with Enter key.
    if (IsKeyPressed(KEY_ENTER) && selectedOption != -1) {
        // Check if the selected option is correct.
        if (selectedOption == questions[currentQuestionIndex].correctAnswerIndex) {
            score++;
        }
        currentQuestionIndex++;

        // Reset selectedOption 
        selectedOption = -1;

        // Check if the test is finished.
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