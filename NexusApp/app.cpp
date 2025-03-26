
#include "raylib.h"    
#include "buttons.h"  
#include "menu.h"      
#include <iostream>   
#include "app.h"     

// Main application function
void app() {
    int state = 1;      // Initialize the application
    Menu menuObj;       // Create a Menu object

    // Initialize the Raylib window
    InitWindow(1000, 800, "NEXUS"); // Set window size and title
    SetTargetFPS(60);              

    // Main game loop
    while (!WindowShouldClose()) { 

        menuObj.update(state); // Update the menu based on user input and game logic

        BeginDrawing();          // Start drawing on the screen
        ClearBackground(RAYWHITE); 

        menuObj.draw(state);     // Draw the menu based on the current state

        EndDrawing();            // Stop drawing on the screen
    }

    // Close the Raylib window
    CloseWindow();
}