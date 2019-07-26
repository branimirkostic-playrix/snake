#pragma once
#include "Settings.h"
#include "Input.h"

class Movement 
{
public:
	void Logic(std::unique_ptr<Settings>& _settings, std::unique_ptr<Input>& _input);
private:
	void TailMovement(std::unique_ptr<Settings>& _settings);
	void MovementThroughWall(std::unique_ptr<Settings>& _settings);
	void TailHittingChecker(std::unique_ptr<Settings>& _settings);
	void PickingUpFruit(std::unique_ptr<Settings>& _settings);
};