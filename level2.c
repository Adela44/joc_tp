#include "raylib.h"
#include "level1.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
#define BLOCK_SIZE 50
#define MAZE_ROWS (SCREEN_HEIGHT / BLOCK_SIZE)
#define MAZE_COLS (SCREEN_WIDTH / BLOCK_SIZE)

static Rectangle player;  //sa fie vazut doar aici in fisier
static bool won = false;
static int maze[MAZE_ROWS][MAZE_COLS] = {{0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1},
                                      {1,0,1,1,0,1,0,1,1,1,1,1,1,0,1,1},
                                      {1,0,1,0,0,1,0,0,0,1,1,0,0,0,1,1},
                                      {1,0,1,0,1,1,1,1,0,1,1,0,1,1,1,1},
                                      {1,0,1,0,0,0,0,0,0,1,1,0,0,0,1,1},
                                      {1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1},
                                      {1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1},
                                      {1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1},
                                      {1,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1},
                                      {0,0,1,0,0,0,1,1,1,0,0,0,0,1,1,1},
                                      {1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1},
                                      {1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1},
                                      {1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,1},
                                      {1,1,1,1,0,1,0,0,0,0,0,1,0,1,0,1},
                                      {1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1},
                                      {1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0}};
static bool visible[MAZE_ROWS][MAZE_COLS] = {0};

void InitLevel2()
{
    player = (Rectangle){0,0,25,25};
    won = false;
}

void GameLevel2()
{
    int speed = 5;
     if (!won) {
        Rectangle prevPlayer = player;


       if (IsKeyDown(KEY_RIGHT) && player.x + speed <= SCREEN_WIDTH - player.width)
       {
            player.x += speed;
       }
        if (IsKeyDown(KEY_LEFT) && player.x - speed >= 0)
        {
            player.x -= speed;
        }
        if (IsKeyDown(KEY_DOWN) && player.y + speed <= SCREEN_HEIGHT - player.height)
        {
            player.y += speed;
        }
        if (IsKeyDown(KEY_UP) && player.y - speed >= 0)
        {
            player.y -= speed;
        }
        Rectangle goal = {750, 750, BLOCK_SIZE, BLOCK_SIZE};

        for (int row = 0; row < MAZE_ROWS; row++)
        {
            for (int col = 0; col < MAZE_COLS; col++)
            {
                if (maze[row][col] == 1)
                {
                    Rectangle block = {col * BLOCK_SIZE, row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE};
                    if (CheckCollisionRecs(player, block))
                    {
                        visible[row][col] = true;
                        player = prevPlayer;
                    }
                }
            }
        }
         if (CheckCollisionRecs(player, goal))
            {
                won = true;
            }
        }

        ClearBackground(RAYWHITE);

        for (int row = 0; row < MAZE_ROWS; row++) {
            for (int col = 0; col < MAZE_COLS; col++) {
                if (maze[row][col] == 1 && visible[row][col]) {
                    DrawRectangle(col * BLOCK_SIZE, row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, GRAY);
                }
            }
        }

        DrawRectangleRec(player, BLACK);
}

bool isLevel2Won()
{
    return won;
}
