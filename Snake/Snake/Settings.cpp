#include <windows.h>
#include "Settings.h"

Settings::Settings() 
{
	this->gameOver = false;
	// setting player starting position on center of the arena
	this->snakeXCoord = this->arenaWidth / 2;
	this->snakeYCoord = this->arenaHeight / 2;
	// randomizes fruit spawn places
	this->fruitXCoord = rand() % this->arenaWidth;
	this->fruitYCoord = rand() % this->arenaHeight;
	// allocates memory for max number of array values (all the slots of the arena - the borders)
	this->tailXCoord.reserve((this->GetArenaHeight() * this->GetArenaWidth()) - (this->GetArenaHeight() + this->GetArenaWidth()));
	this->tailYCoord.reserve((this->GetArenaHeight() * this->GetArenaWidth()) - (this->GetArenaHeight() + this->GetArenaWidth()));
}

int Settings::GetArenaHeight() const
{
	return this->arenaHeight;
}

int Settings::GetArenaWidth() const
{
	return this->arenaWidth;
}

int Settings::GetGameSpeed() const
{
	return this->gameSpeed;
}