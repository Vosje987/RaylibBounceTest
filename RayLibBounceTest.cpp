#include "raylib.h"

// Simple raylib physics test

int main(void)
{

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set target fps of the simulation/game...

    Vector2 Position = { 400.0f, 100.0f }; // starting position
    Vector2 Velocity = { 400.0f, 50.0f }; // Starting velocity --> shoot object to a side for testing gravity/bounce

    float Gravity = 980.0f; // gravity, pixel per second
    float radius = 30.0f; // size of object
    float bounce = -0.9f; // energyloss per bounce


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        float DeltaTime = GetFrameTime(); //Get deltatime --> simulation is the same speed for everyone

        Velocity.y += Gravity * DeltaTime; // Velocity needs to be affected by the gravity


        // Update position of object based on velocity
        Position.y += Velocity.y * DeltaTime;
        Position.x += Velocity.x * DeltaTime;

        // right wall
        if (Position.x + radius >= screenWidth)
        {
            Velocity.x *= bounce; // lose 20% of energy on bounce against a wall
            Position.x = screenWidth - radius;
        }

        // bounce floor
        if (Position.y + radius >= screenHeight)
        {
            Velocity.y *= bounce;
            Position.y = screenHeight - radius;
        }

        //left wall
        if (Position.x - radius <=0)
        {
            Velocity.x *= bounce; // lose 20% of energy on bounce against a wall
            Position.x = radius;
        }

        // bounce ceiling
        if (Position.y - radius <=0)
        {
            Velocity.y *= bounce;
            Position.y = screenHeight + radius;
        }


        BeginDrawing();

        ClearBackground(GetColor(0x181818FF));
        
       
        DrawCircleV(Position, radius, MAROON);

     
        DrawLine(0, screenHeight - 1, screenWidth, screenHeight - 1, WHITE);

        
        

        EndDrawing();

    }


    CloseWindow();        // Close window and OpenGL context


    return 0;
}