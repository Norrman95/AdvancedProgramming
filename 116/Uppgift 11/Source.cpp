#include <algorithm>  
#include <iostream>  
#include <cstdlib>  
#include <cstdio>  

using namespace std;

int totalRows, totalColumns, matrix[11][101], cost[11][101], path[11][101];

//We step through the matrix with recursive calls of this method untill we reach the end of the columns.
//Since we have previously set the base cost to infinity we can check if this is still the case to indicate if the row has been visited to avoid.
//On each step we have to calculate the possible ways that we can go since the matrix rows are circular.
//We use logic similar to DFS to step through the different paths untill we reach the end. 
//After this we start to calculate the cost needed to traverse the different paths.
//If we find a suitable destination we go there, update the cost and path.
int CalculatePath(int row, int column)
{
	if (column >= totalColumns)
	{
		return 0;
	}

	if (cost[row][column] == numeric_limits<int>::max())
	{
		int Dir[3] = { (row == 0) ? totalRows - 1 : row - 1, row, (row == totalRows - 1) ? 0 : row + 1 };

		for (int i = 0; i < 3; i++)
		{
			int currentCost = matrix[row][column] + CalculatePath(Dir[i], column + 1);

			if (cost[row][column] > currentCost || (cost[row][column] == currentCost && path[row][column] > Dir[i]))
			{
				cost[row][column] = currentCost;
				path[row][column] = Dir[i];
			}
		}
	}
	return cost[row][column];
}

//Create the matrix and set the cost to infinity.
//We step through each row and calculate the path from that point.
//If the cost is lower on that row we save the row to be used later.
int main()
{
	while (cin >> totalRows >> totalColumns)
	{
		for (int i = 0; i < totalRows; i++)
		{
			for (int j = 0; j < totalColumns; j++)
			{
				cin >> matrix[i][j];
				cost[i][j] = numeric_limits<int>::max();;
			}
		}

		int minimumPath, pathCost = numeric_limits<int>::max();
		for (int i = 0; i < totalRows; i++)
		{
			CalculatePath(i, 0);
			if (cost[i][0] < pathCost)
			{
				pathCost = cost[i][0];
				minimumPath = i;
			}
		}

		//Starting from the lowest cost row we step through the matrix and follow the path that has been previously set.
		for (int i = 0; i < totalColumns; i++)
		{
			(i > 0) ? cout << ' ' << (minimumPath + 1) : cout << (minimumPath + 1);
			minimumPath = path[minimumPath][i];
		}
		cout << '\n' << pathCost << '\n';
	}
	return 0;
}