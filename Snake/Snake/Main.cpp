#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <algorithm>

#include "Settings.h"
#include "Input.h"
#include "Renderer.h"
#include "Movement.h"

int main()
{
	std::unique_ptr<Settings> settings = std::make_unique<Settings>();
	std::unique_ptr<Input> input = std::make_unique<Input>();
	std::unique_ptr<Renderer> renderer = std::make_unique<Renderer>();
	std::unique_ptr<Movement> movement = std::make_unique<Movement>();
	while (!settings->gameOver)
	{
		renderer->Draw(settings);
		input->Controller(settings);
		movement->Logic(settings, input);
		Sleep(settings->GetGameSpeed());
	}

	renderer->DrawScoreBoard(settings);
}