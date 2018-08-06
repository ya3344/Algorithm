/*
Max Product of Three
*/

#include <math.h>
#include <algorithm>

bool compare(int a, int b)
{
	return abs(a) > abs(b);
}

bool compare2(int a, int b)
{
	return abs(a) < abs(b);
}

int solution(vector<int> &A)
{
	//max Abs
	vector<int> positive;
	vector<int> negative;
	//min Abs
	vector<int> minAbs;

	for (int n : A)
	{
		if (n<0)
		{
			if (negative.size() < 2)
			{
				negative.emplace_back(n);
				sort(negative.begin(), negative.end(), compare);
			}
			else if (negative[1] > n)
			{
				negative[1] = n;
				sort(negative.begin(), negative.end(), compare);
			}
		}
		else
		{
			if (positive.size() < 3)
			{
				positive.emplace_back(n);
				sort(positive.begin(), positive.end(), compare);
			}
			else if (positive[2] < n)
			{
				positive[2] = n;
				sort(positive.begin(), positive.end(), compare);
			}
		}

		if (minAbs.size() < 3)
		{
			minAbs.emplace_back(n);
			sort(minAbs.begin(), minAbs.end(), compare2);
		}
		else if (abs(minAbs[2]) > abs(n))
		{
			minAbs[2] = n;
			sort(minAbs.begin(), minAbs.end(), compare2);
		}
	}

	// +
	if (positive.size() == 3 && negative.size() == 2)
	{
		int temp1 = positive[0] * positive[1] * positive[2];
		int temp2 = positive[0] * negative[0] * negative[1];

		return (temp1 > temp2) ? temp1 : temp2;
	}
	else if (positive.size() == 3)
	{
		return positive[0] * positive[1] * positive[2];
	}
	else if (positive.size() >= 1 && negative.size() == 2)
	{
		return positive[0] * negative[0] * negative[1];
	}

	// -
	else
	{
		return minAbs[0] * minAbs[1] * minAbs[2];
	}
}


/*
Triangle
*/

#include <algorithm>

int solution(vector<int> &A)
{
	if (A.size() < 3)
	{
		return 0;
	}

	sort(A.begin(), A.end());

	for (unsigned int i = 0; i<A.size() - 2; i++)
	{
		if ((long long)A[i] + (long long)A[i + 1] >(long long)A[i + 2])
		{
			return 1;
		}
	}

	return 0;
}

/*
Fish
*/

#include <stack>

int solution(vector<int> &A, vector<int> &B)
{
	stack<int> down;
	int death = 0;

	for (unsigned int i = 0; i<A.size(); i++)
	{
		if (B[i] == 1)
		{
			down.emplace(A[i]);
		}
		else
		{
			while (!down.empty())
			{
				if (down.top() > A[i])
				{
					death++;
					break;
				}
				else
				{
					down.pop();
					death++;
				}
			}
		}
	}

	return A.size() - death;
}

/*
Stone Wall
*/

#include <stack>

int solution(vector<int> &H)
{
	stack<int> block;
	int count = 0;

	for (int n : H)
	{
		while (!block.empty() && block.top() > n)
		{
			block.pop();
		}
		if (!block.empty() && block.top() == n)
		{
			continue;
		}
		else
		{
			block.emplace(n);
			count++;
		}
	}

	return count;
}

/*
Equi Leader
*/

#include <stack>

int solution(vector<int> &A)
{
	stack<int> leaderStack;

	//find leader of A
	for (int n : A)
	{
		if (leaderStack.empty() || leaderStack.top() == n)
		{
			leaderStack.emplace(n);
		}
		else
		{
			leaderStack.pop();
		}
	}

	if (leaderStack.empty())
	{
		return 0;
	}

	const int leader = leaderStack.top();
	int size = A.size();
	int leaderCount = 0;

	for (int n : A)
	{
		if (n == leader)
		{
			leaderCount++;
		}
	}

	if (leaderCount <= size / 2)
	{
		return 0;
	}

	int count = 0;
	int newLeaderCount = 0;
	int newSize = 0;

	for (int n : A)
	{
		newSize++;
		size--;
		if (n == leader)
		{
			newLeaderCount++;
			leaderCount--;
		}

		if (newSize / 2 < newLeaderCount && size / 2 < leaderCount)
		{
			count++;
		}
	}

	return count;
}