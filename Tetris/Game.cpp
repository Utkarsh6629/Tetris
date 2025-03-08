#include "Game.h"
#include <random>
Game::Game() {
	grid = Grid();
	Blocks = getAllBlocks();
	currentBlock = getRandomBlock();
	nextBlock = getRandomBlock();
}
Block Game::getRandomBlock() {
	if (Blocks.empty())
	{
		Blocks = getAllBlocks();
	}
	int randomIndex = rand() % Blocks.size();
	Block block = Blocks[randomIndex];
	Blocks.erase(Blocks.begin() + randomIndex);
	return block;
}

void Game::handleInput(){
	int keyPressed = GetKeyPressed();
	switch (keyPressed) {
	case (KEY_LEFT):
		moveBlockLeft();
		break;
	case (KEY_RIGHT):
		moveBlockRight();
		break;
	case (KEY_DOWN):
		moveBlockDown();
		break;
	case (KEY_UP):
		rotateBlock();
		break;
	}
}

void Game::moveBlockLeft() {
	currentBlock.Move(0, -1);
	if (isBlockOutside()|| blockFits() == false) {
		currentBlock.Move(0, 1);
	}
}

void Game::moveBlockRight() {
	currentBlock.Move(0, 1);
	if (isBlockOutside()|| blockFits() == false) {
		currentBlock.Move(0, -1);
	}
}

void Game::moveBlockDown() {
	currentBlock.Move(1, 0);
	if (isBlockOutside() || blockFits() == false) {
		currentBlock.Move(-1, 0);
		lockBlock();
	}
}



vector<Block> Game::getAllBlocks() {
	return { IBlock(),JBlock(),LBlock(),OBlock(),SBlock(),TBlock(),ZBlock() };
}

void Game::Draw() {
	grid.Draw();
	currentBlock.Draw();
}

bool Game::isBlockOutside()
{
	vector<Position> tiles = currentBlock.getCellsPositions();
	for (Position item : tiles) {
		if (grid.isCellOutside(item.row, item.col)) {
			return true;
		}
	}
		return false;
}

void Game::rotateBlock()
{	
	currentBlock.rotate();
	if (isBlockOutside()) {
		currentBlock.derotate();
	}
}

void Game::lockBlock()
{
	vector<Position> tiles = currentBlock.getCellsPositions();
	for (Position item : tiles) {
		grid.grid[item.row][item.col] = currentBlock.id;
	}
	currentBlock = nextBlock;
	nextBlock = getRandomBlock(); 
	grid.clearFullRows();
}

bool Game::blockFits()
{
	vector<Position> tiles = currentBlock.getCellsPositions();
	for (Position item : tiles) {
		if (grid.isCellEmpty(item.row, item.col) == false) {
			return false;
		}
	}
	return true;	 
}
