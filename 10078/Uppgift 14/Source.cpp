#include <iostream>
#include <math.h>
using namespace std;

struct Corner
{
	int X, Y;
	Corner() {}
	Corner(int x, int y)
	{
		X = x;
		Y = y;
	}
}corners[50];

//Calculates the crossproduct of the two vertices created by the three corners.
float CrossProduct(Corner a, Corner b, Corner c)
{
	return (b.X - a.X) * (c.Y - a.Y) - (c.X - a.X) * (b.Y - a.Y);
}

//First we create all the corners of the building and set some fixed values to make the looping easier.
//We loop through and calculate the crossproducts of the building corners. 
//If any of the crossproducts is negative it means that the building isnt convex and we can break the loop.
int main()
{
	int totalCorners, x, y;

	while (cin >> totalCorners && totalCorners != 0)
	{
		for (int i = 0; i < totalCorners; i++)
		{
			cin >> x;
			cin >> y;
			corners[i] = Corner(x, y);
		}
		corners[totalCorners] = corners[0];
		corners[totalCorners + 1] = corners[1];


		bool convex = true;
		int temp1 = CrossProduct(corners[0], corners[1], corners[2]);

		for (int i = 1; i < totalCorners; i++)
		{
			int temp2 = temp1;
			temp1 = CrossProduct(corners[i], corners[i + 1], corners[i + 2]);

			if (temp2 * temp1 < 0)
			{
				convex = false;
				break;
			}
		}
		if (convex)
		{
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
	}
	return 0;
};