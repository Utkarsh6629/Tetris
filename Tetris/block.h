#pragma once
#include<vector>
#include<map>
#include "colors.h"
#include "position.h"
using namespace std;
class Block {
public:
	Block();
	void Draw();
	void Move(int rows, int cols);
	vector<Position> getCellsPositions();
	int id;
	void rotate();
	void derotate();
	map<int, vector<Position>> cells;

private:
	int cellSize;
	int rotationState;
	vector<Color> Colors;
	int rowOffset;
	int colOffset;
};
