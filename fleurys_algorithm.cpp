#include "fleurys_algorithm.h"

void Graph::printGraph()
{
	for (int v = 0; v < V; ++v)
	{
		cout << "\n Adjacency list of vertex "	<< v << "\n head ";
		for (auto x : adj[v])
		{
			cout << "-> " << x;
		}
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

int Graph::isEulerian()
{
	int odd = 0;
	int start_vertex;

	if (isConnected() == false)
	{
		cout << "\nThe undirected graph isn t connected.";
		return -1;
	}

	for (int u = 0; u < V; u++)
	{
		if (adj[u].size() % 2 != 0)
		{
			odd++;
			start_vertex = u;
		}
	}

	if(odd == 2)
	{
		return start_vertex;
	}
	else if (odd == 0)
	{
		return 1;
	}

	return -1;
}

void Graph::PrintEulerTraverse()
{
	if (isEulerian() == 1)
	{
		int u = 0;
		Euler_function(u);
	}
	else if (isEulerian() != 1 && isEulerian() >= 0)
	{
		int u = isEulerian();
		Euler_function(u);
	}
}

void Graph::Euler_function(int u)
{
	list <int>:: iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); i++)
	{
		int v = *i;

		if (v != -2 && IsValidNextEdge(u, v))
		{
			cout << u << " - " << v <<" \n";
			RemoveEdge(u, v);
			Euler_function(v);
		}
	}
}

bool Graph::IsValidNextEdge(int u, int v)
{
	int count = 0;

	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); i++)
	{
		if (*i != -2)
		{
			count++;
		}
	}

	//Daca este doar un nod adiacent selectam muchia corespunzatoare nodului curent si nodului adiacent
	if (count == 1)
	{
		return true;
	}

	for (auto i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	//Numaram nodurile adiacente
	int contor1 = CountVertices(u, visited);
	RemoveEdge(u, v);

	for (auto i = 0; i < V; ++i)
	{
		visited[i] = false;
	}
	int contor2 = CountVertices(u, visited);

	AddEdge(u, v);
	if (contor1 > contor2)
	{
		//the edge is a bridge
		return false;
	}
	else
	{
		return true;
	}
}

int Graph::CountVertices(int u, bool visited[])
{
	    visited[u] = true;
		int count = 1;
		list<int> ::iterator i;

		for (i = adj[u].begin(); i != adj[u].end(); i++)
		{
			if (!visited[*i] && *i != -2)
			{
				count += CountVertices(*i, visited);
			}
		}

	return count;
}

void Graph::RemoveEdge(int u, int v)
{
	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); i++)
	{
		if (*i == v)
		{
		    *i = -2;
		}
	}

	for (i = adj[v].begin(); i != adj[v].end(); i++)
	{
		if (*i == u)
		{
			*i = -2;
		}
	}
}

void Graph::display_message()
{
	//isEulerian();
	if (isEulerian() == 1)
	{
		cout << "\nThe undirected graph has the next euler circuit: \n";
	}
	else if(isEulerian() >= 0 && isEulerian() != 1)
	{
		cout << "\nThe undirected graph has the next euler path: \n";
	}
	return;
}

void test()
{
	Graph g1(4);
	g1.AddEdge(0, 1);
	g1.AddEdge(0, 2);
	g1.AddEdge(1, 2);
	g1.AddEdge(2, 3);
	g1.display_message();
	g1.PrintEulerTraverse();
	auto start = high_resolution_clock::now();
	g1.PrintEulerTraverse();
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	cout << "\nThe duration of the algorithm: " << duration.count() << " microseconds.";

	Graph g2(3);
	g2.AddEdge(0, 1);
	g2.AddEdge(1, 2);
	g2.AddEdge(2, 0);
	g2.display_message();
	start = high_resolution_clock::now();
	g2.PrintEulerTraverse();
	stop = high_resolution_clock::now();

	duration = duration_cast<microseconds>(stop - start);

	cout << "\nThe duration of the algorithm: " << duration.count() << " microseconds.";
	

	Graph g3(5);
	g3.AddEdge(1, 0);
	g3.AddEdge(0, 2);
	g3.AddEdge(2, 1);
	g3.AddEdge(0, 3);
	g3.AddEdge(3, 4);
	g3.AddEdge(3, 2);
	g3.AddEdge(3, 1);
	g3.AddEdge(2, 4);
	g3.display_message();
	start = high_resolution_clock::now();
	g3.PrintEulerTraverse();
	stop = high_resolution_clock::now();

	duration = duration_cast<microseconds>(stop - start);

	cout << "\nThe duration of the algorithm: " << duration.count() << " microseconds.";
	
	
	Graph g4(9);
	g4.AddEdge(0, 2);
	g4.AddEdge(0, 1);
	g4.AddEdge(1, 3);
	g4.AddEdge(1, 5);
	g4.AddEdge(5, 6);
	g4.AddEdge(3, 7);
	g4.AddEdge(6, 8);
	g4.AddEdge(7, 8);
	g4.display_message();
	start = high_resolution_clock::now();
	g4.PrintEulerTraverse();
	stop = high_resolution_clock::now();

	duration = duration_cast<microseconds>(stop - start);

	cout << "\nThe duration of the algorithm: " << duration.count() << " microseconds.";
	

	Graph g5(6);
	g5.AddEdge(0,1);
	g5.AddEdge(1, 2);
	g5.AddEdge(2, 3);
	g5.AddEdge(2, 4);
	g5.AddEdge(4, 5);
	g5.AddEdge(3, 5);
	g5.AddEdge(3, 0);
	g5.display_message();
	start = high_resolution_clock::now();
	g5.PrintEulerTraverse();
	stop = high_resolution_clock::now();

	duration = duration_cast<microseconds>(stop - start);

	cout << "\nThe duration of the algorithm: " << duration.count() << " microseconds.";
	
	
	Graph g6(7);
	g6.AddEdge(0, 1);
	g6.AddEdge(1, 2);
	g6.AddEdge(2, 3);
	g6.AddEdge(2, 4);
	g6.AddEdge(4, 5);
	g6.AddEdge(3, 5);
	g6.AddEdge(3, 0);
	g6.AddEdge(5, 6);
	g6.AddEdge(6, 3);
	g6.display_message();
	start = high_resolution_clock::now();
	g6.PrintEulerTraverse();
	stop = high_resolution_clock::now();

	duration = duration_cast<microseconds>(stop - start);

	cout << "\nThe duration of the algorithm: " << duration.count() << " microseconds.";

	Graph g7(8);
	g7.AddEdge(0, 1);
	g7.AddEdge(1, 2);
	g7.AddEdge(2, 3);
	g7.AddEdge(2, 4);
	g7.AddEdge(4, 5);
	g7.AddEdge(3, 5);
	g7.AddEdge(3, 0);
	g7.AddEdge(5, 6);
	g7.AddEdge(6, 7);
	g7.AddEdge(7, 3);
	g7.display_message();
	start = high_resolution_clock::now();
	g7.PrintEulerTraverse();
	stop = high_resolution_clock::now();

	duration = duration_cast<microseconds>(stop - start);

	cout << "\nThe duration of the algorithm: " << duration.count() << " microseconds.";
}