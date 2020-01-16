#pragma once
#include <iostream>
//#include <conio.h>
#include<vector>
#include <list>
using namespace std;
#define VERTICES  5

void traverse(int start_node, bool visited[VERTICES]);
bool isStronglyConnected(int graph[VERTICES][VERTICES]);
bool isEulerCircuit(int graph[VERTICES][VERTICES]);
void test();

