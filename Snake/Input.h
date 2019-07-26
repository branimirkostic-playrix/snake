#pragma once
#include <iostream>
#include "Settings.h"

class Input 
{
public:
	enum class MovementDirection
	{
		Stop,
		Left,
		Right,
		Up,
		Down
	};
public:
	void Controller(std::unique_ptr<Settings>& _settings);
	void DirectionController(std::unique_ptr<Settings>& _settings);
private:
	void DirectionChecker(std::unique_ptr<Settings>& _settings, MovementDirection _dir);
public:
	MovementDirection moveDirection = MovementDirection::Stop;
};