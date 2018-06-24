#include <iostream>
#include <stdio.h> 
#include <string>
#include <string.h>
#include <cstring>
using namespace std;

string input, equationPart[3];

int rValue[128], nValue[3], solutions, variables;
char visited[128], firstLetter[128];
const char *rLetter = "IVXLCDM";

//Values of the different roman letters.
void RomanValue()
{
	rValue['I'] = 1;
	rValue['V'] = 5;
	rValue['X'] = 10;
	rValue['L'] = 50;
	rValue['C'] = 100;
	rValue['D'] = 500;
	rValue['M'] = 1000;
}
//Resets everything between the loops.
void Initialize()
{
	RomanValue();
	solutions = 0, variables = 0;
	memset(nValue, 0, sizeof(nValue));
	memset(visited, 0, sizeof(visited));
	memset(firstLetter, 0, sizeof(firstLetter));
	memset(equationPart, 0, sizeof(equationPart));
}
//Reverse iterator of a string. Converts the letter to the assigned value while also handling potential minus.
int ConvertToNumerals(string& s)
{
	int value = 0, prev = 0;
	int sLength = s.length() - 1;

	for (int i = sLength; i >= 0; i--)
	{
		if (rValue[s[i]] >= prev)
		{
			value += rValue[s[i]];
		}
		else
		{
			value -= rValue[s[i]];
		}
		prev = rValue[s[i]];
	}
	return value;
}
//Steps through and divides the input string into different more manageable parts.
//If its the first letter of that part we save it to the firstLetter to avoid setting it to 0 later on.
//Uses the array visited to keep track of unique roman letters.
//When the "sorting" is completed we convert them to numerals and check if the equation is correct or not.
bool CheckCorrectness()
{
	Initialize();
	int currentString = 0, first = 1;

	for (unsigned int i = 0; i < input.length(); i++)
	{
		if (input[i] == '+' || input[i] == '=')
		{
			currentString++;
			first = 1;
			continue;
		}

		equationPart[currentString] += input[i];

		if (first)
		{
			firstLetter[input[i]] = 1;
			first = 0;
		}
		if (!visited[input[i]])
		{
			visited[input[i]] = 1;
			variables++;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		nValue[i] = ConvertToNumerals(equationPart[i]);
	}
	return (nValue[0] + nValue[1] == nValue[2]);
}
//Creates a new number from the input, each time adding another zero.
int CreateNumber(string& s)
{
	int temp = 0;
	for (unsigned int i = 0; i < s.length(); i++)
	{
		temp = temp * 10 + rValue[s[i]];
	}
	return temp;
}
//Dfs like method where we check the different solutions to the equation.
//When the all the unique variables have been loaded in we test the possible solutions then we end that loop.
//If a solution was found we increment the solutions variable that later decides the numeral encodings.
//If all variables have been exhausted we end that loop, otherwise we search for new ones.
//We assign different values to the letters, these will be used at the start of another DFS eventually.
//Each time we increment a and b to keep track of how many variables we have used and where to start looking for the next.
void DFS(int a, int b)
{
	if (a == variables)
	{
		int n1 = CreateNumber(equationPart[0]);
		int n2 = CreateNumber(equationPart[1]);
		int n3 = CreateNumber(equationPart[2]);

		if (n1 + n2 == n3)
		{
			solutions++;
		}
		return;
	}
	if (b >= 7)
	{
		return;
	}

	while (!visited[rLetter[b]])
	{
		b++;
	}

	if (b < 7)
	{
		for (int i = 0; i <= 9; i++)
		{
			if (i == 0 && firstLetter[rLetter[b]])
			{
				continue;
			}

			rValue[rLetter[b]] = i;

			DFS(a + 1, b + 1);

			if (solutions >= 2)
			{
				return;
			}
		}
	}
}

int main()
{
	while (getline(cin, input) && input[0] != '#')
	{
		cout << (CheckCorrectness() ? "Correct " : "Incorrect ");

		DFS(0, 0);

		if (solutions == 1)
		{
			cout << "valid" << endl;
		}
		else if (solutions > 1)
		{
			cout << "ambiguous" << endl;
		}
		else
		{
			cout << "impossible" << endl;
		}
	}
	return 0;
}