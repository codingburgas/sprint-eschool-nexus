

#ifndef BUTTONS_H
#define BUTTONS_H

#include "raylib.h"
#include <string>

struct Button {
    Rectangle bounds;
    std::string text;
    Color defaultColor;
    Color hoverColor;
};

void DrawButton(Button button);
bool IsButtonPressed(Button button);

#endif 