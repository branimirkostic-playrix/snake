#pragma once
#include "Settings.h"
#include "Visuals.h"

class Renderer
{
public:
	void Draw(std::unique_ptr<Settings>& _settings);
	void DrawScoreBoard(std::unique_ptr<Settings>& _settings);
private:
	void DrawVerticalArenaBorder(std::unique_ptr<Settings>& _settings);
private:
	Visuals visuals;
};