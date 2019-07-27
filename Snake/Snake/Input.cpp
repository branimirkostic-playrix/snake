#include <conio.h>
#include "Input.h"

void Input::Controller(std::unique_ptr<Settings>& _settings)
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			DirectionChecker(_settings, MovementDirection::Left);
			break;
		case 'd':
			DirectionChecker(_settings, MovementDirection::Right);
			break;
		case 'w':
			DirectionChecker(_settings, MovementDirection::Up);
			break;
		case 's':
			DirectionChecker(_settings, MovementDirection::Down);
			break;
		case 'x':
			_settings->gameOver = true;
			break;
		}
	}
}

void Input::DirectionController(std::unique_ptr<Settings>& _settings)
{
	switch (this->moveDirection)
	{
	case MovementDirection::Left:
		_settings->snakeXCoord--;
		break;
	case MovementDirection::Right:
		_settings->snakeXCoord++;
		break;
	case MovementDirection::Up:
		_settings->snakeYCoord--;
		break;
	case MovementDirection::Down:
		_settings->snakeYCoord++;
		break;
	default:
		break;
	}
}

// making sure you cannot go behind your tail once you get it
void Input::DirectionChecker(std::unique_ptr<Settings>& _settings, MovementDirection _dir)
{
	if (_settings->score == 0) 
	{
		this->moveDirection = _dir;
	}
	else 
	{
		if (this->moveDirection != MovementDirection::Left && _dir == MovementDirection::Right)
		{
			this->moveDirection = _dir;
		}
		else if (this->moveDirection != MovementDirection::Right && _dir == MovementDirection::Left)
		{
			this->moveDirection = _dir;
		}
		else if (this->moveDirection != MovementDirection::Up && _dir == MovementDirection::Down)
		{
			this->moveDirection = _dir;
		}
		else if (this->moveDirection != MovementDirection::Down && _dir == MovementDirection::Up)
		{
			this->moveDirection = _dir;
		}
	}
}