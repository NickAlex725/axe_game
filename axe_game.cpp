#include "raylib.h"

int main()
{
    // window dimensions
    int width = 800;
    int height = 450;

    InitWindow(width, height, "Axe Game");

    // circle stats
    int circle_x = 200;
    int circle_y = 200;
    int circle_radius = 25;
    int circle_move_speed = 7;
    // circle edges
    int l_circle_x = circle_x - circle_radius;
    int r_circle_x = circle_x + circle_radius;
    int t_circle_y = circle_y - circle_radius;
    int b_circle_y = circle_y + circle_radius;

    // axe cords
    int axe_x = 400;
    int axe_y = 0;
    int axe_height = 50;
    int axe_width = 50;
    int axe_direction = 10;
    // axe edges
    int l_axe_x = axe_x;
    int r_axe_x = axe_x + axe_width;
    int t_axe_y = axe_y;
    int b_axe_y = axe_y + axe_height;

    bool collision_with_axe = (b_axe_y >= t_circle_y) &&
                              (t_axe_y <= b_circle_y) &&
                              (l_axe_x <= r_circle_x) &&
                              (r_axe_x >= l_circle_x);

    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if(collision_with_axe)
        {
            DrawText("Game Over!", 400, 200, 20, RED);
        }
        else
        {
            //  game logic begins

            // update the edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            t_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_width;
            t_axe_y = axe_y;
            b_axe_y = axe_y + axe_height;
            // update collision with axe
            collision_with_axe = (b_axe_y >= t_circle_y) &&
                                 (t_axe_y <= b_circle_y) &&
                                 (l_axe_x <= r_circle_x) &&
                                 (r_axe_x >= l_circle_x);

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
        }
        EndDrawing();
    }
}