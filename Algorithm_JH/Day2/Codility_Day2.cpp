// you can use includes, for example:
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
FrogJmp
Count minimal number of jumps from position X to Y.
*/
int FrogJmp(int X, int Y, int D) 
{
	int distance = 0;
	int jumpCount = 0;
	
	if (Y == X)
	{
		jumpCount = 0;
	}
	else if (Y > X)
	{
		distance = Y - X;
		jumpCount = distance / D;

		if (distance % D > 0)
		{
			jumpCount += 1;  // ceil function 
		}
	}

	return jumpCount;
}

/*
PermMissingElem
Find the missing element in a given permutation.
*/
int PermMissingElem(vector<int> &A) 
{
	int sum = 0;
	int totalSum = 0;
	int missingNum = 0;

	totalSum = A.size() + A.size() + 1;

	for (size_t i = 0; i < A.size(); i++)
	{
		sum += A[i];
		totalSum += i;
	}

	missingNum = totalSum - sum;

	return missingNum;
	
}

/*
FrogRiverOne
Find the earliest time when a frog can jump to the other side of a river.
*/

//int FrogRiverOne(int X, vector<int> &A) 
//{
//	unordered_set<size_t> leapSpace;
//	size_t time = 0;
//	size_t totalDistance = 0;
//	size_t preDistance = 0;
//	
//	unordered_set<size_t>::iterator iterPos = leapSpace.begin();
//
//	for (int i = 0; i <= X; i++)
//	{
//		totalDistance += i;
//	}
//
//	for (time = 0; time < A.size(); time++)
//	{
//		leapSpace.emplace(A[time]);
//
//		iterPos = leapSpace.end();
//		--iterPos;
//
//		if (preDistance != *(iterPos))
//		{
//			totalDistance -= *(iterPos);
//		}
//
//		preDistance = *(iterPos);
//		if (totalDistance == 0)
//		{
//			return time;
//		}
//	}
//
//	return -1;
//	
//}

int FrogRiverOne(int X, vector<int> &A)
{
	unordered_set<int> leapSpace;

	for (size_t time = 0; time < (int)A.size(); time++)
	{
		leapSpace.emplace(A[time]);

		if (X == leapSpace.size())
		{
			return time;
		}
	}

	return -1;
}


/*
MaxCounters
Calculate the values of counters after applying all alternating operations: 
increase counter by 1; set value of all counters to current maximum.
*/

vector<int> MaxCounters(int N, vector<int> &A)
{
	vector<int> maxCounterSpace;
	maxCounterSpace.reserve((size_t)N);

	int maxTempNum = 0;
	int maxNum = 0;
	bool bMax = false;

	for (size_t i = 0; i < (size_t)N; i++)
	{
		maxCounterSpace.emplace_back(0);
	}

	for (size_t i = 0; i < A.size(); i++)
	{
		if (A[i] == N + 1)
		{
			bMax = true;
			maxNum = maxTempNum;
		}
		else
		{
			if (bMax == false)
			{
				maxCounterSpace[A[i] - 1] = maxCounterSpace[A[i] - 1] + 1;
			}
			else
			{
				if (maxCounterSpace[A[i] - 1] <= maxNum)
				{
					maxCounterSpace[A[i] - 1] = maxNum + 1;
				}
				else
				{
					maxCounterSpace[A[i] - 1] = maxCounterSpace[A[i] - 1] + 1;
				}
			}
			
			if (maxCounterSpace[A[i] - 1] > maxTempNum)
			{
				maxTempNum = maxCounterSpace[A[i] - 1];
			}
		}
	}

	for (size_t i = 0; i < maxCounterSpace.size(); i++)
	{
		if (maxCounterSpace[i] < maxNum)
		{
			maxCounterSpace[i] = maxNum;
		}
	}

	return maxCounterSpace;
}


/*
GenomicRangeQuery
Find the minimal nucleotide from a range of sequence DNA.
*/

vector<int> GenomicRangeQuery(string &S, vector<int> &P, vector<int> &Q)
{
	enum letter { DNA_A = 0, DNA_C, DNA_G, DNA_T, DNA_END};

	int impactFactors = 0;

	// impactFactor P, Q
	vector<int> impactFactor_space;
	size_t imapctFactorSize = P.size();
	impactFactor_space.reserve(imapctFactorSize);

	// letterCount S
	vector<vector<int>> DNA_Space;
	DNA_Space.reserve(DNA_END); // A, C, G, T -> 0, 1 ,2, 3

	size_t stringSize = S.size();
	vector<int> characterCount_space;
	characterCount_space.reserve(stringSize);

	int count[DNA_END] = {};

	for (size_t i = 0; i < DNA_END; i++)
	{
		DNA_Space.emplace_back(characterCount_space);
	}

	for (size_t N = 0; N < stringSize; ++N)
	{
		switch (S[N])
		{
		case 'A':
			++count[DNA_A];
			
			break;
		case 'C':
			++count[DNA_C];
			
			break;
		case 'G':
			++count[DNA_G];
			
			break;
		case 'T':
			++count[DNA_T];
			
			break;
		default:
			break;
		}

		DNA_Space[DNA_A].emplace_back(count[DNA_A]);
		DNA_Space[DNA_C].emplace_back(count[DNA_C]);
		DNA_Space[DNA_G].emplace_back(count[DNA_G]);
		DNA_Space[DNA_T].emplace_back(count[DNA_T]);
	}


	for (size_t i = 0; i < imapctFactorSize; i++)
	{
		if (P[i] == Q[i])
		{
			switch (S[P[i]])
			{
			case 'A':
				impactFactors = 1;
				break;
			case 'C':
				impactFactors = 2;
				break;
			case 'G':
				impactFactors = 3;
				break;
			case 'T':
				impactFactors = 4;
				break;
			}
		}
		else if(P[i] < Q[i])
		{
			if (DNA_Space[DNA_A][Q[i]] - DNA_Space[DNA_A][P[i]] > 0 || S[P[i]] == 'A')
			{
				impactFactors = 1;
			}
			else if (DNA_Space[DNA_C][Q[i]] - DNA_Space[DNA_C][P[i]] > 0 || S[P[i]] == 'C')
			{
				impactFactors = 2;

			}
			else if (DNA_Space[DNA_G][Q[i]] - DNA_Space[DNA_G][P[i]] > 0 || S[P[i]] == 'G')
			{
				impactFactors = 3;
			}
			else if (DNA_Space[DNA_T][Q[i]] - DNA_Space[DNA_T][P[i]] > 0 || S[P[i]] == 'T')
			{
				impactFactors = 4;
			}
		}

		impactFactor_space.emplace_back(impactFactors);
	}

	return impactFactor_space;
}

void main()
{
	//vector<int> A = { 1, 3, 1, 4, 2, 3, 5, 4 };
	/*vector<int> A = { 1, 3, 4, 2};
	cout << FrogRiverOne(5, A) << endl;*/
	/*vector<int> answer;
	vector<int> A = { 3, 4, 4, 6, 1, 4, 4 };
	answer = MaxCounters(5, A);

	for (int i : answer)
	{
		cout << i << " ";
	}*/

	string S = "TC";
	vector<int> P = { 0, 0, 1 };
	vector<int> Q = { 0, 1, 1 };
	GenomicRangeQuery(S, P, Q);

	for (size_t i : GenomicRangeQuery(S, P, Q))
	{
		cout << i << " ";
	}

}