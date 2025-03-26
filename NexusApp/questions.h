#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <string> 
#include <vector> 

// Structure to represent a question
struct Question {
    std::string questionText; 
    std::vector<std::string> options; 
    int correctAnswerIndex; 

    // Constructor to initialize a Question object
    Question(const std::string& text, const std::vector<std::string>& opts, int correctIdx)
        : questionText(text), options(opts), correctAnswerIndex(correctIdx) {
    } 
};

#endif