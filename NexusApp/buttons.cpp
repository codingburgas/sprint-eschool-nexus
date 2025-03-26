
#include "buttons.h"

// Draws a button on the screen
void DrawButton(Button button) {
    // Get the current mouse position
    Vector2 mousePoint = GetMousePosition();


    Color buttonColor = (CheckCollisionPointRec(mousePoint, button.bounds)) ? button.hoverColor : button.defaultColor;

  
    DrawRectangleRec(button.bounds, buttonColor);

    
    DrawText(button.text.c_str(), button.bounds.x + 20, button.bounds.y + 15, 20, BLACK);
}

// Checks if a button has been pressed 
bool IsButtonPressed(Button button) {

    Vector2 mousePoint = GetMousePosition();

    return CheckCollisionPointRec(mousePoint, button.bounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}