#include<raylib.h>
#include<iostream>
#include "Game.h"
using namespace std;

double lastUpdateTime = 0;

bool EventTriggered(double interval) {
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval) {
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

int main() {
	Color darkBlue = { 44,44,127,255 };
	InitWindow(300, 600, "Tetris");
	Game game = Game();
	SetTargetFPS(60);
	while (WindowShouldClose() == false) {
		BeginDrawing();
		ClearBackground(darkBlue);
		if (EventTriggered(0.2)) {
			game.moveBlockDown();
		}
		game.handleInput();
		game.Draw();
		DrawFPS(10, 10);
		EndDrawing();
	}

	CloseWindow();
}