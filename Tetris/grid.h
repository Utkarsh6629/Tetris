#pragma once
#include<vector>
#include<raylib.h>
using namespace std;

class Grid {
public:
	Grid();
	int grid[20][10];
	void Initialize();
	bool isCellOutside(int row, int col);
	void Draw();
private:
	int rowNum, colNum;
	int cellSize;
	vector<Color> colors;
};