#include <iostream>
using namespace std;

int main()
{
	int testCases, farmers;

	cin >> testCases;
	for (int i = 0; i < testCases; i++)
	{
		int totalPremium = 0, farmSize, numberOfAnimals, enviromentFrendliness;
		cin >> farmers;
		for (int j = 0; j < farmers; j++)
		{
			cin >> farmSize >> numberOfAnimals >> enviromentFrendliness;
			totalPremium += enviromentFrendliness * farmSize;
		}
		cout << totalPremium << endl;
	}
	return 0;
};