#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	char input[50];
	while (gets_s(input))
	{
		//Skip the edges.
		if (input[0] != '|') continue;

		//Assign bit value, will be shifted later to represent different letters from the ascii table.
		int bit = 128;
		char output = 0;

		for (int i = 0; i < input[i]; i++)
		{
			//Shift the bits right to decrease the number.  
			if (input[i] == ' ')
			{
				bit >>= 1;
			}
			//If a "hole" is found we save the bits to construct the final letter. 
			else if (input[i] == 'o')
			{
				output += bit;
				bit >>= 1;
			}
		}
		//Prints the saved bits and automatically converts it to a letter from the ascii table.
		printf("%c", output);
	}
	return 0;
}