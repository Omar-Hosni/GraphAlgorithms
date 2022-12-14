#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


class Graph {
	int V;
	list<int>* adj;

	void toplogicalSortUtil(int v, bool visited[], stack<int>& myStack);

public:
	Graph(int v);

	void addEdge(int v, int w);

	void topologicalSortPrint();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::toplogicalSortUtil(int v, bool visited[], stack<int>& myStack)
{
	visited[v] = true;

	list<int>::iterator it;

	for (it = adj[v].begin(); it != adj[v].end(); it++)
	{
		if (!visited[*it])
		{
			toplogicalSortUtil(*it, visited, myStack);
		}
	}

	myStack.push(v);
}

void Graph::topologicalSortPrint()
{
	stack<int> myStack;

	bool* visited = new bool[V];

	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	for (int i = 0; i < V; i++)
	{
		if (visited[i] == false)
		{
			toplogicalSortUtil(i, visited, myStack);
		}
	}

	while (!myStack.empty())
	{
		cout << myStack.top() << " ";
		myStack.pop();
	}
}

int main()
{
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	cout << "GRAPH AFTER SORTING..." << endl;
	g.topologicalSortPrint();
}
