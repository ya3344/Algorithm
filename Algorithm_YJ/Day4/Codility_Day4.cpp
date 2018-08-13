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