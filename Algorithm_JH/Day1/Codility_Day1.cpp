#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <set>
using namespace std;

/*
BinaryGap
Find longest sequence of zeros in binary representation of an integer.
*/
int binaryGap(int N) 
{
	stack<int> binarySpace;
	size_t count = 0;
	size_t maxCount = 0;
	size_t bCountCheck = 0;
	size_t binaryNum = 0;

	while (N != 1)
	{
		binarySpace.emplace(N % 2);
		N = N / 2;

		if (N == 1)
		{
			binarySpace.emplace(N);
		}
	}

	while (!binarySpace.empty())
	{
		binaryNum = binarySpace.top();

		if (binaryNum == 1)
		{
			++bCountCheck;
		}

		if (bCountCheck == 1)
		{
			if (binaryNum == 0)
			{
				++count;
			}
		}
		else if (bCountCheck == 2)
		{
			if (count > maxCount)
			{
				maxCount = count;
			}
			bCountCheck = 1;
			count = 0;
		}

		binarySpace.pop();
	}

	return maxCount;	
}

/*
CyclicRotation
Rotate an array to the right by a given number of steps
*/
vector<int> CyclicRotation(vector<int> &A, int K) 
{
	// write your code in C++14 (g++ 6.2.0)
	vector<int> shiftSpace;
	shiftSpace.reserve(A.size());

	size_t shiftIndex = 0;

	for (int i = 0; i < A.size(); ++i)
	{
		shiftSpace.emplace_back(-1);
	}

	for (int i = 0; i < A.size(); ++i)
	{
		shiftIndex = (K + i) % A.size();
		shiftSpace[shiftIndex] = A[i];
	}

	return shiftSpace;

}

/*
OddOccurrencesInArray
Find value that occurs in odd number of elements.
*/
int OddOccurrencesInArray(vector<int> &A)
{
	unordered_set<int> noOverlapSet;
	noOverlapSet.clear();
	unordered_set<int>::iterator iterPos;

	// write your code in C++14 (g++ 6.2.0)
	for (int i = 0; i < A.size(); ++i)
	{
		if (noOverlapSet.find(A[i]) == noOverlapSet.end())
			noOverlapSet.insert(A[i]);
		else
			noOverlapSet.erase(A[i]);
	}

	iterPos = noOverlapSet.begin();

	return *iterPos;

	//int result = 0;

	//for (int i = 0; i < A.size(); ++i)
	//{
	//	result ^= A[i];
	//}

	//return result;
}


void main()
{
	vector<int> test = { 9, 3, 9, 3, 9, 7, 9 };
	//solution(test, 3);
	//cout << oddNumber(test) << endl;
	//cout << solution(1041) << endl;
}