#ifndef BUTTONS_H
#define BUTTONS_H

#include "raylib.h" 
#include <string>  

// Structure to represent a button
struct Button {
    Rectangle bounds;    
    std::string text;    
    Color defaultColor;
    Color hoverColor;   
};

// Function to draw a button on the screen
void DrawButton(Button button);

// Function to check if a button is pressed
bool IsButtonPressed(Button button);

#endif 