#include <algorithm>  
#include <iostream>  
#include <cstdlib>  
#include <string>  
#include <cstdio>  
#include <queue> 

using namespace std;

string maze[55];
int mazeDist[55][55]; 
int setRank[105];
int set[105];
int	testCases, totalWeight, x, y;

typedef struct Edge
{
	int source;
	int destination;
	int weight;
	Edge(int Source, int Destination, int Weight)
	{
		source = Source;
		destination = Destination;
		weight = Weight;
	}
	Edge() {}
	bool operator < (Edge & b) const
	{
		return weight < b.weight;
	}
}
Edge;
Edge edge[5555];

typedef struct Vertex
{
	int x, y;
	Vertex(int X, int Y)
	{
		x = X; y = Y;
	}
	Vertex() {}
}
Vertex;
Vertex vertex[105];

int Find(int a)
{
	if (a != set[a])
	{
		set[a] = Find(set[a]);
	}
	return set[a];
}

void Union(int a, int b)
{
	if (setRank[a] < setRank[b])
	{
		set[a] = b;
	}
	else
	{
		if (setRank[a] == setRank[b])
		{
			setRank[a] ++;
		}
		set[b] = a;
	}
}

//First we sort the edges by weight.
//Set the initial values of the ranks and sets.
//Check if the source and destination of each vertex is part of the same set. 
//If they are not union them to make them part of the same set and assign a setrank in the "tree".
//Save the weights so that we can print it later. 
void Kruskal(int n, int m)
{
	sort(edge, edge + m);

	for (int i = 0; i <= n; i++)
	{
		setRank[i] = 0;
		set[i] = i;
	}

	totalWeight = 0;
	for (int i = 0; i < m; i++)
	{
		int source = Find(edge[i].source);
		int destination = Find(edge[i].destination);
		if (source != destination)
		{
			Union(source, destination);
			totalWeight += edge[i].weight;
		}
	}
}

//Assign values to the possible directions that the aliens can take in the graph.
int xDir[4] = { 1, -1, 0, 0 };
int yDir[4] = { 0, 0, 1, -1 };
//Assign the distances of the vertices to "infinity".
//Add create a queue and add the initial vertex to it. Set the distance to the initial vertex to 0.
//While the queue isnt empty assign a new source then remove it from the list. 
//Step through the possible variations of the directions in the graph. If this destination has not been visited and if it is not a wall go there.
//Assign the new weight in the dist array based on the cost of the source. Add the accepted destination to the queue of sources. 
void BFS(Vertex source)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			mazeDist[i][j] = numeric_limits<int>::max();
		}
	}

	queue<Vertex>que;
	que.push(source);

	mazeDist[source.x][source.y] = 0;

	while (!que.empty())
	{
		Vertex destination, source = que.front();
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			destination = Vertex(source.x + xDir[i], source.y + yDir[i]);

			if (maze[destination.x][destination.y] != '#' && mazeDist[destination.x][destination.y] == numeric_limits<int>::max())
			{
				mazeDist[destination.x][destination.y] = mazeDist[source.x][source.y] + 1;
				que.push(destination);
			}
		}
	}
}

int main()
{
	cin >> testCases;
	while (testCases--)
	{
		cin >> x >> y;
		getchar();
		for (int i = 0; i < y; i++)
		{
			getline(cin, maze[i]);
		}

		//Checks how many vertecises there are in the graph.
		int vertexCount = 0;
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				if (maze[i][j] == 'A' || maze[i][j] == 'S')
				{
					vertex[vertexCount++] = Vertex(i, j);
				}
			}
		}

		//Checks how many edges there are in the graph.
		//Create a weighted graph by the use of BFS.
		int edgeCount = 0;
		for (int i = 0; i < vertexCount; i++)
		{
			BFS(vertex[i]);

			for (int j = i + 1; j < vertexCount; j++)
			{
				edge[edgeCount++] = Edge(i, j, mazeDist[vertex[j].x][vertex[j].y]);
			}
		}

		Kruskal(vertexCount, edgeCount);
		cout << totalWeight << endl;
	}
	return 0;
}