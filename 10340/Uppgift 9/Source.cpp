#include <iostream>  
#include <string>  

using namespace std;

//Checks if the strings have an equal number of letters that are the exact same and in the same order.
string CheckSubsequence(string s, string t)
{
	int j = 0;
	for (int i = 0; i < t.length(); i++)
	{
		if (s[j] == t[i])
		{
			j++;
		}
	}
	if (j == s.length())
	{
		return "Yes";
	}
	else
	{
		return "No";
	}
}

int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		cout << CheckSubsequence(s, t) << '\n';
	}
	return 0;
}