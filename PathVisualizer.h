#pragma once
#include "PathfindingAlgorithms.h"

class PathVisualizer
{
public:
	
	PathVisualizer();

	void HandleInput();
	void Update();
	void Draw() const;

private:

	PathState pathState;

	void DrawPath() const;
};
