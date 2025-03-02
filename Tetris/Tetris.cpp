#include<raylib.h>
#include<iostream>
#include "Game.h"

using namespace std;

int main() {
	Color darkBlue = { 44,44,127,255 };
	InitWindow(300, 600, "Tetris");
	Game game = Game();
	SetTargetFPS(60);
	while (WindowShouldClose() == false) {
		BeginDrawing();
		ClearBackground(darkBlue);
		game.handleInput();
		game.Draw();
		DrawFPS(10, 10);
		EndDrawing();
	}

	CloseWindow();
}