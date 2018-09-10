#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <functional>
#include <map>
using namespace std;

/*
문제 1 DoubleSize
*/
long doubleSize(vector <long> a, long b)
{
	size_t size = a.size();
	long answer = b;

	sort(a.begin(), a.end());

	for (size_t i = 0; i < size; i++)
	{
		if (a[i] == answer)
		{
			answer *= 2;
		}
	}

	return answer;
}

/*
문제 2 Crossing the Street
*/
inline int Max(int a, int b)
{
	return a > b ? a : b;
}

inline int Min(int a, int b)
{
	return a < b ? a : b;
}

int widestGap(int n, vector<int> start, vector<int> end)
{
	size_t size = start.size();
	int answer = 0;
	int minPosition = 0;
	int maxPosition = 0;

	for (size_t i = 0; i < size-1; i++)
	{
		minPosition = Min(minPosition, start[i]);
		maxPosition = Max(maxPosition, end[i]);

		answer = Max(answer, (start[i + 1] - end[i]) - 1);
	}

	minPosition = Min(minPosition, start[size - 1]);
	maxPosition = Max(maxPosition, end[size - 1]);

	answer = Max(answer, minPosition - 1);
	answer = Max(answer, n - maxPosition);


	return answer;
}

/*
문제3. Psychometric Testing
*/
vector<int> jobOffers(vector<int> scores, vector<int> lowerLimits, vector<int> upperLimits)
{
	size_t scoreSize = scores.size();
	size_t limitsSize = lowerLimits.size();

	vector<int> candidateSpace;
	candidateSpace.reserve(limitsSize);
	
	size_t answer = 0;

	sort(scores.begin(), scores.end());

	for (size_t i = 0; i < limitsSize; i++)
	{
		size_t limitsNum =  upperLimits[i] - lowerLimits[i] + 1; // Score점수에 중복이없다면
		answer = 0;

		for (size_t j = 0; j < scoreSize; j++)
		{
			if (scores[j] >= lowerLimits[i] && scores[j] <= upperLimits[i])
			{
				++answer;
			}

			if (scores[j] > upperLimits[i] || answer > limitsNum)
				break;
		}

		candidateSpace.emplace_back(answer);
	}

	return candidateSpace;
}

int minimizeCost(vector<int> p, vector<int> x, vector<int> y)
{
	return 0;
}


void socialGraphs(vector<int> counts)
{
	size_t countsSize = counts.size();
	int id = 0;
	int rowMaxCount = -1;
	int rowCount = 0;
	int row = 0;

	multimap<int, int> validGrouping_Space;
	vector<vector<int>> validGrouping_FinalSpace;
	vector<int> rowSpace;

	for (size_t i = 0; i < countsSize; i++)
	{
		validGrouping_Space.emplace(counts[i], id);
		++id;
	}

	sort(counts.begin(), counts.end(), greater<>());

	multimap<int, int>::iterator iterFind;
	typedef pair<int, int> mapPair;

	validGrouping_FinalSpace.emplace_back(rowSpace);

	for (size_t i = 0; i < countsSize; i++)
	{
		if (rowMaxCount != counts[i])
		{
			rowMaxCount = counts[i];
		}
		
		if (rowCount >= rowMaxCount)
		{
			rowCount = 0;
			validGrouping_FinalSpace.emplace_back(rowSpace);
			++row;
		}
		++rowCount;

		iterFind = validGrouping_Space.find(counts[i]);
		mapPair pair = *iterFind;

		validGrouping_FinalSpace[row].emplace_back(pair.second);
		validGrouping_Space.erase(iterFind);
	}


	for (size_t i = 0; i < validGrouping_FinalSpace.size(); i++)
	{
		for (size_t j = 0; j < validGrouping_FinalSpace[i].size(); j++)
		{
			cout << validGrouping_FinalSpace[i][j] << " ";
		}

		cout << endl;
	}
}


void main()
{
	{ // Problem 1
		vector<long> a = { 1, 1, 4, 6, 8 };
		long b = 2;

		//cout << doubleSize(a, b) << endl;
	}

	{ // Problem 2
		int n = 10;
		vector<int> start = { 1, 2, 5, 8 };
		vector<int> finish = { 2, 2, 6, 10 };

		/*int n = 10;
		vector<int> start = { 3, 8 };
		vector<int> finish = { 4, 9 }; */

		//int n = 10;
		//vector<int> start = { 1, 2, 6, 6 };
		//vector<int> finish = { 4, 4, 10 ,8 }; 

		//cout << widestGap(n, start, finish) << endl;
	}

	{ // Problem 3
	/*	vector<int> scores = { 4, 8, 7 };
		vector<int> lowerLimits = { 2, 4 };
		vector<int> upperLimits = { 8, 4 };*/

		vector<int> scores = { 1, 3, 5, 6, 8 };
		vector<int> lowerLimits = { 2 };
		vector<int> upperLimits = { 6 };

		vector<int> answer = jobOffers(scores, lowerLimits, upperLimits);


		/*for (int i : answer)
		{
			cout << i << " ";
		}*/
	}

	{ // Problem 4

	}



	{ // Problme 5

		//vector<int> counts = { 3, 3, 3, 3, 3, 1, 3 };
		//vector<int> counts = { 2, 1, 1, 2, 1 };
		vector<int> counts = { 2, 1, 1, 2, 1 };
		socialGraphs(counts);
	}


}