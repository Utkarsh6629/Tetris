#pragma once
#include "grid.h"
#include "blocks.cpp"
#include <vector>
using namespace std;

class Game{
public:
	Game();
	Block getRandomBlock();
	void handleInput();
	void moveBlockLeft();
	void moveBlockRight();
	void moveBlockDown();
	vector<Block> getAllBlocks();
	void Draw();
	Grid grid;
	bool gameOver;
private:
	bool isBlockOutside();
	void rotateBlock();
	void lockBlock();
	bool blockFits();
	vector<Block> Blocks;
	Block currentBlock;
	Block nextBlock;
	void Reset(); 
};
