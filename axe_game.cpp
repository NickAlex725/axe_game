#include "raylib.h"

int main()
{
    // window dimensions
    int width = 800;
    int height = 450;

    InitWindow(width, height, "Nicks window");

    // circle stats
    int circle_x = 200;
    int circle_y = 200;
    int circle_radius = 20;
    int circle_move_speed = 7;

    // axe cords
    int axe_x = 400;
    int axe_y = 0;
    int axe_height = 50;
    int axe_width = 50;
    int axe_direction = 10;

    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        //  game logic begins

        DrawCircle(circle_x, circle_y, circle_radius, BLUE);
        DrawRectangle(axe_x, axe_y, axe_width, axe_height, RED);

        // move the axe
        axe_y += axe_direction;
        if((axe_y + axe_height) > height || axe_y < 0)
        {
            axe_direction = -axe_direction;
        }

        if(IsKeyDown(KEY_D) && (circle_x + circle_radius) < width)
        {
            circle_x += circle_move_speed;
        }
        if(IsKeyDown(KEY_A) && (circle_x - circle_radius) > 0)
        {
            circle_x -= circle_move_speed;
        }

        // game logic ends
        EndDrawing();
    }
}