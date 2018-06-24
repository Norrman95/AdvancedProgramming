#include <iostream>
#include <vector>
using std::vector;

int main()
{
	int stacks;
	int set = 1;

	while (std::cin >> stacks)
	{
		if (stacks == 0)
		{
			return 0;
		}

		int desiredHeight = 0;
		int moves = 0;
		vector<int> blocks;

		for (int i = 0; i < stacks; i++)
		{
			int block;
			std::cin >> block;
			blocks.push_back(block);
			desiredHeight += block;
		}

		desiredHeight /= stacks;

		for (int i = 0; i < stacks; i++)
		{
			if (blocks[i] > desiredHeight)
			{
				moves += blocks[i] % desiredHeight;
			}
		}

		std::cout << "Set #" << set << '\n';
		std::cout << "The minimum number of moves is " << moves << ".\n\n";
		set++;
	}
	return 0;
};