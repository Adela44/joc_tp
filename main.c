#include <stdio.h>
#include "raylib.h"
#include "level1.h"
#include "level2.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800


typedef enum {
    LEVEL1,
    LEVEL2,
    END,

}GameLevel;

int main(void) {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Blind Maze");
    SetTargetFPS(60);

    GameLevel currentLevel = LEVEL1;
    InitLevel1();

    while(!WindowShouldClose()) {
        BeginDrawing();

        switch(currentLevel)
        {
            case LEVEL1:
                GameLevel1();
                if (isLevel1Won())
                {
                    currentLevel = LEVEL2;
                    InitLevel2();
                }
                break;

            case LEVEL2:
                GameLevel2();
                if (isLevel2Won())
                {
                    currentLevel = END;
                }
                break;

            case END:
                ClearBackground(RAYWHITE);
                DrawText("You finished all levels!", 200, 400, 40, DARKBLUE);
                break;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
