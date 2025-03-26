
#ifndef TEST_H
#define TEST_H

#include <vector> 
#include <string>
#include "questions.h" 

#define TOTAL_QUESTIONS 20 // Define a constant for the total number of questions in a test

// Test class declaration
class Test {
private:
    std::vector<Question> questions; // Vector to store the questions for the test
    int currentQuestionIndex; 
    int score; 
    bool finished; 
    std::string filename;
    int selectedOption; 

public:
    Test(const std::string& filename); // Constructor to create a Test object
    void display(); 
    void handleInput(); 
    bool isFinished() const; 
    int getScore() const; 
    std::string getFileName() const; 

private:
    void loadQuestions(const std::string& filename); 
};

#endif // TEST_H