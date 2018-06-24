#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

//Recusive calls of this method lets us calculate huge numbers by splitting them up into smaller pieces.
//We continue with the recusive calls untill we reach the point where p is 0, which results in a value of 1.
//If p is uneven we split the equation into two halves and start a new recusive call where we subtract 1 from p to make it even.
//If p is already even we can just split p in halv in the next recusive call. 
//Each of these halves are then multiplied, or in the case of p being even we multiply it with itself.
//On each step of the equation we use modulo so that we can avoid the need for saving extremely large numbers.
long long int CalcBigMod(long long int b, long long int p, long long int m)
{
	if (p == 0)
	{
		return 1;
	}
	else if (p % 2 == 1)
	{
		long long int p1 = b%m;
		long long int p2 = CalcBigMod(b, p - 1, m);
		return(p1 * p2) % m;
	}
	else if (p % 2 == 0)
	{
		long long int p1 = CalcBigMod(b, p / 2, m);
		return(p1 * p1) % m;
	}
}

int main()
{
	long long int B, P, M;

	while (cin >> B >> P >> M)
	{
		cout << CalcBigMod(B, P, M) << "\n";
	}
	return 0;
}
