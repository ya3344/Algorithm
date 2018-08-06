#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;

/*
Lesson6: MaxproductOfThree
Maximize A[P] * A[Q] * A[R] for any triplet (P, Q, R).
*/

int MaxproductOfThree(vector<int> &A) {
	
	// write your code in C++14 (g++ 6.2.0)
	int product = 0;
	int maxProduct = numeric_limits<int>::min();

	size_t size = A.size();
	sort(A.begin(), A.end());

	maxProduct = A[size - 3] * A[size - 2] * A[size - 1];

	if (A[size - 3] < 0 || A[size - 2] < 0)
	{
		product = A[0] * A[1] * A[size - 1];
	}
	else if (A[0] < 0 && A[1] < 0)
	{
		product = A[0] * A[1] * A[size - 1];
	}

	if (maxProduct < product)
	{
		maxProduct = product;
	}

	return maxProduct;

}
/*
Lesson6: Triangle
*/

int Triangle(vector<int> &A) 
{
	long long sum = 0;
	size_t size = A.size();

	if (size < 3)
		return 0;

	sort(A.begin(), A.end());

	for (size_t i = 0; i < size-2; i++)
	{
		sum = ((long long)A[i] + (long long)A[i + 1]);
		if (sum <= A[i + 2])
			continue;

		sum = ((long long)A[i+1] + (long long)A[i + 2]);
		if (sum <= A[i])
			continue;

		sum = ((long long)A[i] + (long long)A[i + 2]);
		if (sum <= A[i + 1])
			continue;

		return 1;

	}

	return 0;	
}

/*
Lesson6: NumberOfDiscIntersections
Compute the number of intersections in a sequence of discs.
*/
int NumberOfDiscIntersections(vector<int> &A) 
{
	// write your code in C++14 (g++ 6.2.0)
	vector<long long> startPointSpace;
	vector<long long> endPointSpace;
	int count = 0;

	for (size_t i = 0; i < A.size(); ++i)
	{
		long long startPoint = i - (long long)A[i];
		long long endPoint = i + (long long)A[i];

		startPointSpace.emplace_back(startPoint);
		endPointSpace.emplace_back(endPoint);
	}

	sort(startPointSpace.begin(), startPointSpace.end());
	sort(endPointSpace.begin(), endPointSpace.end());

	for (size_t i = 0; i < A.size() - 1; ++i)
	{
		for (size_t j = i + 1; j < A.size(); ++j)
		{
			if (startPointSpace[j] <= endPointSpace[i])
			{
				++count;
			}
			else
				break;
		}
		if (count > 10000000)
			return -1;
	}

	return count;
}
/*
Lesson7: Fish
N voracious fish are moving along a river. Calculate how many fish are alive.
*/
int Fish(vector<int> &A, vector<int> &B) {

	stack<int> fishSpace;
	int count = 0;
	int answer = 0;

	for (size_t i = 0; i < B.size(); i++)
	{
		if (B[i] == 1)
		{
			fishSpace.push((A[i]));
		}
		else
		{
			while (!fishSpace.empty())
			{
				if (fishSpace.top() > A[i])
					break;
				else if (fishSpace.top() < A[i])
				{
					fishSpace.pop();
				}
			}
			if (B[i] == 0 && fishSpace.empty())
			{
				++count;
			}
		}

	}

	answer = fishSpace.size() + count;

	return answer;
}

/*
Lesson7: StoneWall
Cover "Manhattan skyline" using the minimum number of rectangles.
*/
int StoneWall(vector<int> &H) {

	vector<int> wallSpace;
	size_t size = H.size();
	size_t overlapCount = 0;
	wallSpace.emplace_back(H[0]);
	bool bClear = false;
	int answer = 0;
	int preOvelapWall = 0;

	for (size_t i = 0; i < size-1; i++)
	{
		bClear = false;
		for (int wall : wallSpace)
		{
			if (wall == H[i + 1])
			{
				preOvelapWall = wall;
				wallSpace.clear();
				bClear = true;
				++overlapCount;
				break;
			}
		}
		if (bClear == false)
		{
			if (preOvelapWall == H[i + 1])
			{
				++overlapCount;
			}
			else
			{
				wallSpace.emplace_back(H[i + 1]);
				preOvelapWall = -1;
			}
			
		}
	}

	answer = H.size() - overlapCount;

	return answer;
}

/*
Lesson8: EquiLeader
Find the index S such that the leaders of the sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N - 1] are the same.
*/
int EquiLeader(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	stack<int> leaderSpace;
	size_t size = A.size();
	if (size == 1)
		return 0;

	for (size_t i = 0; i < size; i++)
	{
		if (!leaderSpace.empty())
		{
			if (leaderSpace.top() != A[i])
			{
				leaderSpace.pop();
			}
			else
			{
				leaderSpace.push(A[i]);
			}
		}
		else
		{
			leaderSpace.push(A[i]);
		}
	}
	return leaderSpace.size();
}

void main()
{
	//if ((long long)(A[i] + A[i + 1]) > A[i + 2] &&
	//	(long long)(A[i + 1] + A[i + 2]) > A[i] &&
	//	(long long)(A[i] + A[i + 2]) > A[i + 1])
	//	return 1;
	//vector<int> test{2147483645, 2147483646 , 2147483647 };

	//cout << Triangle(test) << endl;

	//vector<int> test = { 1, 1, 1 }; // 1
	//vector<int> test = { 8, 8, 5, 7, 9, 8, 7, 4, 8 };
	vector<int> test = { 1, 2, 3, 3, 2, 1 }; // 3
	//cout << NumberOfDiscIntersections(test) << endl;
	cout << StoneWall(test) << endl;
}