#include "grid.h"
#include<iostream>
#include<vector>
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

vector<Color> Grid::GetCellColors() {
	Color darkGrey = { 26,31,40,255 };
	Color green = { 47,230,23,255 };
	Color red = { 232,18,18,255 };
	Color orange = { 236,116,17,255 };
	Color yellow = { 237,234,4,255 };
	Color purple = { 166,0,247,255 };
	Color  cyan = { 21,204,209,255 };
	Color  blue = { 13,64,216,255 };

	return { darkGrey,green,red,orange,yellow,purple,cyan,blue };
}

void Grid::Draw() {
	for (int row = 0;row < rowNum;row++) {
		for (int col = 0;col < colNum;col++) {
			int cellValue = grid[row][col];
			DrawRectangle(col * cellSize + 1, row * cellSize + 1, cellSize, cellSize, colors[cellValue]);
		}
	}
}