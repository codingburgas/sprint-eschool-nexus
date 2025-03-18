// test.h
#ifndef TEST_H
#define TEST_H

#include <vector>
#include <string>
#include "questions.h"

#define TOTAL_QUESTIONS 20 // Define TOTAL_QUESTIONS here
class Test {
private:
    std::vector<Question> questions;
    int currentQuestionIndex;
    int score;
    bool finished;
    std::string filename; // Declare filename as a member

public:
    Test(const std::string& filename);
    void display();
    void handleInput();
    bool isFinished() const;
    int getScore() const;

private:
    void loadQuestions(const std::string& filename);
};

#endif // TEST_H