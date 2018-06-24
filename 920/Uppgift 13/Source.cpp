#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point
{
	float X, Y;
	bool operator < (Point & b) const
	{
		return X > b.X;
	}
}; Point point[100];

//Calculates the distance between two points.
float CalcDistance(Point a, Point b)
{
	return sqrt((a.X - b.X)*(a.X - b.X) + (a.Y - b.Y)*(a.Y - b.Y));
}

//Points are sorted in descending order of their X value.
//Loop through and for each new point with a greater Y value than the previously highest point calculate the new length of the side of the mountain.
//Then we remove the portion of the slope that is blocked by the previously highest peak. 
int main()
{
	int testCases, totalPairs, maxY;
	float x, y, output, slope, prevSlope;
	cin >> testCases;

	while (testCases--)
	{
		cin >> totalPairs;
		for (int i = 0; i < totalPairs; i++)
		{
			cin >> x;
			cin >> y;
			point[i].X = x;
			point[i].Y = y;
		}
		sort(point, point + totalPairs);
		
		maxY = point[0].Y;
		output = 0;

		for (int i = 1; i < totalPairs; i++)
		{
			if (point[i].Y > maxY)
			{
				slope = CalcDistance(point[i], point[i - 1]);
				prevSlope = (point[i].Y - maxY) / (point[i].Y - point[i - 1].Y);
				output += slope * prevSlope;
				maxY = point[i].Y;
			}
		}
		printf("%.2lf\n", output);
	}
	return 0;
};