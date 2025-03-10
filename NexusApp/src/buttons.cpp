#include "buttons.h"
void DrawButton(Button button) {
    Vector2 mousePoint = GetMousePosition();
    Color buttonColor = (CheckCollisionPointRec(mousePoint, button.bounds)) ? button.hoverColor : button.defaultColor;

    DrawRectangleRec(button.bounds, buttonColor);
    DrawText(button.text.c_str(), button.bounds.x + 20, button.bounds.y + 15, 20, BLACK);
}


bool IsButtonPressed(Button button) {
    Vector2 mousePoint = GetMousePosition();
    return CheckCollisionPointRec(mousePoint, button.bounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}
