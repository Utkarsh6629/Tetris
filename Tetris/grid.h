#pragma once

class Grid {
public:
	Grid();
	int grid[20][10];
	void Initialize();
	void print();
private:
	int rowNum, colNum;
	int cellSize;
};