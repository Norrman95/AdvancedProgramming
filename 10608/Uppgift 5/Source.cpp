#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int>graph[40000];
bool visited[40000];
int testCases, totalCitizens, totalPairs, output, tempCount, u, v;

//DFS like method. Set the initial point to true. Count the friends of this group.
//If there are neighbouring points that have not already been visited go there with recursive calls of this method.
void DFS(int u)
{
	visited[u] = true;
	tempCount++;

	for (int i = 0; i < graph[u].size(); i++)
	{
		int v = graph[u][i];
		if (!visited[v])
		{
			DFS(v);
		}
	}
	return;
}

int main()
{
	cin >> testCases;

	while (testCases--)
	{
		output = 0;
		cin >> totalCitizens >> totalPairs;
		for (int i = 0; i < totalPairs; i++)
		{
			cin >> u >> v;
			//A array of vectors is used to simulate a graph.
			//The graph is connected by pushing each pair of friends into the others vector.
			//This results in each person having a list of their friends that can later be used to step through.
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		for (int i = 1; i <= totalCitizens; i++)
		{
			//Skips the starting point if it has already been visited. 
			//Saves the currently largest group of friends for later output.
			if (!visited[i])
			{
				tempCount = 0;
				DFS(i);

				output = (output > tempCount) ? output : tempCount;
			}
		}

		cout << output << "\n";

		//Resets everything for next loop.
		for (int i = 1; i <= totalCitizens; i++)
		{
			graph[i].clear();
		}
		for (int i = 0; i <= totalCitizens; i++)
		{
			visited[i] = 0;
		}
	}
	return 0;
}
