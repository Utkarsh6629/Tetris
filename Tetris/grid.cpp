#include "grid.h"
#include<iostream>
using namespace std;

Grid::Grid() {
	rowNum = 20;
	colNum = 10;
	cellSize = 30;
	Initialize();
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