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

void Grid::print() {
	for (int row = 0;row < rowNum;row++) {
		for (int col = 0; col < colNum;col++) {
			cout << grid[row][col]<<" ";
		}
		cout << endl;
	}
}



void Grid::Draw() {
	for (int row = 0;row < rowNum;row++) {
		for (int col = 0;col < colNum;col++) {
			int cellValue = grid[row][col];
			DrawRectangle(col * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
		}
	}
}