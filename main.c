#include <stdio.h>
#include "raylib.h"
#include <stdlib.h>

int main(void)
{
  const int  lungime = 800;
  const int latime =800;
  InitWindow(latime,lungime,"Proiect joc");
  SetTargetFPS(60);
  Rectangle square = {5,5,25,25}; //x,y,latime,lungime patrat
  int speed = 5;
  while (!WindowShouldClose()) {
        if(IsKeyDown(KEY_RIGHT))
         {
             if (square.x + speed  <= 775){
             square.x += speed;
             }
         }
        if(IsKeyDown(KEY_LEFT))
        {
              if(square.x - speed >= 0){
             square.x -= speed;
              }
        }
        if(IsKeyDown(KEY_DOWN))
       {
             if(square.y + speed <= 775){
              square.y += speed; 
             }          
         }
        if(IsKeyDown(KEY_UP))
       {
            if(square.y - speed >=0){
            square.y -= speed;
            }
       }
        BeginDrawing();
        ClearBackground(RAYWHITE);
       DrawRectangleRec(square, BLACK);
       // DrawText("Joc",400, 300,40, DARKGRAY);//pozx,pozy,font
        EndDrawing();
    }
  

   CloseWindow();
   return 0;
}
