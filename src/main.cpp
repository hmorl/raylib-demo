#include <raylib.h>
#include <string>

void drawHexagon() {
    Vector2 pos{static_cast<float>(GetMouseX()),
                static_cast<float>(GetMouseY())};

    auto numSides = 6;
    auto radius = 30.0f;
    auto rotation = 0.0f;

    DrawPoly(pos, numSides, radius, rotation, MAROON);
}

void updateWindowTitle() {
    auto text = "raylib-demo [" + std::to_string(GetFPS()) + " FPS]";
    SetWindowTitle(text.c_str());
}

int main() {
    auto screenWidth = 896;
    auto screenHeight = 504;
    InitWindow(screenWidth, screenHeight, "raylib-demo");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(SKYBLUE);
        drawHexagon();

        EndDrawing();

        updateWindowTitle();
    }

    CloseWindow();

    return 0;
}
