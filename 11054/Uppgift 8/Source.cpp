#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int a[1000000];

int main()
{
	long long int n, output, bottles;

	while (cin >> n && n != 0)
	{
		bottles = 0, output = 0;
		//Assign the bottles that the citizens are willing to trade etc.
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		//We step through each citizen and add the amount of bottles that are traded.
		//Then we add the current absolute value of the bottles to simulate the need for movment between the houses.
		for (int i = 0; i < n; i++)
		{
			output += abs(bottles);

			bottles += a[i];
		}
		cout << output << '\n';
	}
	return 0;
}
