#pragma once
#include<vector>
#include<raylib.h>
using namespace std;

class Grid {
public:
	Grid();
	int grid[20][10];
	void Initialize();
	void print();
	void Draw();
private:
	vector<Color> GetCellColors();
	int rowNum, colNum;
	int cellSize;
	vector<Color> colors;
};