#pragma once
#include <iostream>
#include<vector>
#include <list>
using namespace std;

class Graph {
private:
	int V;
	list<int>* adj;
public:
	Graph(int v = 0) : V(v)
	{
		adj = new list<int>[V];
	}

	void printGraph();
	void AddEdge(int u, int v);
	void isEulerian();
	bool isConnected();
	void DFS(int v);

	~Graph()
	{
		delete[]adj;
	}
};

void test2();