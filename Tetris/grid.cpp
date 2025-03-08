#include "grid.h"
#include<iostream>
#include<vector>
#include "colors.h"
using namespace std;

Grid::Grid() {
	rowNum = 20;
	colNum = 10;
	cellSize = 30;
	Initialize();
	colors = GetCellColors();
}

void Grid::Initialize() {
	for (int row = 0;row < rowNum;row++) {
		for (int col = 0; col < colNum;col++) {
			grid[row][col] = 0;
		}
	}
}

bool Grid::isCellOutside(int row, int col)
{
	if (row >= 0 && row < rowNum && col >= 0 && col < colNum) {
		return false;
	}
	return true;
}

bool Grid::isCellEmpty(int row, int col)
{
	if (grid[row][col] == 0) {
		return true;
	}
	return false;
}

int Grid::clearFullRows()
{
	int completed = 0;
		for (int row = rowNum - 1;row >= 0;row--) {
			if (isRowFull(row)) {
				clearRow(row);
				completed++;
			}
			else if (completed > 0) {
				moveRowDown(row, completed);
			}
		 }
		return completed;
}




void Grid::Draw() {
	for (int row = 0;row < rowNum;row++) {
		for (int col = 0;col < colNum;col++) {
			int cellValue = grid[row][col];
			DrawRectangle(col * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
		}
	}
}

bool Grid::isRowFull(int row)
{
	for (int col = 0;col < colNum;col++) {
		if (grid[row][col] == 0) {
			return false;
		}
	}
	return true;
}

void Grid::clearRow(int row)
{
	for (int col = 0; col < colNum;col++) {
		grid[row][col] = 0;
	}
}

void Grid::moveRowDown(int row, int numRows)
{
	for (int col = 0; col < colNum;col++) {
		grid[row + numRows][col] = grid[row][col];
		grid[row][col] = 0; 
	}
}
