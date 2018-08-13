/*
Count Factors
*/
#include <math.h>

int solution(int N)
{
	int count = 0;
	int range = (int)sqrt(N);

	for (int i = 1; i <= range; i++)
	{
		if (N%i == 0)
		{
			count += 2;
		}
	}
	if (range * range == N)
	{
		count--;
	}

	return count;

}



/*
Max Profit
*/

int solution(vector<int> &A)

{
	int buy = -1;
	int maxProfit = 0;

	for (int price : A)
	{
		if (buy == -1)
		{
			buy = price;
		}
		if (buy > price)
		{
			buy = price;
		}
		else
		{
			if (maxProfit < price - buy)
			{
				maxProfit = price - buy;
			}
		}
	}

	return maxProfit;
}

/*
Count Non Divisible
*/
#include <math.h>

vector<int> solution(vector<int> &A)
{
	int N = A.size();
	int max = 2 * A.size();

	vector<int> table;
	table.resize(max + 1, 0); // 0 ~ 2N

	vector<int> countTable;
	countTable.resize(max + 1, 0);

	for (int n : A)
	{
		countTable[n]++;
	}

	for (int n : A)
	{
		if (countTable[n] > 0)
		{
			for (int j = 1; n*j <= max; j++)
			{
				table[n*j] += countTable[n];
			}
			countTable[n] = 0;
		}
	}

	vector<int> result;
	result.resize(N);
	for (int i = 0; i<(int)A.size(); i++)
	{
		result[i] = N - table[A[i]];
	}

	return result;
}
