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
	bool isCellEmpty(int row, int col);
	int clearFullRows();
	void Draw();
private:
	int rowNum, colNum;
	int cellSize;
	bool isRowFull(int row);
	void clearRow(int row);
	void moveRowDown(int row, int numRows);
	vector<Color> colors;
};