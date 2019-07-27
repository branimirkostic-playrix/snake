#pragma once
#include <vector>

class Settings
{
public:
	Settings();

	int GetArenaWidth() const;
	int GetArenaHeight() const;
	int GetGameSpeed() const;

public:
	bool gameOver;
	std::vector<int> tailXCoord;
	std::vector<int> tailYCoord;
	int score = 0;
	int snakeXCoord;
	int snakeYCoord;
	int fruitXCoord;
	int fruitYCoord;
private:
	const int arenaWidth = 20;
	const int arenaHeight = 20;
	int gameSpeed = 40; // the greater the value the slower the game
};