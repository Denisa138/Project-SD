#include "eulerian_directed_graph.h"

void traverse(int start_node, bool visited[VERTICES])
{
	visited[start_node] = true;

	for (int next_node = 0; next_node < VERTICES; next_node++)
	{
		if (visited[next_node] == false)
		{
			traverse(next_node, visited);
		}
	}
}

bool isStronglyConnected(int graph[VERTICES][VERTICES])
{
	bool visited[VERTICES];

	for (int u = 0; u < VERTICES; u++)
	{
		visited[u] = false;
		traverse(u, visited);
	}

	for (int u = 0; u < VERTICES; u++)
	{
		if (!visited[u])
		{
			return false;
		}
	}

	return true;
}

bool isEulerCircuit(int graph[VERTICES][VERTICES])
{
	int sum = 0;

	if (!isStronglyConnected(graph))
	{
		return false;
	}

	vector<int> inward(VERTICES);
	vector<int>  outward(VERTICES);

	for (int i = 0; i < VERTICES; i++)
	{
		sum = 0;

		for (int j = 0; j < VERTICES; j++)
		{
			if (graph[j][i] == 1)
			{
				inward[i]++;
				sum++;
			}
		}

		outward[i] = sum;
	}

	if (inward == outward)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test()
{
	int graph[VERTICES][VERTICES] = { {0, 1, 0, 0, 0},
									  {0, 0, 1, 0, 0},
									  {0, 0, 0, 1, 1},
									  {1, 0, 0, 0, 0},
									  {0, 0, 1, 0, 0} };


	(isEulerCircuit(graph)) ? cout << " The graph is Eulerian" : cout << "The graph isn't Eulerian";
}