#pragma once
#include <vector>
#include <queue>
#include <climits>
#include <stack>



enum class PathfinderType
{
	Dijkstras,
	BFS,
	DFS
};

struct PathNode
{
	int x;
	int y;
};

struct QueueNode
{
	int distance;
	PathNode node;
};

struct CompareQueueNode
{
	bool operator()(const QueueNode& a, const QueueNode& b)
	{
		return a.distance > b.distance;
	}
};


struct PathState
{
	bool searching = false;
	bool found = false;
	bool initialized = false;

	PathfinderType currentPath = PathfinderType::Dijkstras;
	
	std::vector<PathNode> visitedNodes;
	std::vector<PathNode> path;

	std::vector<std::vector<int>> distance;
	std::vector<std::vector<PathNode>> previous;

	std::priority_queue<
		QueueNode,
		std::vector<QueueNode>,
		CompareQueueNode
	> openSet;

	std::queue<PathNode> bfsQueue;

	std::stack<PathNode>dfsStack;
};

void UpdatePath(PathState& state);
void ResetPathState(PathState& state);
void DijkstrasStep(PathState& state);
void BFSStep(PathState& state);
void DFSStep(PathState& state);