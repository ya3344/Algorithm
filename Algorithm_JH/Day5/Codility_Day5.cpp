#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>
using namespace std;


/*
PAINLESS
Lesson12: ChocolatesByNumbers
There are N chocolates in a circle. Count the number of chocolates you will eat.
*/
int GCD(int a, int b, int res)
{
	if (a == b)
		return res * a;
	else if (a % 2 == 0 && b % 2 == 0)
		return GCD(a / 2, b / 2, 2 * res);
	else if (a % 2 == 0)
		return GCD(a / 2, b, res);
	else if (b % 2 == 0)
		return GCD(a, b / 2, res);
	else if (a > b)
		return GCD(a - b, b, res);
	else
		return GCD(a, b - a, res);
}


int ChocolatesByNumbers(int N, int M)
{
	int GCDNum = GCD(N, M, 1);
	int LCMNum = N / GCDNum;

	return LCMNum;
}

/*
Lesson 13: FibFrog
Count the minimum number of jumps required for a frog to get to the other side of a river.
*/


vector<size_t> gFibonachiSpace;

void Fibonachi(size_t size)
{
	gFibonachiSpace.reserve(size);

	for (size_t i = 0; i <= size; i++)
	{
		if (i <= 1)
		{
			gFibonachiSpace.emplace_back(i);
		}
		else
		{
			size_t fibonachiNum = gFibonachiSpace[i - 1] + gFibonachiSpace[i - 2];
			if (fibonachiNum > size)
				break;

			gFibonachiSpace.emplace_back(fibonachiNum);
		}
	}
}


int FibFrog(vector<int> &A) 
{
	size_t N = A.size();

	int minNum = 0;
	int position = -1;

	Fibonachi(N);

	for (size_t i = 0; i < N; i++)
	{
		if (A[i] == 1)
		{

		}
	}

	return minNum;
}

/*
Lesson14:
MinMaxDivision
Divide array A into K blocks and minimize the largest sum of any block.
*/

inline int Max(int a, int b)
{
	return a > b ? a : b;
}

bool DivisionSolvable(int mid, int K, vector<int>& A)
{
	int sum = 0;

	for (size_t i = 0; i < A.size(); i++)
	{
		sum += A[i];

		if (sum > mid)
		{
			sum = A[i];
			--K;
		}

		if (K < 0)
			return false;
	}

	return true;
}

int MinMaxDivision(int K, int M, vector<int> &A) 
{
	int maxNum = 0;
	int max = 0;
	int result = 0;

	for (size_t i = 0; i < A.size(); i++)
	{
		max += A[i];
		maxNum = Max(maxNum, A[i]);
	}

	result = max;

	while (maxNum <= max)
	{
		int mid = (maxNum + max) / 2;

		if (DivisionSolvable(mid, K - 1, A))
		{
			max = mid - 1;
			result = mid;
		}
		else
		{
			maxNum = mid + 1;
		}
	}

	return result;
}

/*
Lesson16: MaxNonoverlappingSegments
*/
int MaxNonoverlappingSegments(vector<int> &A, vector<int> &B) 
{
	size_t size = A.size();
	size_t maxCount = 1;
	size_t prevIndex = 0;

	if (size <= 1)
		return 0;

	for (size_t i = 1; i < size; i++)
	{
		if (A[i] > B[prevIndex])
		{
			++maxCount;
			prevIndex = i;
		}
	}

	return maxCount;
}

/*
Lesson17:NumberSolitaire 
*/
int NumberSolitaire(vector<int> &A)
{
	size_t size = A.size();
	size_t resultIndex = 0;
	size_t resultSum = 0;

	map<int, int, greater<int>> positiveIndexSpace;
	typedef pair<int, int> positivePair;

	for (size_t i = 0; i < size; i++)
	{
		positiveIndexSpace.emplace(positivePair(A[i], i));
	}

	for (positivePair pair : positiveIndexSpace)
	{
		resultIndex += pair.second;

		if (pair.second != 0)
		{
			resultSum += A[resultIndex];
		}
		else
		{
			resultSum += pair.first;
		}
		
		if (resultIndex == size-1)
		{
			break;
		}
		if (resultIndex > size-1)
		{
			resultIndex -= pair.second;

			if (pair.second != 0)
			{
				resultSum -= A[resultIndex];
			}
			else
			{
				resultSum -= pair.first;
			}
		}
	}

	return resultSum;
}

void main()
{
	////cout << ChocolatesByNumbers(10, 4) << endl
	//vector<int> A = { 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, };
	//cout << FibFrog(A) << endl;

	vector<int> A = { 1, -2, 0, 9, -1, -2 };

	cout << NumberSolitaire(A) << endl;
}