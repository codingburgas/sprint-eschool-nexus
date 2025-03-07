#include "raylib.h"
#include "buttons.h"
#include "menu.h"
#include <iostream>
#include "app.h"

void app() {
    int state = 1;
    Menu menuObj; 

    InitWindow(1000, 800, "NEXUS");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
      
        menuObj.update(state);

        BeginDrawing();
        ClearBackground(DARKGRAY);

        menuObj.draw(state);

        EndDrawing();
    }

    CloseWindow();
}
