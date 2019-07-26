#include <iostream>
#include <conio.h>

#include "Movement.h"

void Movement::Logic(std::unique_ptr<Settings>& _settings, std::unique_ptr<Input>& _input)
{
	TailMovement(_settings);

	_input->DirectionController(_settings);

	MovementThroughWall(_settings);

	TailHittingChecker(_settings);

	PickingUpFruit(_settings);
}

void Movement::TailMovement(std::unique_ptr<Settings>& _settings)
{
	int prevX = _settings->tailXCoord[0];
	int prevY = _settings->tailYCoord[0];

	int prev2X;
	int prev2Y;
	_settings->tailXCoord[0] = _settings->snakeXCoord;
	_settings->tailYCoord[0] = _settings->snakeYCoord;
	for (int i = 1; i < _settings->score; i++)
	{
		prev2X = _settings->tailXCoord[i];
		prev2Y = _settings->tailYCoord[i];
		_settings->tailXCoord[i] = prevX;
		_settings->tailYCoord[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
}

void Movement::MovementThroughWall(std::unique_ptr<Settings>& _settings)
{
	if (_settings->snakeXCoord >= _settings->GetArenaWidth())
	{
		_settings->snakeXCoord = 0;
	}
	else if (_settings->snakeXCoord < 0)
	{
		_settings->snakeXCoord = _settings->GetArenaWidth() - 1;
	}

	if (_settings->snakeYCoord >= _settings->GetArenaWidth())
	{
		_settings->snakeYCoord = 0;
	}
	else if (_settings->snakeYCoord < 0)
	{
		_settings->snakeYCoord = _settings->GetArenaWidth() - 1;
	}
}

void Movement::TailHittingChecker(std::unique_ptr<Settings>& _settings)
{
	for (int i = 0; i < _settings->score; i++)
	{
		if (_settings->tailXCoord[i] == _settings->snakeXCoord && _settings->tailYCoord[i] == _settings->snakeYCoord)
		{
			_settings->gameOver = true;
		}
	}
}

void Movement::PickingUpFruit(std::unique_ptr<Settings>& _settings)
{
	if (_settings->snakeXCoord == _settings->fruitXCoord && _settings->snakeYCoord == _settings->fruitYCoord)
	{
		_settings->score++;
		_settings->fruitXCoord = rand() % _settings->GetArenaWidth();
		_settings->fruitYCoord = rand() % _settings->GetArenaHeight();
	}
}
