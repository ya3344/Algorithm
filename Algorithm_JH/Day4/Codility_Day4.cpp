#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_set>
using namespace std;

inline int max(int a, int b)
{
	return a > b ? a : b;
}

inline int min(int a, int b)
{
	return a < b ? a : b;
}

int MaxSlice(vector<int>& test)
{
	int maxEnding = 0;
	int maxSlice = 0;

	for (int a : test)
	{
		maxEnding = max(0, maxEnding + a);
		maxSlice = max(maxSlice, maxEnding);
	}

	return maxSlice;

}
/*
Lesson9: MaxDoubleSliceSum
Find the maximal sum of any double slice
*/
int MaxDoubleSliceSum(vector<int> & A)
{
	int maxEnding = 0;
	int maxSlice = 0;

	vector<int> endSpace;
	vector<int> strtSpace;

	int endCount = 0;

	for (size_t i = 0; i< A.size()-1; ++i)
	{
		maxEnding = max(0, maxEnding + A[i+1]);

		if (maxSlice < maxEnding)
		{
			maxSlice = maxEnding;
			strtSpace.emplace_back(i + 1);
		}
		else if (maxSlice > maxEnding)
		{
			endSpace.emplace_back(i+1);
		}
	}

	sort(strtSpace.begin(), strtSpace.end());

	return maxSlice;
}

/*
Lesson10: CountFactors
Count factors of given number n.
*/

int CountFactors(int N)
{
	size_t factorNum = 0;
	float fraction = 0.f;
	float integer = 0.f;

//	fraction = modf(sqrtf(N), &integer);

	for (int i = 1; i <= sqrt(N); i++)
	{
		if ((N % i) == 0)
		{
			++factorNum;
		}
	}

	factorNum *= 2;

	if (fraction <= 0.f)
	{
		factorNum -= 1;
	}

	return factorNum;
}

/*
Lesson11: CountNonDivisible
Calculate the number of elements of an array that are not divisors of each element.
*/
vector<int> CountNonDivisible(vector<int> &A)
{
	int divNum = 0;
	int answer = 0;
	vector<int> answerSpace;
	vector<int> minDivSpace = A;
	vector<int> divNumSpace;
	int size = A.size();

	sort(minDivSpace.begin(), minDivSpace.end());


	/*for (size_t i = 0; i < minDivSpace.size(); i++)
	{
		divNumSpace.emplace_back
	}
*/
	for (int i = 0; i < size; i++)
	{
		divNum = 0;
		for (int j = 0; j < size; j++)
		{
			if (A[i] < minDivSpace[j])
				break;

			if (A[i] % minDivSpace[j] == 0)
			{
				++divNum;
			}
		}
		answer = size - divNum;
		answerSpace.emplace_back(answer);
	}
	
	return answerSpace;

}


/*
Lesson11: CountSemiprimes
Count the semiprime numbers in the given range [a..b]
*/

vector<int> CountSemiprimes(int N, vector<int> &P, vector<int> &Q)
{
	vector<int> answerSpace;
	vector<int> primeSpaceOne;
	vector<vector<int>> primeSpace;
	int semiPrime_Count = 0;

	const size_t PSize = P.size();
	const size_t QSize = Q.size();

	bool bPrime[30001] = {};

	for (size_t i = 0; i < QSize; i++)
	{
		primeSpace.emplace_back(primeSpaceOne);
	}

	for (size_t i = 0; i < QSize; i++)
	{
		for (int j = P[i]; j <= Q[i]; j++)
		{
			if (j == 1)
				continue;
			
			if (bPrime[j] == false)
			{
				if (j * 2 <= Q[i])
				{
					primeSpace[i].emplace_back(j);
				}
			}

			for (int k = j+j; k <= Q[i]; k+=j)
			{
				bPrime[k] = true;
			}
		}
	}

	unordered_set<int> semiPrime_Space;

	for (size_t i = 0; i < primeSpace.size(); i++)
	{
		semiPrime_Count = 0;
		for (size_t j = 0; j < primeSpace[i].size(); j++)
		{
		
		}
	}


	return answerSpace;

}

void main()
{
	//vector<int> test = { 3, 2, 6, -1, 4, 5, -1, 2};
	//vector<int> test = { -1, -3, -5, 4, 7, 9, 5 };
	//cout << MaxDoubleSliceSum(test) << endl;

	//cout << CountFactors(16) << endl;
	//vector<int> P = { 1, 4, 16 };
	//vector<int> Q = { 26, 10, 20 };
	//CountSemiprimes(26, P, Q);

	vector<int> A = { 3, 1, 2, 3, 6 };
	vector<int> answer = CountNonDivisible(A);


	for (int i : answer)
	{
		cout << i << " ";
	}

}