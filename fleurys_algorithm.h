#pragma once
#include <iostream>
#include<string.h>
#include<vector>
#include <chrono> 
using namespace std::chrono;
#include <list>
using namespace std;

class Graph {
private:
	int V;
	list<int>* adj;
	bool *visited;
public:
	Graph(int v = 0) : V(v)
	{
		adj = new list<int>[V];
		visited = new bool[V];
	}
	
	void printGraph();
	void AddEdge(int u, int v);
	int isEulerian();
	bool isConnected();
	void DFS(int v);
	void PrintEulerTraverse();
	void Euler_function(int);
	bool IsValidNextEdge(int u, int v);
	int CountVertices(int u, bool visited[]);
	void RemoveEdge(int u, int v);
	void display_message();

	~Graph()
	{
		delete[]adj;
		delete[]visited;
	}
};

void test();