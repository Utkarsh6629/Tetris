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
private:
	bool isBlockOutside();
	void rotateBlock();
	vector<Block> Blocks;
	Block currentBlock;
	Block nextBlock;
};
