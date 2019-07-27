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
	if (_settings->score != 0)
	{
		this->prevX = _settings->tailXCoordd[0];
		this->prevY = _settings->tailYCoordd[0];
		this->prev2X;
		this->prev2Y;

		_settings->tailXCoordd.at(0) = _settings->snakeXCoord;
		_settings->tailYCoordd.at(0) = _settings->snakeYCoord;
		for (int i = 1; i < _settings->score; i++)
		{
			this->prev2X = _settings->tailXCoordd[i];
			this->prev2Y = _settings->tailYCoordd[i];
			_settings->tailXCoordd[i] = this->prevX;
			_settings->tailYCoordd[i] = this->prevY;
			this->prevX = this->prev2X;
			this->prevY = this->prev2Y;
		}
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
	if (_settings->score != 0)
	{
		for (int i = 0; i < _settings->score; i++)
		{
			if (_settings->tailXCoordd[i] == _settings->snakeXCoord && _settings->tailYCoordd[i] == _settings->snakeYCoord)
			{
				_settings->gameOver = true;
			}
		}
	}
}

void Movement::PickingUpFruit(std::unique_ptr<Settings>& _settings)
{
	if (_settings->snakeXCoord == _settings->fruitXCoord && _settings->snakeYCoord == _settings->fruitYCoord)
	{
		_settings->score++;
		if (_settings->score == (_settings->GetArenaHeight() * _settings->GetArenaWidth()) - (_settings->GetArenaHeight() + _settings->GetArenaWidth()))
		{
			_settings->gameOver = true;
		}

		_settings->tailXCoordd.push_back(_settings->snakeXCoord);
		_settings->tailYCoordd.push_back(_settings->snakeYCoord);
		_settings->fruitXCoord = rand() % _settings->GetArenaWidth();
		_settings->fruitYCoord = rand() % _settings->GetArenaHeight();
	}
}
