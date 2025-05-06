#include <stdio.h>
#include "raylib.h"
#include <stdlib.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
#define BLOCK_SIZE 100
#define MAZE_ROWS (SCREEN_HEIGHT / BLOCK_SIZE)
#define MAZE_COLS (SCREEN_WIDTH / BLOCK_SIZE)

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Maze Touch Reveal");
    SetTargetFPS(60);

    Rectangle player = {0, 0, 25, 25};
    int speed = 5;
     bool won = false;

    int maze[MAZE_ROWS][MAZE_COLS] = {{0,0,0,0,0,0,1,1},
                                      {1,0,1,1,1,0,1,1},
                                      {1,0,0,0,1,0,1,1},
                                      {1,1,1,0,1,0,0,0},
                                      {0,0,0,0,0,1,1,1},
                                      {0,1,1,0,1,0,0,0},
                                      {0,0,0,1,0,0,1,0},
                                      {0,1,0,0,0,1,1,0}};
    bool visible[MAZE_ROWS][MAZE_COLS] = {0};



    while (!WindowShouldClose())
    {
        if (!won) {
        Rectangle prevPlayer = player;

   
       if (IsKeyDown(KEY_RIGHT) && player.x + speed <= SCREEN_WIDTH - player.width)
            player.x += speed;
        if (IsKeyDown(KEY_LEFT) && player.x - speed >= 0)
            player.x -= speed;
        if (IsKeyDown(KEY_DOWN) && player.y + speed <= SCREEN_HEIGHT - player.height)
            player.y += speed;
        if (IsKeyDown(KEY_UP) && player.y - speed >= 0)
            player.y -= speed;

        Rectangle goal = {700, 700, BLOCK_SIZE, BLOCK_SIZE};
 
        for (int row = 0; row < MAZE_ROWS; row++) {
            for (int col = 0; col < MAZE_COLS; col++) {
                if (maze[row][col] == 1) {
                    Rectangle block = {col * BLOCK_SIZE, row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE};
                    if (CheckCollisionRecs(player, block)) {
                        // Reveal the block
                        visible[row][col] = true;
                        // Revert movement
                        player = prevPlayer;
                    }
                }
            }
        }
         if (CheckCollisionRecs(player, goal)) {
                won = true;
            }
        }

        
        BeginDrawing();
        ClearBackground(RAYWHITE);

      
        for (int row = 0; row < MAZE_ROWS; row++) {
            for (int col = 0; col < MAZE_COLS; col++) {
                if (maze[row][col] == 1 && visible[row][col]) {
                    DrawRectangle(col * BLOCK_SIZE, row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, GRAY);
                }
            }
        }
         if (won) {
            DrawText("Felicitari, ai castigat!", SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/2 - 20, 40, DARKGREEN);
        }

        DrawRectangleRec(player, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
