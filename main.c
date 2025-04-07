#include <stdio.h>
#include "raylib.h"
#include <stdlib.h>



int main(void)
{
    const int  lungime = 800;
    const int latime = 800;
    InitWindow(latime,lungime,"Proiect joc");
    SetTargetFPS(60);
    Rectangle player = {5,5,25,25}; //x,y,latime,lungime patrat
    Rectangle square = {100,200,100,100};
    int speed = 5;
    int ok = 0;
    while (!WindowShouldClose()) {
        if(IsKeyDown(KEY_RIGHT))
        {
            if (player.x + speed  <= 775){
                player.x += speed;
            }
            if (CheckCollisionRecs(player, square)){
                player.x -= speed;
                ok = 1;
            }
        }
        if(IsKeyDown(KEY_LEFT))
        {
            if(player.x - speed >= 0){
                player.x -= speed;
            }
            if (CheckCollisionRecs(player, square)){
                player.x += speed;
                ok = 1;
            }

        }
        if(IsKeyDown(KEY_DOWN))
        {
            if(player.y + speed <= 775){
                player.y += speed;
            }
            if (CheckCollisionRecs(player, square)){
                player.y -= speed;
                ok = 1;
            }

        }
        if(IsKeyDown(KEY_UP))
        {
            if(player.y - speed >=0){
                player.y -= speed;
            }
            if (CheckCollisionRecs(player, square)){
                player.y += speed;
                ok = 1;
            }

        }
        if(ok == 1)
        {
            DrawRectangleRec(square,GRAY);
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(player,BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
