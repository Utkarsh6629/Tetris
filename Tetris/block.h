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
	int id;
	map<int, vector<Position>> cells;

private:
	int cellSize;
	int rotationState;
	vector<Color> Colors;
};
