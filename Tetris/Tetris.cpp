#include<raylib.h>
#include "grid.h"
#include<iostream>

using namespace std;

int main() {
	Color darkBlue = { 44,44,127,255 };
	InitWindow(300, 600, "Tetris");
	Grid grid = Grid();
	grid.print();
	SetTargetFPS(60);
	while (WindowShouldClose() == false) {
		BeginDrawing();
		ClearBackground(darkBlue);
		DrawFPS(10, 10);
		EndDrawing();
	}

	CloseWindow();
}