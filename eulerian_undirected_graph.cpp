#include "eulerian_undirected_graph.h"
#define V 5

bool visited[V];

void Graph::printGraph()
{
	for (int v = 0; v < V; ++v)
	{
		cout << "\n Adjacency list of vertex "
			<< v << "\n head ";
		for (auto x : adj[v])
			cout << "-> " << x;
		printf("\n");
	}
}

void Graph::AddEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::DFS(int v)
{
	visited[v] = true;

	list<int> ::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); i++)
	{
		if (!visited[*i])
		{
			DFS(*i);
		}
	}
}

bool Graph::isConnected()
{
   for (int u = 0; u < V; u++)
	{
		visited[u] = false;
	}

	 for (int u = 0; u < V; u++)
	 {
		 DFS(u);
	 }

	for (int u = 0; u < V; u++)
	{
		if (visited[u] == false)
		{
			return false;
		}
	}
	return true;
}

void Graph::isEulerian()
{
	int odd = 0;
	bool flag = true;

	if (isConnected() == false)
	{
		cout << "\nThe undirected graph isn t connected.";
		return;
	}

	for (int u = 0; u < V; u++)
	{
		if (adj[u].size() % 2 != 0)
		{
			flag = false;

			if ((u == 0) || (u == V - 1))
			{
                	odd++;
			}
		}
	}

	if ((flag == false) && (odd == 2))
	{
		cout << "\nThe undirected graph has an eulerian path.";
	}
	else if(flag == true)
	{
		cout << "\nThe undirected graph has an eulerian circuit.";
	}
}

void test2()
{
	cout << "\n-----------g1--------------";
	Graph g1(5);
	g1.AddEdge(1, 0);
	g1.AddEdge(0, 2);
	g1.AddEdge(2, 1);
	g1.AddEdge(0, 3);
	g1.AddEdge(3, 4);

	g1.isEulerian();

	cout << "\n-----------g2--------------";
    Graph g2(5);
	
	g2.AddEdge(1, 0);
	g2.AddEdge(0, 2);
	g2.AddEdge(2, 1);
	g2.AddEdge(0, 3);
	g2.AddEdge(3, 4);
	g2.AddEdge(4, 0);
	
	g2.isEulerian();
	//g2.printGraph();
}



/*void Graph::DFS(int v, bool visited[])
{
	visited[v] = true;

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); i++)
	{
		if (!visited[*i])
		{
			DFS(*i, visited);
		}
	}
}*/
