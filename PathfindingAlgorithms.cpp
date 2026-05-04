#include "PathfindingAlgorithms.h"
#include "Maze.h"
#include "Dijkstras.h"
#include "BFS.h"
#include "DFS.h"


void UpdatePath(PathState& state)
{
	if (!state.searching || state.found)
		return;

	switch (state.currentPath)
	{
		case PathfinderType::Dijkstras:
			DijkstrasStep(state);
			break;

		case PathfinderType::BFS:
			BFSStep(state);
			break;

		case PathfinderType::DFS:
			DFSStep(state);
			break;
	}
}

void ResetPathState(PathState& state)
{
	state.searching = false;
	state.found = false;
	state.initialized = false;

	state.visitedNodes.clear();
	state.path.clear();

	state.distance.clear();
	state.previous.clear();

	while (!state.openSet.empty())
		state.openSet.pop();
}