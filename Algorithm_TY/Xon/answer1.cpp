#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// Answer1
// Double Size
long doubleSize(vector<long> a, long b)
{
	sort(a.begin(), a.end(), less<int>());

	for (long num : a)
	{
		if (b == num)
			b *= 2;
	}

	return b;
}


// Answer2
// Crossing the Street
int widestGap(int n, vector<int> start, vector<int> end)
{
	int len = 0;
	int maxLen = 0;

	int entireLen = n;
	int inputSize = start.size();
	int index = 0;
	for (int i = 1; i <= entireLen; )
	{
		if (index < inputSize && start[index] <= i && end[index] >= i)
		{
			++i;

			if (len > maxLen)
			{
				maxLen = len;
				len = 0;
			}
		}
		else if (index < inputSize && end[index] < i)
		{
			++index;
		}
		else
		{
			++i;
			++len;
		}
	}

	return maxLen;
}


// Answer3
// Psychometric Testing
vector<int> jobOffers(vector<int> scores, vector<int> lowerLimits, vector<int> upperLimits)
{
	sort(scores.begin(), scores.end(), less<int>());

	vector<int> output;
	size_t inputSize = lowerLimits.size();
	output.reserve(inputSize);

	for (size_t i = 0; i < inputSize; ++i)
	{
		int lower = lowerLimits[i];
		int upper = upperLimits[i];

		int passed = 0;
		for (int score : scores)
		{
			if (score >= lower && score <= upper)
				++passed;
			else if (score > upper)
				break;
		}
		output.emplace_back(passed);
	}

	return output;
}


//Answer4
int minimizeCost(vector<int> p, vector<int> x, vector<int> y)
{

	int beginX = *min_element(x.begin(), x.end());
	int beginY = *min_element(y.begin(), y.end());
	int endX = *max_element(x.begin(), x.end());
	int endY = *max_element(y.begin(), y.end());

	int minCost = 0;
	int inputSize = p.size();

	// 미니멈 값 초기 세팅
	for (int k = 0; k < inputSize; ++k)
	{
		minCost += p[k] * (abs(x[k] - beginX) + abs(y[k] - beginY));
	}


	for (int i = beginX + 1; i < endX; ++i)
	{
		for (int j = beginY + 1; j < endY; ++j)
		{
			int cost = 0;

			for (int k = 0; k < inputSize; ++k)
			{
				cost += p[k] * (abs(x[k] - i) + abs(y[k] - j));
			}

			if (minCost > cost)
				minCost = cost;
		}
	}

	return minCost;
}


//Answer5
void socialGraphs(vector<int> counts)
{
	unordered_map<int, vector<int>> output;

	int inputSize = counts.size();

	for (int i = 0; i < inputSize; ++i)
	{
		auto iterFind = output.find(counts[i]);

		if (iterFind != output.end())
		{
			output[counts[i]].emplace_back(i);
		}
		else
		{
			vector<int> tmp = { i };
			output.emplace(counts[i], tmp);
		}
	}

	for (auto pair : output)
	{
		int cnt = 0;
		for (int num : pair.second)
		{
			if (cnt == pair.first)
			{
				cout << endl;
				cnt = 0;
			}
			++cnt;
			cout << num;
		}
		cout << endl;
	}
}