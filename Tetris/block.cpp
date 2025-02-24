#include "block.h"
using namespace std;

Block::Block() {
	cellSize = 30;
	rotationState = 0;
	Colors = GetCellColors();
}

void Block::Draw() {
	vector<Position> tiles = cells[rotationState];
	for (Position items : tiles) {
		DrawRectangle(items.col * cellSize + 1, items.row * cellSize + 1, cellSize - 1, cellSize - 1, Colors[id]);
	}
}