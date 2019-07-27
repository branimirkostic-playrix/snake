#include <windows.h>
#include <iostream>
#include <algorithm>

#include "Renderer.h"

void Renderer::Draw(std::unique_ptr<Settings>& _settings)
{
	system("cls");

	// draw top wall of the arena
	DrawVerticalArenaBorder(_settings);

	std::cout << std::endl;

	for (int i = 0; i < _settings->GetArenaHeight(); i++)
	{
		for (int j = 0; j < _settings->GetArenaWidth(); j++)
		{
			// draw border on the far left side of the arena
			if (j == 0)
			{
				std::cout << visuals.border;
			}

			// draws head of the snake
			if (i == _settings->snakeYCoord && j == _settings->snakeXCoord)
			{
				std::cout << visuals.snake;
			}
			// draws fruit
			else if (i == _settings->fruitYCoord && j == _settings->fruitXCoord)
			{
				std::cout << visuals.fruit;
			}
			else
			{
				bool printTail = false;
				// draws tail of the snake
				if (_settings->score != 0)
				{
					for (int k = 0; k < _settings->score; k++)
					{
						if (_settings->tailXCoord[k] == j && _settings->tailYCoord[k] == i)
						{
							std::cout << visuals.snakeTail;
							printTail = true;
						}
					}
				}
				// draws arena background
				if (!printTail) 
				{
					std::cout << visuals.arenaBakcground;
				}
			}

			// draw border on the far right side of the arena
			if (j == _settings->GetArenaWidth() - 1)
			{
				std::cout << visuals.border;
			}
		}

		std::cout << std::endl;
	}

	// draw bottom wall of the arena
	DrawVerticalArenaBorder(_settings);

	std::cout << std::endl;
	std::cout << "Score:" << _settings->score << std::endl;
}

void Renderer::DrawVerticalArenaBorder(std::unique_ptr<Settings>& _settings)
{
	for (int i = 0; i < _settings->GetArenaWidth() + 2; i++)
	{
		std::cout << this->visuals.border;
	}
}

void Renderer::DrawScoreBoard(std::unique_ptr<Settings>& _settings)
{
	system("cls");

	DrawVerticalArenaBorder(_settings);

	std::cout << std::endl;
	std::string finalScore;
	finalScore = this->visuals.finalScore + std::to_string(_settings->score);

	for (int i = 0; i < _settings->GetArenaHeight(); i++)
	{
		for (int j = 0; j < _settings->GetArenaWidth(); j++)
		{
			if (j == 0)
			{
				std::cout << this->visuals.border;
			}

			if (i == _settings->GetArenaHeight() / 2 && j == 3)
			{
				std::cout << finalScore;
			}

			std::cout << this->visuals.arenaBakcground;

			if (j == _settings->GetArenaWidth() - 1 && i != _settings->GetArenaHeight() / 2)
			{
				std::cout << this->visuals.border;
			}
			if (j == _settings->GetArenaWidth() - finalScore.size() - 1 && i == _settings->GetArenaHeight() / 2)
			{
				std::cout << this->visuals.border;
			}
		}

		std::cout << std::endl;
	}

	DrawVerticalArenaBorder(_settings);
	std::cout << std::endl;
	std::cin.get();
}