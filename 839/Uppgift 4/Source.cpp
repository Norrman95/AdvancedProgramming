#include <iostream>
#include <stdio.h>

using namespace std;
bool balanced;

//Recursive method used to check if the sides are balanced. 
int Checkbalance()
{
	//Create and assign the intial values.
	int weightLeft, distanceLeft, weightRight, distanceRight;
	cin >> weightLeft >> distanceLeft >> weightRight >> distanceRight;

	//If the weights are 0 this means that there is a set of weights hanging there.
	//Assign the weight of this side based on the weights below by recursive calls of the method.
	if (weightLeft == 0)
	{
		weightLeft = Checkbalance();
	}
	if (weightRight == 0)
	{
		weightRight = Checkbalance();
	}

	//If the downward force is unequal the balance is off.
	if (weightLeft * distanceLeft != weightRight * distanceRight)
	{
		balanced = false;
	}

	return weightLeft + weightRight;
}

int main()
{
	int testCases;
	cin >> testCases;

	while(testCases--)
	{
		balanced = true;
		Checkbalance();

		//If the recursion is completed without balanced being set to false print YES, otherwise NO.
		puts(balanced ? "YES" : "NO");

		if (testCases)
		{
			puts("");
		}
	}
	return 0;
}