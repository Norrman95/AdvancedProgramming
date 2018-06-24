#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

const int max = 100;
unsigned int ways[max][max];

//Tabulation dynamic program method that uses knapsack like calculations to determine the ways that we can add.
//We set the initial values, these are based on simple logic.
//We calculate the value of each position based upon the sum of two previous positions.
void Initialize()
{
	for (int i = 0; i <= max; i++)
	{
		ways[1][i] = i;
		ways[i][1] = 1;
	}
	for (int i = 2; i <= max; i++)
	{
		for (int j = 2; j <= max; j++)
		{
			ways[i][j] = (ways[i - 1][j] + ways[i][j - 1]) % 1000000;
		}
	}
}
int main()
{
	int N, K;
	Initialize();

	while (cin >> N >> K && N != 0 && K != 0)
	{
		cout << ways[N][K] << "\n";
	}
	return 0;
}