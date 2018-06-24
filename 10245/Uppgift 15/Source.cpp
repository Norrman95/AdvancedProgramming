#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;
const double infinity = 10000000000.0;

struct Point
{
	double X, Y;
	Point(double x, double y)
	{
		X = x;
		Y = y;
	}
	Point() {}
	bool operator < (Point & b) const
	{
		return X < b.X;
	}
}point[10000];

//Caluclates the distance between the points.
double CalculateDistance(const Point& a, const Point& b)
{
	return sqrt((a.X - b.X)*(a.X - b.X) + (a.Y - b.Y)*(a.Y - b.Y));
}

//Simple bruteforce method were we sort the points in ascending X value.
//We loop through every point and save the smallest one each time.
int main()
{
	int totalPoints;

	while (cin >> totalPoints && totalPoints != 0)
	{
		for (int i = 0; i < totalPoints; i++)
		{
			cin >> point[i].X;
			cin >> point[i].Y;
		}

		sort(point, point + totalPoints);

		double distance = infinity;
		for (int i = 0; i < totalPoints; i++)
		{
			for (int j = i + 1; j < totalPoints; j++)
			{
				distance = min(distance, CalculateDistance(point[i], point[j]));
			}
		}

		if (distance >= 10000)
		{
			cout << "INFINITY" << endl;
		}
		else
		{
			printf("%.4lf\n", distance);
		}
	}
	return 0;
}